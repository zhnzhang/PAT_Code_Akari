//链表建立
//从编程习惯上，我们应该养成及时释放空间的习惯
//本书的示例代码为了使算法的讲解更侧重于对思路的讲解，所以在代码中没有释放空间，但我们自己写的时候，要注意释放空间，申请与释放的操作成对使用，养成好的习惯

#include <cstdio>
#include <cstdlib>
struct node {   //链表结点
    int data;
    node* next;
};

//创建链表(关键函数)
node* create(int Array[]) {
    node *p, *pre, *head;   //pre保存当前结点的前驱结点，head为头结点
    head = new node;    //创建头结点
    head->next = NULL;  //头结点不需要数据域，指针域初始为NULL
    pre = head; //记录pre为head
    for(int i = 0; i < 5; i++) {
        p = new node;   //新建结点
        //将Array[i]赋给新建的结点作为数据域，也可以scanf输入
        p->data = Array[i];
        p->next = NULL; //新结点的指针域设为NULL
        pre->next = p;  //前驱结点的指针域设为当前新建结点的地址
        pre = p;    //把pre设为p，作为下个结点的前驱结点
    }
    return head;    //返回头结点指针
}

int main() {
    int Array[5] = {5, 3, 6, 1, 2};
    node* L = create(Array);    //新建链表，返回的头指针head赋给L
    L = L->next;    //从第一个结点开始有数据域
    while(L != NULL) {
        printf("%d", L->data);  //输出每个结点的数据域
        L = L->next;
    }
    return 0;
}

//注意自己再去学习如何释放所申请的链表空间。
