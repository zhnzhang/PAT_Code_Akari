//example
//删不删，输出的都得是有效结点。
//表现出结点性质的变量得考虑下，同时注意初始化，初始化的值一般选变量取不到的值，当然也要根据题意来衡量
//留意-1的输出(特判，单独处理)
//结点性质由int型变量order定义，表示结点在链表上的序号，最后需要先输出所有未删除的结点，然后输出所有被删除的结点，在后面的步骤中，令未删除的结点的order从0开始编号，被删除的结点的order从maxn开始编号
//初始化，令order的初值均为2maxn，这样无效结点就会被区分开来
//由于未删除的结点的order从0开始编号，被删除的结点从maxn开始编号，而无效结点的order为初始的2maxn，因此按结点的order从小到大排序，结点的顺序就是按未删除的结点、已删除的结点、无效结点进行排列
//输出时，最后一个未删除的结点和最后一个被删除的结点单独处理

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100005;
const int TABLE = 1000010;
struct Node {
    int address, data, next;
    int order;
} node[maxn];

bool isExist[TABLE] = {false};

bool cmp(Node a, Node b) {
    return a.order < b.order;
}

int main() {
    memset(isExist, false, sizeof(isExist));
    for(int i = 0; i < maxn; i++) {
        node[i].order = 2 * maxn;
    }
    int n, begin, address;
    scanf("%d %d", &begin, &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &address);
        scanf("%d %d", &node[address].data, &node[address].next);
        node[address].address = address;
    }
    //未删除的有效结点个数和已删除的有效结点个数
    int countValid = 0, countRemoved = 0, p = begin;
    while(p != -1) {
        if(!isExist[abs(node[p].data)]) {
            isExist[abs(node[p].data)] = true;
            node[p].order = countValid++;
        } else {
            node[p].order = maxn + countRemoved++;
        }
        p = node[p].next;
    }
    sort(node, node + maxn, cmp);
    int count = countValid + countRemoved;
    for(int i = 0; i < count; i++) {
        if(i != countValid - 1 && i != count - 1) {
            printf("%05d %d %05d\n", node[i].address, node[i].data, node[i + 1].address);   //sort后就要这样实现下一个结点地址的输出
        } else {
            printf("%05d %d -1\n", node[i].address, node[i].data);
        }
    }
    return 0;
}
