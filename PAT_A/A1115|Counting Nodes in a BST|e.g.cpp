//example
//对BFS的每一轮开头，可以知道队列中的元素个数size即为当前层的结点个数
//与根结点相同的结点应当插到左子树中
//下面的代码中同时写了DFS和BFS的代码，读者可以按需阅读，其中DFS的执行和输出代码(共两行)被注释，已明确区分BFS和DFS的执行和输出代码

#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 1010;
struct node {
    int data;                   //数据域
    node *lchild, *rchild;      //指针域
};

void insert(node* &root, int data) {
    if(root == NULL) {      //到达空结点时，即为需要插入的位置
        root = new node;
        root->data = data;
        root->lchild = root->rchild = NULL;     //此句不能漏
        return;
    }
    if(data <= root->data) insert(root->lchild, data);      //插在左子树
    else insert(root->rchild, data);        //插在右子树
}

node* buildTree(int n) {
    node* root = NULL;              //定义头结点
    for(int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        insert(root, data);         //将data插入二叉树
    }
    return root;
}

int n1 = 0, n2 = 0;     //n1为最下面一层的结点个数，n2为倒数第二层的结点个数
void BFS(node* root) {
    queue<node*> q;     //因为队列传入副本，所以这里是定义结点指针(结点地址)的队列
    q.push(root);       //根结点入队
    int size;       //当前层的结点个数
    while(!q.empty()) {
        size = q.size();        //队列大小即为当前层结点个数
        for(int i = 0; i < size; i++) { //遍历当前层所有结点
            node* front = q.front();    //取出队首结点
            q.pop();        //出队
            if(front->lchild) q.push(front->lchild);    //左孩子入队
            if(front->rchild) q.push(front->rchild);    //右孩子入队
        }
        if(!q.empty()) n2 = size;       //只要下一层还有结点，就让n2不断赋值为当前层结点个数
    }
    n1 = size;      //n1为最下面一层的结点个数
}

//num数组记录每层的结点个数，maxDepth为最大深度
int num[maxn] = {0}, maxDepth = -1;
void DFS(node* root, int depth) {
    if(!root) return;       //空结点直接返回
    num[depth]++;       //第depth层的结点个数加1
    maxDepth = max(maxDepth, depth);        //更新最大深度
    DFS(root->lchild, depth + 1);       //左子树递归
    DFS(root->rchild, depth + 1);       //右子树递归
}

int main() {
    int n;
    scanf("%d", &n);        //输入结点个数
    node* root = buildTree(n);      //建树
    BFS(root);      //层次遍历，计算最下面两层的结点个数n1和n2
    printf("%d + %d = %d\n", n1, n2, n1 + n2);  //BFS输出结果
    //DFS(root, 1);     //执行DFS，其中根结点深度为1
    //printf("%d + %d = %d\n", num[maxDepth], num[maxDepth - 1], num[maxDepth] + num[maxDepth - 1]);    //DFS输出结果
    return 0;
}
