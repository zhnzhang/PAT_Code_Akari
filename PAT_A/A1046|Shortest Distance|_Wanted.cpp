//A1046.Shortest Distance
//example
//以dis[i]表示1号结点按顺时针方向到达"i号结点顺时针方向的下一个结点"的距离(1 <= i <= N)
//sum表示一圈的总距离
//对每个查询left -> right, 其结果就是dis(left, right)与sum - dis(left, right)中的较小值
//dis数组和sum在读入时就可以进行累加得到，这样对每个查询left -> right, dis(left, right)(left和right按顺时针之间的距离)，其实就是dis[right - 1] - dis[left - 1]
//这样可以做到查询复杂度为O(1)
//查询的两个点的编号可能会有left > right的情况，这种情况下，需要交换left和right
//此题需要对dis数组和sum进行预处理，不然很容易超时。这是因为在极端情况下，每次查询都需要遍历整个数组，即有10^5次操作，而共有10^4个查询，所以极端情况会有10^9次操作，这在100ms时限内是不能承受的
//之所以不把dis[i]设置为1号结点按顺时针方向到达i号结点的距离，是因为N号结点到达1号结点的距离无法被这个数组保存
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
int dis[MAXN], A[MAXN];		//dis数组含义见上面注释，A[i]存放i号与i + 1号顶点的距离

int main() {
	int sum = 0, query, n, left, right;		//query是查询的次数
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
		sum += A[i];		//累加sum
		dis[i] = sum;		//预处理dis数组
	}
	scanf("%d", &query);
	for(int i = 0; i < query; i++) {		//query个查询
		scanf("%d %d", &left, &right);		//left -> right
		if(left > right) {
			swap(left, right);			//left > right时交换
		}
		int temp = dis[right - 1] - dis[left - 1];
		printf("%d\n", min(temp, sum - temp));		//对每个询问看最短距离的核心语句在此
	}
	return 0;
}
