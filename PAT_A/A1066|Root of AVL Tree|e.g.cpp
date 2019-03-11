 //example
 //本题直接输出中位数也可以得到许多分数(PAT考题中，用于测试的数据点都对应一定的分数，因此考生不要直接放弃不会做的题目，而应该通过尽可能多地完成题目，以去的分数)
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 30;
struct node {
    int v, height;      //v为结点权值，height为当前子树高度
    node *lchild, *rchild;      //左右孩子结点地址
} *root;

//生成一个新结点，v为结点权值
node* newNode(int v) {
    node* Node = new node;  //申请一个node型变量的地址空间
    Node->v = v;        //结点权值为v
    Node->height = 1;   //结点高度初始为1
    Node->lchild = Node->rchild = NULL; //初始状态下没有左右孩子
    return Node;    //返回新建结点的地址
}

//获取以root为根结点的子树的当前height
int getHeight(node* root) {
    if(root == NULL) return 0;  //空结点高度为0
    return root->height;
}

//更新结点root的height
void updateHeight(node* root) {
     //max(左孩子的height, 右孩子的height) + 1
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

//计算结点root的平衡因子
int getBalanceFactor(node* root) {
     //左子树高度减右子树高度
    return getHeight(root->lchild) - getHeight(root->rchild);
}

//左旋(Left Rotation)
void L(node* &root) {
    node* temp = root->rchild;  //root指向结点A，temp指向结点B
    root->rchild = temp->lchild;    //步骤1
    temp->lchild = root;    //步骤2
    updateHeight(root); //更新结点A的高度
    updateHeight(temp); //更新结点B的高度
    root = temp;        //步骤3
}

//右旋(right Rotation)
 void R(node* &root) {
     node* temp = root->lchild;          //root指向结点B，temp指向结点A
     root->lchild = temp->rchild;        //步骤1
     temp->rchild = root;    //步骤2
     updateHeight(root);     //更新结点B的高度
     updateHeight(temp);     //更新结点A的高度
     root = temp;    //步骤3
 }

//AVL插入代码
//只有在从根结点到该插入结点的路径上的结点才可能发生平衡因子变化，因此只需对这条路径上失衡的结点进行调整。
//可以证明，只要把最靠近插入结点的失衡结点调整到正常，路径上的所有结点就都会平衡
//插入权值为v的结点
 void insert(node* &root, int v) {
     if(root == NULL) {      //到达空结点
         root = newNode(v);
         return;
     }
     if(v < root->v) {               //v比根结点的权值小
         insert(root->lchild, v);        //往左子树插入
         updateHeight(root);     //更新树高
         if(getBalanceFactor(root) == 2) {
             if(getBalanceFactor(root->lchild) == 1) {       //LL型
                 R(root);
             } else if(getBalanceFactor(root->lchild) == -1) {       //LR型
                 L(root->lchild);
                 R(root);
             }
         }
     } else {        //v比根结点的权值大
         insert(root->rchild, v);        //往右子树插入
         updateHeight(root);     //更新树高
         if(getBalanceFactor(root) == -2) {
             if(getBalanceFactor(root->rchild) == -1) {          //RR型
                 L(root);
             } else if(getBalanceFactor(root->rchild) == 1) {    //RL型
                 R(root->rchild);
                 L(root);
             }
         }
     }
 }

//AVL树的建立
 node* Create(int data[], int n) {
     node* root = NULL;      //新建空的根结点root
     for(int i = 0; i < n; i++) {
         insert(root, data[i]);      //将data[0]~data[n - 1]插入AVL树中
     }
     return root;    //返回根结点
 }
 
int main() {
    int n, data[maxn] = {0};
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }
    root = Create(data, n);
    printf("%d\n", root->v);
    return 0;
}
