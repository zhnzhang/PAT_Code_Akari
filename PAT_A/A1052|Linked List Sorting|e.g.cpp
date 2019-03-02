//example
//注意标记有效结点并排到数组左端，过程中应该记录下有效结点的个数
//要留意-1的输出，不能高位补0
//区分有效结点与无效结点
//数据里面还有可能出现均为无效的情况，这时候要根据有效结点的个数 特判输出"0 -1"

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100005;
struct Node {       //定义静态链表(步骤1)
    int address, data, next;
    bool flag;      //结点是否在链表上
} node[maxn];

bool cmp(Node a, Node b) {
    if(a.flag == false || b.flag == false) {
        return a.flag > b.flag;     //只要a和b中有一个无效结点，就把它放后面去，把有效结点都排到数组的左端
    } else {
        return a.data < b.data;     //如果都是有效结点，则按要求排序
    }
}

int main() {
    for(int i = 0; i < maxn; i++) {     //初始化(步骤2)
        node[i].flag = false;
    }
    int n, begin, address;
    scanf("%d %d", &n, &begin);
    for(int i = 0; i < n; i++) {
        scanf("%d", &address);
        scanf("%d %d", &node[address].data, &node[address].next);
        node[address].address = address;
    }
    int count = 0, p = begin;
    //枚举链表，对flag进行标记，同时计数有效结点个数(步骤3)
    while(p != -1) {
        node[p].flag = true;
        count++;
        p = node[p].next;
    }
    if(count == 0) {        //特判，新链表中没有结点时输出0 -1
        printf("0 -1");
    } else {
        //筛选有效结点，并按data从小到大排序(步骤4)
        sort(node, node + maxn, cmp);
        //输出结果(步骤5)
        //防止-1被%05d化，提前判断
        printf("%d %05d\n", count, node[0].address);
        for(int i = 0; i < count; i++) {
            if(i < count - 1) {
                printf("%05d %d %05d\n", node[i].address, node[i].data, node[i + 1].address);   //这里用i + 1结点的address而不是i结点的next，主要因为排序后next没改，而address是及时更新的所以这么写
            } else {
                printf("%05d %d -1\n", node[i].address, node[i].data);
            }
        }
    }
    return 0;
}
