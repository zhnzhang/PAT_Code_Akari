//example
//使用map容易超时
//scanf使用%c格式是可以读入空格的，因此在输入地址、数据、后继结点地址时，格式不能写成%d%c%d，必须要在中间加空格

#include <cstdio>
#include <cstring>
const int maxn = 100010;
struct Node {
    char data;  //数据域
    int next;   //指针域
    bool flag;  //结点是否在第一条链表中出现
} node[maxn];

int main() {
    for(int i = 0; i < maxn; i++) {
        node[i].flag = false;
    }
    int s1, s2, n;      //s1与s2分别代表两条链表的首地址
    scanf("%d %d %d", &s1, &s2, &n);
    int address, next;  //结点地址与后继结点地址
    char data;  //数据
    for(int i = 0; i < n; i++) {
        scanf("%d %c %d", &address, &data, &next);
        node[address].data = data;
        node[address].next = next;
    }
    int p;
    for(p = s1; p != -1; p = node[p].next) {
        node[p].flag = true;        //枚举第一条链表的所有结点，令其出现次数为1
    }
    for(p = s2; p != -1; p = node[p].next) {
        //找到第一个已经在第一条链接中出现的结点
        if(node[p].flag == true) break;
    }
    if(p != -1) {   //如果第二条链表还没有到达结尾，说明找到了共用结点
        printf("%05d\n", p);
    } else {
        printf("-1\n");
    }
    return 0;
}
