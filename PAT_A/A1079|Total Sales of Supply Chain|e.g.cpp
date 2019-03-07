//example
//输入中，如果Ki为0，则表示该结点为叶结点，后面跟的数字为该叶结点的货物量，如果Ki不为0，则表示该结点为非叶子结点，Ki为其子结点的个数，后面跟的数字都是子结点编号
//计算深度时，根结点的深度应设为0.其余注意点与A1090相同，不再赘述
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
struct node {
	double data;			//数据域(货物量)
	vector<int> child;		//指针域
} Node[maxn];		//存放树
int n;
double p, r, ans = 0;		//ans为叶结点货物的价格之和

void DFS(int index, int depth) {
	if(Node[index].child.size() == 0) {		//到达叶结点
		ans += Node[index].data * pow(1 + r, depth);		//累加叶结点货物的价格
		return;
	}
	for(int i = 0; i < Node[index].child.size(); i++) {
		DFS(Node[index].child[i], depth + 1);		//递归访问子结点
	}
}

int main() {
	int k, child;
	scanf("%d%lf%lf", &n, &p, &r);
	r /= 100;
	for(int i = 0; i < n; i++) {
		scanf("%d", &k);
		if(k == 0) {		//叶结点标志
			scanf("%lf", &Node[i].data);		//叶结点货物量
		} else {
			for(int j = 0; j < k; j++) {
				scanf("%d", &child);
				Node[i].child.push_back(child);		//child为结点i的子结点
			}
		}
	}
	DFS(0, 0);		//DFS入口
	printf("%.1f\n", p * ans);	//输出结果
	return 0;
}
