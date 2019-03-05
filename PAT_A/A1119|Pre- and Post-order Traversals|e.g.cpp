//example
//左(右)子树的先序序列第一个结点和左(右)子树的后序序列最后一个结点也是相同的，该题用这个结论启发，从先后序遍历中分辨左右子树
//当先序序列的第二个结点就是后序序列的倒数第二个结点时，说明只存在一棵子树，此时会产生不唯一性
//只要存在一个结点的孩子个数为奇数，那么就是不唯一的；只有当所有结点的孩子个数均为偶数时，二叉树才唯一
//在有些写法中，计算其中一棵子树的结点个数需要考虑特殊情况，即preL == preR时的结果可能无法用k - postL + 1获得，可以使用参考代码中统计子树结点个数(numLeft)的方法
//有些读者可能只设置了当递归时某层的结点个数为2(即preL + 1 == preR)时认为二叉树不唯一。
//事实上这是不完备或者说是片面的，这只是上面所说的"先序序列的第二个结点就是后序序列的倒数第二个结点"的一种特殊情况而已(本题数据较弱，只使用这种写法也能通过)

#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 50;
struct node {
	int data;
	node* lchild;
	node* rchild;
};
int pre[maxn], post[maxn];	//先序、后序
int n;		//结点个数
bool isUnique = true;		//二叉树是否唯一

//当前二叉树的先序序列区间为[preL, preR],后序序列区间为[postL, postR]
//create函数返回构建出的二叉树的根结点地址
node* create(int preL, int preR, int postL, int postR) {
	if(preL > preR) {
		return NULL;		//空树
	}
	node* root = new node;
	root->data = pre[preL];		//根结点
	//在后序序列中找到先序序列的第二个结点，其下标为k；numLeft为(左)子树结点个数
	int k, numLeft = 0;
	for(k = postL; k < postR; k++) {
		numLeft++;		//(左)子树结点个数加1
		if(post[k] == pre[preL + 1]) {		//在后序序列中找到先序序列的第二个结点
			break;
		}
	}
	if(k == postR - 1) isUnique = false;		//先序第二个结点等于后序倒数第二个结点，说明不唯一
	root->lchild = create(preL + 1, preL + numLeft, postL, k);		//建立左子树
	root->rchild = create(preL + numLeft + 1, preR, k + 1, postR - 1);		//建立右子树
	return root;		//返回根结点
}

vector<int> in;		//中序
void inOrder(node* root) {		//中序遍历
	if(!root) return;
	inOrder(root->lchild);
	in.push_back(root->data);		//将中序结果存下来
	inOrder(root->rchild);
}

int main() {
	scanf("%d", &n);		//输入结点个数
	for(int i = 0; i < n; i++) {
		scanf("%d", &pre[i]);		//输入先序
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &post[i]);		//输入后序
	}
	node* root = create(0, n - 1, 0, n - 1);		//建树
	inOrder(root);		//获取中序序列
	printf(isUnique ? "Yes\n" : "No\n");		//根据是否唯一的情况输出Yes跟No
	for(int i = 0; i < in.size(); i++) {		//输出中序序列
		printf("%d", in[i]);
		printf(i < in.size() - 1 ? " " : "\n");		//除了最后一个输出换行，其他输出空格
	}
	return 0;
}
