#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;
const int maxn = 50;
struct node {
	int data;
	node* lchild;
	node* rchild;
};
int pre[maxn], in[maxn], post[maxn];	//先序、中序及后序
int n;		//结点个数

//当前二叉树的先序序列区间为[preL, preR],中序序列区间为[inL, inR]
//create函数返回构建出的二叉树的根结点地址
node* create(int preL, int preR, int inL, int inR) {
	if(preL > preR) {
		return NULL;		//若先序序列长度小于等于0，则直接返回
	}
	node* root = new node;	//新建一个新的结点，用来存放当前二叉树的根结点
	root->data = pre[preL];	//新结点的数据域为根结点的值
	int k;
	for(k = inL; k <= inR; k++) {
		if(in[k] == pre[preL]) {	//在中序序列中找到in[k] == pre[preL]的结点
			break;
		}
	}
	int numLeft = k - inL;		//左子树的结点个数
	//返回左子树的根结点地址，赋值给root的左指针
	root->lchild = create(preL + 1, preL + numLeft, inL, k - 1);
	//返回右子树的根结点地址，赋值给root的右指针
	root->rchild = create(preL + numLeft + 1, preR, k + 1, inR);
	return root;		//返回根结点地址
}

int num = 0;		//已输出的结点个数
void postorder(node* root) {		//后序遍历
	if(root == NULL) {
		return;
	}
	postorder(root->lchild);
	postorder(root->rchild);
	printf("%d", root->data);
	num++;
	if(num < n) {
		printf(" ");
	}
}

int main() {
	scanf("%d", &n);
	char str[5];
	stack<int> st;
	int x, preIndex = 0, inIndex = 0;	//入栈元素、先序序列位置及中序序列位置
	for(int i = 0; i < 2 * n; i++) {	//出栈入栈共2n次
		scanf("%s", str);
		if(strcmp(str, "Push") == 0) {	//入栈
			scanf("%d", &x);
			pre[preIndex++] = x;		//令pre[preIndex] = x
			st.push(x);
		}
		else {
			in[inIndex++] = st.top();		//令in[inIndex] = st.top
			st.pop();
		}
	}
	node* root = create(0, n - 1, 0, n - 1);	//建树
	postorder(root);	//后序遍历
	return 0;
}
