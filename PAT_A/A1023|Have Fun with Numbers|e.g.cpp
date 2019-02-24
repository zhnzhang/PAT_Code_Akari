//example
//开一个count数组，用来存放0～9中每个数字的出现次数。
//然后枚举两个整数的所有数位，对原整数中出现的数字，令对应的count值加1；对新整数中出现的数字，令对应的count值减1
//如果在枚举完所有数位后，所有count数组元素的值均为0，说明新整数的数位是原整数数位的一个排列
//若原整数和新整数的长度不相同，则一定输出"No"
#include <cstdio>
#include <cstring>
struct bign {
    int d[21];
    int len;
    bign() {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

bign change(char str[]) {       //将整数转换为bign
    bign a;
    a.len = strlen(str);
    for(int i = 0; i < a.len; i++) {
        a.d[i] = str[a.len - 1 - i] - '0';
    }
    return a;
}

bign multi(bign a, int b) {     //高精度低精度乘法
    bign c;
    int carry = 0;      //进位
    for(int i = 0; i < a.len; i++) {
        int temp = a.d[i] * b + carry;
        c.d[c.len++] = temp % 10;       //个位作为该位结果
        carry = temp / 10;      //高位部分作为新的进位
    }
    while (carry != 0) {        //和加法不一样，乘法的进位可能不止1位，因此用while
        c.d[c.len++] = carry % 10;
        carry /= 10;
    }
    return c;
}

bool Judge(bign a, bign b) {            //判断b的所有位是否是a的某个排列
    if(a.len != b.len) return false;        //若长度不同，则肯定是false
    int count[10] = {0};        //计数0～9的出现次数
    for(int i = 0; i < a.len; i++) {
        count[a.d[i]]++;        //数位a.d[i]对应的count值加1
        count[b.d[i]]--;        //数位b.d[i]对应的count值减1
    }
    for(int i = 0; i < 10; i++) {       //判断0～9的出现次数是否都为0
        if(count[i] != 0) {     //只要有一个数字的出现次数不为0，则返回false
            return false;
        }
    }
    return true;
}

void print(bign a) {        //输出bign
    for(int i = a.len - 1; i >= 0; i--) {
        printf("%d", a.d[i]);
    }
}

int main() {
    char str[21];
    scanf("%s", str);       //输入数据
    bign a = change(str);       //转换为bign
    bign mul = multi(a, 2);     //计算a * 2
    if(Judge(a, mul) == true) printf("Yes\n");
    else printf("No\n");
    print(mul);     //输出结果
    return 0;
}
