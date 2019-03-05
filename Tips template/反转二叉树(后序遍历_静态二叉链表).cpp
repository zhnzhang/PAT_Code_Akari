//后序遍历，用以反转二叉树
void postOrder(int root) {
	if(root == -1) {
		return;
	}
	postOrder(Node[root].lchild);
	postOrder(Node[root].rchild);
	swap(Node[root].lchild, Node[root].rchild);		//交换左右孩子结点
}
