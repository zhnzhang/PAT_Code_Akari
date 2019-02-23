//example
//用筛法或者非筛法都行，只需要在算法中添加一句控制素数个数的语句：
//if(num >= n) break;
//筛法代码其实比暴力代码要短。不过无论是筛法还是非筛法求解，下面这几个问题都需要注意，其中第一点容易造成边界数据：
//第一点，1不是素数
//第二点，素数表长至少要比n大1。我觉得是因为数组的号是从0开始的，这里需要判断n是否是素数
//在Find_Prime()函数中要特别留意i < maxn不能写成i <= maxn。这个一定要注意，虽然我不知道确切的原因，可能跟相应bool数组有点关系
//main函数中要记得调用Find_Prime()，不然不会出结果

#include <cstdio>
const int maxn = 1000001;
int prime[maxn], num = 0;
bool p[maxn] = {0};         //筛法
void Find_Prime(int n) {
    for(int i = 2; i < maxn; i++) {
        if(p[i] == false) {
            prime[num++] = i;
            if(num >= n) break;     //只需要n个素数，因此超过时即可结束
            for(int j = i + i; j < maxn; j += i) {
                p[j] = true;
            }
        }
    }
}

int main() {
    int m, n, count = 0;
    scanf("%d%d", &m, &n);
    Find_Prime(n);
    for(int i = m; i <= n; i++) {       //输出第m个素数至第n个素数
        printf("%d", prime[i - 1]);     //下标从0开始
        count++;
        if(count % 10 != 0 && i < n) printf(" ");
        else printf("\n");
    }
    return 0;
}
