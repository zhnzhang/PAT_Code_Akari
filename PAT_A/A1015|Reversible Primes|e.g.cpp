//example
//1不是素数，注意边界数据，当n等于1时，需要输出"No"
#include <cstdio>
#include <cmath>
bool isPrime(int n) {   //判断是否为素数
    if(n <= 1) return false;
    int sqr = (int)sqrt(1.0 * n);
    for(int i = 2; i <= sqr; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int d[111];
int main() {
    int n, redix;
    while(scanf("%d", &n) != EOF) {
        if(n < 0) break;        //当n是负数时，退出循环
        scanf("%d", &redix);
        if(isPrime(n) == false) {
            printf("No\n");
        } else {        //n是素数，判断n在radix进制下的逆序的十进制是否是素数
            int len = 0;
            do {        //进制转换
                d[len++] = n % redix;
                n /= redix;
            } while(n != 0);
            for(int i = 0; i < len; i++) {      //按逆序转换进制
                n = n * redix + d[i];
            }
            if(isPrime(n) == true) printf("Yes\n");     //逆序是素数
            else printf("No\n");    //逆序不是素数
        }
    }
    return 0;
}
