//example
//如何判断一个串是回文串：如果串的下标范围是0～(len - 1)，那么对位置i来说，其对称位置就是len - 1 - i(因为对称的两个位置下标之和为len - 1)
//因此可以遍历下标0～len / 2，判断其是否与其对称位置的数位相同，而只要有一个位置不对称，这个串就不是回文串
//在土木给定的操作次数上限内进行重复操作，每次将当前数倒置得到一个新数，再将原数与新数使用大整数加法相加，赋回给原数，直到产生一个回文数或者达到操作次数上限时停止
//当出现给定字符串已经是回文串时，不需要对其进行操作，输出原数与0
//N在执行操作100次后，已经远超过long long的表示范围，必须用大整数运算

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct bign {
    int d[1000];
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

bign add(bign a, bign b) {  //高精度加法
    bign c;
    int carry = 0;  //carry是进位
    for(int i = 0; i < a.len || i < b.len; i++) {
        int temp = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    if(carry != 0) {
        c.d[c.len++] = carry;
    }
    return c;
}

bool Judge(bign a) {        //判断是否回文
    for(int i = 0; i <= a.len / 2; i++) {
        if(a.d[i] != a.d[a.len - 1 - i]) {
            return false;   //若对称位置不等，则一定不回文
        }
    }
    return true;    //回文
}

void print(bign a) {    //输出bign
    for(int i = a.len - 1; i >= 0; i--) {
        printf("%d", a.d[i]);
    }
    printf("\n");
}

int main() {
    char str[1000];
    int T, k = 0;       //T是操作次数上限；k是当前操作次数，初始化为0
    scanf("%s %d", str, &T);        //初始数字、操作次数上限
    bign a = change(str);       //将字符串转换为bign
    while(k < T && Judge(a) == false) {     //不超过操作次数上限且a非回文
        bign b = a;
        reverse(b.d, b.d + b.len);  //将b倒置
        a = add(a, b);      //使用大整数加法,a = a + b
        k++;    //操作次数加1
    }
    print(a);
    printf("%d\n", k);
    return 0;
}
