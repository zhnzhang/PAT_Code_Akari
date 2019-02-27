//example
//本题只需完成两点：（1）求一个正整数的数位和；（2）对一堆正整数（即刚刚的数位和）进行去重并从小到大排序

#include <cstdio>
#include <set>
using namespace std;
set<int> st;            //存放朋友证号的set

int getSum(int x) {
    int sum = 0;            //数位和
    while (x) {             //因为x是正整数，所以不需要用do...while
        sum += x % 10;      //累加x的个位
        x /= 10;        //去掉x的个位
    }
    return sum;             //返回数位和
}

int main() {
    int n, x;
    scanf("%d", &n);        //个数
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);             //输入给定的正整数
        st.insert(getSum(x));       //计算x的数位和，并将这个和插入到set中
    }
    printf("%d\n", st.size());      //输出set中的元素个数即为朋友证号的个数
    for(set<int>::iterator it = st.begin(); it != st.end(); it++) {     //遍历set
        if(it != st.begin()) {  //要掌握这种针对STL容器输出的空格格式控制方法
            printf(" ");        //不在第一个数前输出空格
        }
        printf("%d", *it);  //从小到大输出朋友证号
    }
    return 0;
}
