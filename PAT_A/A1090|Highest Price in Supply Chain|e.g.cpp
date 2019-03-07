//example
//根结点的价格为P，不需要乘以(1 + r)
//题目中给定的r是百分数，因此需要除以100.例如样例中的r = 1.00是指1%
//输入中第二行给定的是i号结点的父亲结点

#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
vector<int> child[maxn];		//存放树
double p, r;
//maxDepth为最大深度，num为最大深度的叶结点个数
int n, maxDepth = 0, num = 0;

void DFS(int index, int depth) {
	if(child[index].size() == 0) {		//到达叶结点
		if(depth > maxDepth) {		//深度比目前最大深度大
			maxDepth = depth;		//更新最大深度
			num = 1;		//重置最大深度的叶结点个数为1
		}
		else if(depth == maxDepth) {	//深度等于最大深度
			num++;		//最大深度的叶结点个数加1
		}
		return;
	}
	for(int i = 0; i < child[index].size(); i++) {
		DFS(child[index][i], depth + 1);		//递归访问结点index的子结点
	}
}

int main() {
	int father, root;
	scanf("%d%lf%lf", &n, &p, &r);
	r /= 100;			//将百分数除以100
	for(int i = 0; i < n; i++) {
		scanf("%d", &father);
		if(father != -1) {
			child[father].push_back(i);		//i是father的子结点
		}
		else {
			root = i;		//根结点为root
		}
	}
	DFS(root, 0);		//DFS入口
	printf("%.2f %d\n", p * pow(1 + r, maxDepth), num);		//输出结果
	return 0;
}
