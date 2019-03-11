#include <cstdio>

//在下面代码中，很关键的一点是有的代码段根结点指针root使用了引用&。引用的作用在前面已经介绍过，即在函数中修改root会直接修改原变量
//这么做是因为在insert函数中新建了结点，并把新结点的地址赋给了当层的root。
//如果不使用引用，root = new node这个语句对root的修改就无法作用到原变量(即上一层的root->lchild与root->rchild)上去，也就不能把新结点接到二叉树上面。
//因此insert函数必须加引用
//那么为什么前面的search函数不需要加引用呢？这是因为search函数中修改的是指针root指向的内容，而不是root本身，而对指针指向的结点内容的修改是不需要加引用的。
//详情可见前面关于参数传递的相关知识

//进一步看，如何判断我写这类函数的时候是否需要加引用呢？一般来说，如果函数中需要新建结点，即对二叉树的结构做出修改，就需要加引用；
//如果只是修改当前已有结点的内容，或仅仅是遍历树，就不用加引用。
//至于判断不出来的情况，不妨直接试一下加引用和不加引用的区别再来选择
//最后提醒，在新建结点之后，务必令新结点的左右指针域为NULL，表示这个新结点暂时没有左右子树


struct node {
    int v, height;              //v为结点权值，height为当前子树高度
    node *lchild, *rchild;      //左右孩子结点地址
};

//生成一个新结点，v为结点权值
node* newNode(int v) {
    node* Node = new node;      //申请一个node型变量的地址空间
    Node->v = v;            //结点权值为v
    Node->height = 1;       //结点高度初始为1
    Node->lchild = Node->rchild = NULL;     //初始状态下没有左右孩子
    return Node;        //返回新建结点的地址
}

//获取以root为根结点的子树的当前height
int getHeight(node* root) {
    if(root == NULL) return 0;  //空结点高度为0
    return root->height;
}

//计算结点root的平衡因子
int getBalanceFactor(node* root) {
    //左子树高度减右子树高度
    return getHeight(root->lchild) - getHeight(root->rchild);
}

//更新结点root的height
void updateHeight(node* root) {
    //max(左孩子的height, 右孩子的height) + 1
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

//search函数查找AVL树中数据域为x的结点
void search(node* root, int x) {
    if(root == NULL) {          //空树，查找失败
        printf("search failed\n");
        return;
    }
    if(x == root->data) {       //查找成功，访问之
        printf("%d\n", root->data);
    }
    else if(x < root->data) {       //如果x比根结点的数据域小，说明x在左子树
        search(root->lchild, x);    //往左子树搜索x
    }
    else {          //如果x比根结点大的数据域大，说明x在右子树
        search(root->rchild, x);    //往右子树搜索x
    }
}

//左旋(Left Rotation)
void L(node* &root) {
    node* temp = root->rchild;          //root指向结点A，temp指向结点B
    root->rchild = temp->lchild;        //步骤1
    temp->lchild = root;        //步骤2
    updateHeight(root);         //更新结点A的高度
    updateHeight(temp);         //更新结点B的高度
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
