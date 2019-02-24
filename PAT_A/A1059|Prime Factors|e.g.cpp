//example
//先打素数表
//考虑到2 * 3 * 5 * 7 * 11 * 13 * 17 * 19 * 23 * 29就已经超过int范围了，因此对一个int型范围的数来说，fac数组的大小只需要开到10就可以了
//对一个正整数n来说，如果它存在[2, n]范围内的质因子，要么这些质因子全部小于等于sqrt(n)，要么只存在一个大于sqrt(n)的质因子，而其余质因子全部小于等于sqrt(n)
//题目说的是int范围内的正整数进行质因子分解，因此素数表大概开10^5大小就可以
//注意n == 1需要特判输出 "1=1"，否则不会输出1的结果
//初学者学习素数和质因子分解容易犯错的地方：一是在main函数开头忘记调用Find_Prime()函数；二是Find_Prime()函数中把i < maxn误写成i <= maxn
//三是没有处理大于sqrt(n)部分的质因子；四是在枚举质因子的过程中发生了死循环(死因各异)；
//五是没有在循环外定义变量来存储sqrt(n)，而在循环条件中直接计算sqrt(n)，这样当循环中使用n本身进行操作的话会导致答案错误

//质因子分解的范例代码

#include <cstdio>
#include <cmath>
const int maxn = 100010;
bool is_prime(int n) {      //判断n是否为素数
    if(n <= 1) return false;
    int sqr = (int)sqrt(1.0 * n);
    for(int i = 2; i <= sqr; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int prime[maxn], pNum = 0;
void Find_Prime() {     //求素数表
    for(int i = 1; i < maxn; i++) {
        if(is_prime(i) == true) {
            prime[pNum++] = i;
        }
    }
}

struct factor {
    int x, cnt; //x为质因子，cnt为其个数
} fac[10];

int main() {
    Find_Prime();       //此句请务必要记得写
    int n, num = 0;     //num为n的不同质因子的个数
    scanf("%d", &n);
    if(n == 1) printf("1=1");   //特判1的情况
    else {
        printf("%d=", n);
        int sqr = (int)sqrt(1.0 * n);   //n的根号
        //枚举根号n以内的质因子
        for(int i = 0; i < pNum && prime[i] <= sqr; i++) {
            if(n % prime[i] == 0) {     //如果prime[i]是n的因子
                fac[num].x = prime[i];  //记录该因子
                fac[num].cnt = 0;
                while(n % prime[i] == 0) {  //计算出质因子prime[i]的个数
                    fac[num].cnt++;
                    n /= prime[i];
                }
                num++;      //不同质因子个数加1
            }
            if(n == 1) break;       //及时退出循环，节省点时间
        }
        if(n != 1) {        //如果无法被根号n以内的质因子除尽
            fac[num].x = n;     //那么一定有一个大于根号n的质因子，据语句，大概就是指这个无法被除尽后n剩下的值把
            fac[num++].cnt = 1;
        }
        //按格式输出结果
        for(int i = 0; i < num; i++) {
            if(i > 0) printf("*");
            printf("%d", fac[i].x);
            if(fac[i].cnt > 1) {
                printf("^%d", fac[i].cnt);
            }
        }
    }
    return 0;
}
