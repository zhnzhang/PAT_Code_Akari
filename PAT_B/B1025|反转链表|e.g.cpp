//example
//本题地址比较简单或者说短小，可以使用静态链表来做
//枚举每个完整的块，对每一个块，从后往前输出结点信息，唯一需要注意的就是每一个快的最后一个(从后往前)结点的next的处理，具体见习题集P266
//对无效结点，要去掉，最后不予输出
//反转链表只改变结点的next地址，而不会改变本身的地址，因此address和data可以视为绑定的。
//%05d的输出格式会使-1的输出出现问题，因此一定要将-1的输出跟其他地址的输出分开来考虑
//这5个步骤就是静态链表处理问题的一般步骤

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct Node {           //定义静态链表(步骤1)
    int address, data, next;
    int order;      //结点在链表上的序号，无效结点记为maxn
} node[maxn];

bool cmp(Node a, Node b) {
    return a.order < b.order;       //按order从小到大排序
}

int main() {
    for(int i = 0; i < maxn; i++) {     //初始化(步骤2)
        node[i].order = maxn;       //初始化全部为无效结点
    }
    int begin, n, K, address;
    scanf("%d%d%d", &begin, &n, &K);        //起始地址、结点个数、步长
    for(int i = 0; i < n; i++) {        //这个for循环注意一下，这三句的写法
        scanf("%d", &address);
        scanf("%d%d", &node[address].data, &node[address].next);
        node[address].address = address;
    }
    int p = begin, count = 0;   //count计数有效结点的数目
    while(p != -1) {        //遍历链表找出单链表的所有有效结点(步骤3)
        node[p].order = count++;    //结点在单链表中的序号
        p = node[p].next;       //下一个结点
    }
    sort(node, node + maxn, cmp);       //按单链表从头到尾顺序排列(步骤4)
    //有效结点为前count个结点，为了下面书写方便，因此把count赋给n
    n = count;
    //单链表已经形成，下面是按题目要求的输出(步骤5)
    for(int i = 0; i < n / K; i++) {        //枚举完整的n / K块
        for(int j = (i + 1) * K - 1; j > i * K; j--) {      //第i块倒着输出
            printf("%05d %d %05d\n", node[j].address, node[j].data, node[j - 1].address);
        }
        //下面是每一块的最后一个结点的next地址的处理
        printf("%05d %d ", node[i * K].address, node[i * K].data);
        if(i < n / K - 1) {     //如果不是最后一块，就指向下一块的最后一个结点
            printf("%05d\n", node[(i + 2) * K - 1].address);
        } else {    //是最后一块时
            if(n % K == 0) {        //恰好是最后一个结点，输出-1
                printf("-1\n");
            } else {        //剩下不完整的块按原先的顺序输出
                printf("%05d\n", node[(i + 1) * K].address);
                for(int i = n / K * K; i < n; i++) {
                    printf("%05d %d ", node[i].address, node[i].data);
                    if(i < n - 1) {
                        printf("%05d\n", node[i + 1].address);  //next不用改，就按静态链表的特性来做，主要变下标，下标直接定位结点，故看地址即可
                    } else {
                        printf("-1\n");
                    }
                }
            }
        }
    }
    return 0;
}
