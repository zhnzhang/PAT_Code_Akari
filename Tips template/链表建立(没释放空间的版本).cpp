//链表建立
//从编程习惯上，我们应该养成及时释放空间的习惯
//本书的示例代码为了使算法的讲解更侧重于对思路的讲解，所以在代码中没有释放空间，但我们自己写的时候，要注意释放空间，申请与释放的操作成对使用，养成好的习惯

#include <cstdio>
#include <cstdlib>
struct node {
    int data;
    node* next;
};

node* create(int Array[]) {
    node *p, *pre, *head;
    head = new node;
    head->next = NULL;
    pre = head;
    for(int i = 0; i < 5; i++) {
        p = new node;
        p->data = Array[i];
        p->next = NULL;
        pre->next = p;
        pre = p;
    }
    return head;
}

int main() {
    int Array[5] = {5, 3, 6, 1, 2};
    node* L = create(Array);
    L = L->next;
    while(L != NULL) {
        printf("%d", L->data);
        L = L->next;
    }
    return 0;
}

//注意自己再去学习如何释放所申请的链表空间。
