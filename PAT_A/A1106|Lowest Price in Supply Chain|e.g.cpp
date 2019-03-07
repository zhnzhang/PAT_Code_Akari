//example
//本题实际就是在求树的深度最小的叶子结点，只需要在A1079的基础上稍加改动即可完成。主要的改动在于对叶子结点的处理
//计算深度时，根结点的深度应设为0，其余注意点与A1090相同

#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
const double INF = 1e12;
vector<int> Node[maxn];
int n, num = 0;
double p, r, ans = INF;
void DFS(int index, int depth) {
	if(Node[index].size() == 0) {
		double price = p * pow(1 + r, depth);
		if(price < ans) {
			ans = price;
			num = 1;
		}
		else if(price == ans) {
			num++;
		}
		return;
	}
	for(int i = 0; i < Node[index].size(); i++) {
		DFS(Node[index][i], depth + 1);
	}
}

int main() {
	int k, child;
	scanf("%d%lf%lf", &n, &p, &r);
	r /= 100;
	for(int i = 0; i < n; i++) {
		scanf("%d", &k);
		if(k != 0) {
			for(int j = 0; j < k; j++) {
				scanf("%d", &child);
				Node[i].push_back(child);
			}
		}
	}
	DFS(0, 0);
	printf("%.4f %d\n", ans, num);
	return 0;
}
