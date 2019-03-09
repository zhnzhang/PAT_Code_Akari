//example
//由于题目直接给的是结点编号的关系，因此使用二叉树的静态写法会比较方便
//对一棵二叉查找树来说，中序遍历是递增的
//因此只需要把给定的整数序列从小到大排序，然后对给定的二叉树进行中序遍历，将排序后序列的整数按中序遍历的顺序填入二叉树，就可以形成二叉查找树
//由于根结点默认为0号结点，因此不需要寻找根结点
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 110;

struct node {       //二叉树的静态写法
    int data;
    int lchild, rchild;
} Node[maxn];
//n为结点个数，in为中序序列，num为已经填入/输出的结点个数
int n, in[maxn], num = 0;

//中序遍历，将排序好的序列依次填入二叉树结点
void inOrder(int root) {
    if(root == -1) {
        return;
    }
    inOrder(Node[root].lchild);
    Node[root].data = in[num++];    //填入序列中的整数
    inOrder(Node[root].rchild);
}

//层序遍历
void BFS(int root) {
    queue<int> q;   //注意队列里是存地址
    q.push(root);   //将根结点地址入队
    num = 0;        //用于控制输出格式(控制空格)
    while(!q.empty()) {
        int now = q.front();        //取出队首元素
        q.pop();
        printf("%d", Node[now].data);   //访问队首元素
        num++;
        if(num < n) printf(" ");
        if(Node[now].lchild != -1) q.push(Node[now].lchild);    //左子树非空
        if(Node[now].rchild != -1) q.push(Node[now].rchild);    //右子树非空
    }
}

int main() {
    int lchild, rchild;
    scanf("%d", &n);    //结点个数
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &lchild, &rchild);    //左右孩子结点的编号
        Node[i].lchild = lchild;
        Node[i].rchild = rchild;
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &in[i]);    //输入排序前的序列
    }
    sort(in, in + n);   //从小到大排序，作为中序遍历
    inOrder(0); //以0号结点为根结点进行中序遍历，填入整数
    BFS(0);     //输出层序遍历序列
    return 0;
}
