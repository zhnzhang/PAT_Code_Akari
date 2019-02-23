//素数的判断
bool isPrime(int n) {
    if(n <= 1) return false;    //特判
    int sqr = (int)sqrt(1.0 * n);   //根号n
    for(int i = 2; i <= sqr; i++) {     //遍历2～根号n
        if(n % i == 0) return false;    //n是i的倍数，则n不是素数
    }
    return true;    //n是素数
}
//由于sqrt的参数要求是浮点数，因此在n前面乘以1.0来使其成为浮点型

//如果n没有接近int型变量的范围上界，那么有更简单的写法：
bool isPrime(int n) {
    if(n <= 1) return false;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}
//这样写会当n接近int型变量的范围上界时导致i * i溢出(当然n在10^9以内都会是安全的)
//解决的办法是将i定义为long long型，这样就不会溢出了
//初学者还是推荐使用开根号的写法，因为这样写可以更安全


//素数表的获取

//枚举法，总复杂度是O(n√n),这个复杂度对n不超过10^5的大小是没问题的
const int maxn = 101;   //表长
int prime[maxn], pNum = 0;  //prime数组存放所有素数，pNum为素数个数
bool p[maxn] = {0};     //p[i] == true表示i是素数
void Find_Prime() {
    for(int i = 1; i < maxn; i++) {     //不能写成i <= maxn
        if(isPrime(i) == true) {
            prime[pNum++] = i;      //是素数则把i存入prime数组
            p[i] = true;
        }
    }
}

//完整的求解100以内的所有素数的程序：
#include <cstdio>
#include <cmath>
bool isPrime(int n) {       //判断n是否为素数
    if(n <= 1) return false;
    int sqr = (int)sqrt(1.0 * n);
    for(int i = 2; i <= sqr; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int prime[101], pNum = 0;
bool p[101] = {0};
void Find_Prime() {     //求素数表
    for(int i = 1; i < 101; i++) {
        if(isPrime(i) == true) {
            prime[pNum++] = i;
            p[i] = true;
        }
    }
}

int main() {
    Find_Prime();       //在日常使用时很容易忘记写这个，记住要先求出素数表，因此结果不对的时候要检查是否漏写
    for(int i = 0; i < pNum; i++) {
        printf("%d", prime[i]);
        if(i < pNum - 1) printf(" ");
    }
    return 0;
}

//若需要更大范围的素数表，需要使用更高效的算法，它的时间复杂度为O(nloglogn)，名为埃氏筛法
//这是众多筛法中最简单且容易理解的一种，即Eratosthenes筛法。(欧拉筛法更优，可以达到O(n)的时间复杂度)
//算法从小到大枚举所有数，对每一个素数，筛去它的所有倍数，剩下的就都是素数了
//在这个过程中，起手看2，2是素数，也是这个过程中唯一需要事先确定的
//当从小到大到达某数a时，如果a没有被前面步骤的数筛去，那么a一定是素数
//这是因为如果a不是素数，那么a一定有小于a的素因子啊(素因子是能整除给定正整数的质数，即a的因数是素数)，这样在之前的步骤中a一定会被筛掉
//故当枚举到a时还没有被筛掉，那么a一定是素数
//筛这个动作的实现，可以使用一个bool型数组p来标记，如果a被筛掉，p[a]为true；否则，p[a]为false。在程序开始时可以初始化p数组全为false

const int maxn = 101;   //表长
int prime[maxn], pNum = 0;  //prime数组存放所有素数，pNum为素数个数
bool p[maxn] = {0};     //如果i为素数，则p[i]为false；否则，p[i]为true
void Find_Prime() {
    for(int i = 2; i < maxn; i++) {     //从2开始，i < maxn结束，注意不能写成i <= maxn
        if(p[i] == false) {     //如果i是素数
            prime[pNum++] = i;      //把素数i存档prime数组中
            for(int j = i + i; j < maxn; j += i) {
                //筛去所有i的倍数，循环条件不能写成j <= maxn
                p[j] = true
            }
        }
    }
}

//完整的求解100以内的所有素数的程序：
#include <cstdio>
const int maxn = 101;   //表长
int prime[maxn], pNum = 0;  //prime数组存放所有素数，pNum为素数个数
bool p[maxn] = {0};     //如果i为素数，则p[i]为false；否则，p[i]为true
void Find_Prime() {
    for(int i = 2; i < maxn; i++) {     //从2开始，i < maxn结束，注意不能写成i <= maxn
        if(p[i] == false) {     //如果i是素数
            prime[pNum++] = i;      //把素数i存档prime数组中
            for(int j = i + i; j < maxn; j += i) {
                //筛去所有i的倍数，循环条件不能写成j <= maxn
                p[j] = true
            }
        }
    }
}

int main() {
    Find_Prime();       //要记得写上这句
    for(int i = 0; i < pNum; i++) {
        printf("%d", prime[i]);
        if(i < pNum - 1) printf(" ");
    }
    return 0;
}
