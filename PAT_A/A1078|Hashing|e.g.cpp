//example
//令step为步长，冲突处理公式是M = (a + step * step) % TSize
//1不是质数
//可证如果step从0～TSize - 1进行枚举却仍然无法找到位置，那么对step大于等于TSize来说也不可能找到位置，即证明循环节为TSize

#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int N = 11111;

bool isPrime(int n) {   //判断n是否为素数
    if(n <= 1) return false;
    int sqr = (int)sqrt(1.0 * n);
    for(int i = 2; i <= sqr; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

bool hashTable[N] = {0};        //hashTable[x] == false则代表x号位未被使用

int main() {
    int n, TSize, a;
    scanf("%d%d", &TSize, &n);
    while(isPrime(TSize) == false) {        //寻找第一个大于等于TSize的质数
        TSize++;
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &a);
        int M = a % TSize;
        if(hashTable[M] == false) {     //如果M号位未被使用，则已找到
            hashTable[M] = true;
            if(i == 0) printf("%d", M);
            else printf(" %d", M);
        } else {
            int step;       //二次方探查法步长
            for(step = 1; step < TSize; step++) {   //可以证明TSize为循环节
                M = (a + step * step) % TSize;      //下一个检测地址
                if(hashTable[M] == false) {         //如果M号位未被使用，则已找到
                    hashTable[M] = true;
                    if(i == 0) printf("%d", M);
                    else printf(" %d", M);
                    break;      //记住要break
                }
            }
            if(step >= TSize) { //找不到插入的地方
                if(i > 0) printf(" ");
                printf("-");
            }
        }
    }
    return 0;
}
