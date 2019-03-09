//example
//采用静态写法
//对CBT数组表示的二叉树进行中序遍历，并在遍历过程中将数字从小到大填入数组，最后就能得到一颗完全二叉排序树
//根结点下标必须为1
//完全二叉树到达空结点的标志是当前结点root的编号大于结点个数n

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1010;
//n为结点数，number用以存放结点权值，CBT用以存放完全二叉树
//index从小到大枚举number数组
int n, number[maxn], CBT[maxn], index = 0;

void inOrder(int root) {        //中序遍历
    if(root > n) return;        //空结点，直接返回
    inOrder(root * 2);              //往左子树递归
    CBT[root] = number[index++];    //根结点处赋值number[index]
    inOrder(root * 2 + 1);      //往右子树递归
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &number[i]);
    }
    sort(number, number + n);   //从小到大排序
    inOrder(1);         //1号位位根结点
    for(int i = 1; i <= n; i++) {
        printf("%d", CBT[i]);       //CBT数组本身就是按层序存放完全二叉树的结点，具体可看上面inOrder的实现
        if(i < n) printf(" ");
    }
    return 0;
}
