//example
//可以在1～n的范围内枚举奇数p，如果p和p + 2都是素数，那么令计数器count加1

#include <cstdio>
#include <cmath>
bool isPrime(int n) {   //判断n是否为素数
    if(n <= 1) return false;
    int sqr = (int)sqrt(1.0 * n);
    for(int i = 2; i <= sqr; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    int n, count = 0;
    scanf("%d", &n);
    for(int i = 3; i + 2 <= n; i += 2) {    //i每次加2
        if(isPrime(i) == true && isPrime(i + 2) == true) {
            count++;        //如果i和i + 2都是素数，那么count加1
        }
    }
    printf("%d\n", count);
    return 0;
}
