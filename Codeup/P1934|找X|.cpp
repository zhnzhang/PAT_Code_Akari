#include <cstdio>

int main() {
    int n, a[210] = {0};
    int find;                           //要找的
    bool flag;                          //用于判断是否找到
    while (scanf("%d", &n) != EOF) {    //这样写用于多点测试，一次运行测多组实验数据
        flag = false;
        for (int i = 0; i < n; i++) {
            scanf("%d", a + i);
        }
        scanf("%d", &find);
        for (int i = 0; i < n; i++) {
            if (a[i] == find) {
                printf("%d\n", i);
                flag = true;
                break;
            }
        }
        if (flag == false) {
            printf("-1\n");
        }
    }
    return 0;
}




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
