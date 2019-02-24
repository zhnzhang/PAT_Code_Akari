//example
//注意除法之后商的高位0必须除去，并且不能有不输出数字的情况
#include <cstdio>
#include <cstring>
struct bign {
    int d[1010];
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

bign divide(bign a, int b, int &r) {        //高精度除法，r为余数(使用了"引用&")
    bign c;
    c.len = a.len;      //被除数的每一位和商的每一位是一一对应的，因此先令长度相等
    for(int i = a.len - 1; i >= 0; i--) {       //从高位开始
        r = r * 10 + a.d[i];        //和上一位遗留的余数组合
        if(r < b) c.d[i] = 0;   //不够除，该位为0
        else {      //够除
            c.d[i] = r / b;     //商
            r %= b;     //获得新的余数
        }
    }
    while (c.len - 1 >= 1 && c.d[c.len - 1] == 0) {
        c.len--;        //去除高位的0，同时至少保留一位最低位
    }
    return c;
}

void print(bign a) {        //输出bign
    for(int i = a.len - 1; i >= 0; i--) {
        printf("%d", a.d[i]);
    }
}

int main() {
    char str[1010];
    int b, r = 0;   //余数初始化为0
    scanf("%s%d", str, &b);
    bign a = change(str);       //将a转换为bign型
    print(divide(a, b, r));     //r以初值0传入
    printf(" %d", r);
    return 0;
}
