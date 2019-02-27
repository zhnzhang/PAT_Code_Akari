//example
//两个集合的相同元素率，即两个集合的交集和并集(均需去重)的元素个数的比率
//两集合都有的元素个数-交集；两集合所有不同的元素个数-并集
//对每一个查询，设置两个int型变量totalNum与sameNum(初始值分别为集合y中的元素个数与0)，分别表示不同元素的个数(即并集)以及相同元素的个数(即交集)
//然后枚举集合x中的元素，判断其是否在集合y中出现，如果出现，说明找到一个相同元素，令sameNum加1；如果未出现，说明找到一个新的不同元素，令totalNum加1
//要考虑到同一个集合中也会有相同的元素，所以需要用set进行过滤
//二次方级别的算法会有一组数据超时，最好使用排序或set的做法

#include <cstdio>
#include <set>
using namespace std;
const int N = 51;
set<int> st[N];         //N个集合

void compare(int x, int y) {        //比较集合st[x]与集合st[y]
    int totalNum = st[y].size(), sameNum = 0;       //不同数的个数、相同数的个数
    //遍历集合st[x]
    for(set<int>::iterator it = st[x].begin(); it != st[x].end(); it++) {
        if(st[y].find(*it) != st[y].end())      //在st[y]中能找到该元素(这的判断条件我不太懂，为什么要和st[y].end()比，才能知道在set里有没有该元素？)
            sameNum++;
        else
            totalNum++;     //在st[y]中不能找到该元素
    }
    printf("%.1f%%\n", sameNum * 100.0 / totalNum);     //输出比率，注意%的输出在这里的写法，得用%%
}

int main() {
    int n, k, q, v, st1, st2;
    scanf("%d", &n);                //集合个数
    for(int i = 1; i <= n; i++) {
        scanf("%d", &k);            //集合i中的元素个数
        for(int j = 0; j < k; j++) {
            scanf("%d", &v);        //集合i中的元素v
            st[i].insert(v);        //将元素v加入集合st[i]中
        }
    }
    scanf("%d", &q);        //q个查询
    for(int i = 0; i < q; i++) {
        scanf("%d%d", &st1, &st2);  //欲对比的集合编号
        compare(st1, st2);      //比较两个集合
    }
    return 0;
}
