#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 35;

typedef struct BitNode {
    int data;
    BitNode* lchild;
    BitNode* rchild;
    BitNode() {}
    BitNode(int n) {
        data = n;
        lchild = NULL;
        rchild = NULL;
    }
}BitNode, *BiTree;

vector<int> vi;

BiTree BuildTree(int post[], int postl, int postr, int in[], int inl, int inr) {
    if (postl > postr) {
        return NULL;
    }
    BiTree root = new BitNode(post[postr]);
    int k;
    for (int i = inl; i <= inr; i++) {
        if (in[i] == post[postr]) {
            k = i;
            break;
        }
    }
    int numleft = k - inl;
    root->lchild = BuildTree(post, postl, postl + numleft - 1, in, inl, k - 1);
    root->rchild = BuildTree(post, postl + numleft, postr - 1, in, k + 1, inr);
    return root;
}

void LevelOrder(BiTree root) {
    queue<BiTree> q;
    BiTree p;
    q.push(root);
    while (!q.empty()) {
        p = q.front();
        vi.push_back(p->data);
        q.pop();
        if (p->lchild != NULL) {
            q.push(p->lchild);
        }
        if (p->rchild != NULL) {
            q.push(p->rchild);
        }
    }
}

int main() {
    int n;
    int post[MAXN], in[MAXN];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", post + i);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", in + i);
    }
    BiTree root = BuildTree(post, 0, n - 1, in, 0, n - 1);
    LevelOrder(root);
    for (int i = 0; i < vi.size(); i++) {
        printf("%d", vi[i]);
        if (i != vi.size() - 1) {
            printf(" ");
        }
    }
    return 0;
}



#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 50;
struct node {
	int data;
	node* lchild;
	node* rchild;
};
int pre[maxn], in[maxn], post[maxn];		//先序、中序、后序
int n;		//结点个数

//当前二叉树的后序序列区间为[postL, postR],中序序列区间为[inL, inR]
//create函数返回构建出的二叉树的根结点地址
node* create(int postL, int postR, int inL, int inR) {
	if(postL > postR) {
		return NULL;	//后序序列长度小于等于0时，直接返回
	}
	node* root = new node;	//新建一个新的结点，用来存放当前二叉树的根节点
	root->data = post[postR];	//新结点的数据域为根节点的值
	int k;
	for(k = inL; k <= inR; k++) {
		if(in[k] == post[postR]) break;		//在中序序列中找到in[k] == post[postR]的结点
	}
	int numLeft = k - inL;	//左子树的结点个数
	//返回左子树的根结点地址，赋值给root的左指针
	root->lchild = create(postL, postL + numLeft - 1, inL, k - 1);
	//返回右子树的根节点地址，赋值给root的右指针
	root->rchild = create(postL + numLeft, postR - 1, k + 1, inR);
	return root;	//返回根结点地址
}

int num = 0;	//已输出的结点个数
void BFS(node* root) {
	queue<node*> q;		//注意队列里是存地址
	q.push(root);		//将根结点地址入队
	while(!q.empty()) {
		node* now = q.front();	//取出队首元素
		q.pop();
		printf("%d", now->data);	//访问队首元素
		num++;
		if(num < n) printf(" ");
		if(now->lchild != NULL) q.push(now->lchild);	//左子树非空
		if(now->rchild != NULL) q.push(now->rchild);	//右子树非空
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &post[i]);
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
	}
	node* root = create(0, n - 1, 0, n - 1);	//建树
	BFS(root);		//层序遍历
	return 0;
}
