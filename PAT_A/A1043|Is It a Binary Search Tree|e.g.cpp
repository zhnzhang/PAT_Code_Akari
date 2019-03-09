//example
//使用vector来存放初始序列、先序序列、镜像树先序序列，可以方便相互之间的直接比较。(具体比较方法见代码)若使用数组，则比较操作就需要使用循环才能实现
//本题也可以在读入数据的同时建立其镜像二叉树，只需要将插入时的比较逻辑反过来即可。这样先序遍历和后序遍历只需要各写一个函数
//定义根结点时要将其设为空结点(一开始是没有元素的)；在新建结点时要注意令其左右子结点地址设为NULL
//对镜像树的先序遍历只需要在原树的先序遍历时交换左右子树的访问顺序即可
#include <cstdio>
#include <vector>
using namespace std;
struct node {
    int data;                   //数据域
    node *lchild, *rchild;      //指针域
};

void insert(node* &root, int data) {
    if(root == NULL) {      //到达空结点时，即为需要插入的位置
        root = new node;
        root->data = data;
        root->lchild = root->rchild = NULL; //此句不能漏下
        return;
    }
    if(data < root->data) insert(root->lchild, data);   //插在左子树
    else insert(root->rchild, data);        //插在右子树
}

void preOrder(node* root, vector<int> &vi) {    //先序遍历，结果存放于vi
    if(root == NULL) return;
    vi.push_back(root->data);
    preOrder(root->lchild, vi);
    preOrder(root->rchild, vi);
}

//镜像树先序遍历，结果存放于vi
void preOrderMirror(node* root, vector<int> &vi) {
    if(root == NULL) return;
    vi.push_back(root->data);
    preOrderMirror(root->rchild, vi);
    preOrderMirror(root->lchild, vi);
}

void postOrder(node* root, vector<int> &vi) {       //后序遍历，结果存放于vi
    if(root == NULL) return;
    postOrder(root->lchild, vi);
    postOrder(root->rchild, vi);
    vi.push_back(root->data);
}

//镜像树后序遍历，结果存放于vi
void postOrderMirror(node* root, vector<int> &vi) {
    if(root == NULL) return;
    postOrderMirror(root->rchild, vi);
    postOrderMirror(root->lchild, vi);
    vi.push_back(root->data);
}

//origin存放初始序列
//pre、post为先序、后序，preM、postM为镜像树先序、后序
vector<int> origin, pre, preM, post, postM;
int main() {
    int n, data;
    node* root = NULL;      //定义头结点
    scanf("%d", &n);        //输入结点个数
    for(int i = 0; i < n; i++) {
        scanf("%d", &data);
        origin.push_back(data); //将数据加入origin
        insert(root, data);     //将data插入二叉树
    }
    preOrder(root, pre);        //求先序
    preOrderMirror(root, preM); //求镜像树先序
    postOrder(root, post);      //求后序
    postOrderMirror(root, postM);   //求镜像树后序
    if(origin == pre) {     //初始序列等于先序序列
        printf("YES\n");
        for(int i = 0; i < post.size(); i++) {
            printf("%d", post[i]);
            if(i < post.size() - 1) printf(" ");
        }
    } else if(origin == preM) {     //初始序列等于镜像树先序序列
        printf("YES\n");
        for(int i = 0; i < postM.size(); i++) {
            printf("%d", postM[i]);
            if(i < postM.size() - 1) printf(" ");
        }
    } else {
        printf("NO\n");     //否则输出NO
    }
    return 0;
}
