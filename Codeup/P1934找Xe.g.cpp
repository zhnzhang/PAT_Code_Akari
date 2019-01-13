//Example
#include <cstdio>
const int maxn = 210;
int a[maxn];        //存放n个数

int main() {
    int n, x;
    while(scanf("%d", &n) != EOF) {
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);     //输入n个数
        }
        scanf("%d", &x);;       //输入欲查询的数
        int k;                  //下标
        for(k = 0; k < n; k++) {    //遍历数组
            if(a[k] == x) {         //如果找到了x
                printf("%d\n", k)   //输出对应的下标
                break;              //退出查找
            }
        }
        if(k == n) {/               //如果没有找到
            printf("-1\n");         //输出-1
        }
    }
    return 0;
}
