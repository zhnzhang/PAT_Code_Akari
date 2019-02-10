//example
//令sum[i]表示A[1]到A[i]的和值，序列里都是正值，故sum[i]一定是严格单调递增的，这样的好处在于如果要求连续子序列A[i]到A[j]的和值，只需要计算sum[j] - sum[i - 1]即可
//为了下面计算方便，初始化sum[0] = 0
//既然sum数组严格单调递增，那就可以用二分法来做这道题
//考虑到题目要求输出所有方案，因此需要对序列进行两次遍历，其中第一次遍历求出大于等于S的最接近S的和值nearS
//第二次遍历找到那些和值恰好为nearS的方案并输出，总复杂度O(nlogn)

#include <cstdio>
const int N = 100010;
int sum[N];
int n, S, nearS = 100000010;

//upper_bound函数返回在[L, R]内第一个大于x的位置
int upper_bound(int L, int R, int x) {
	int left = L, right = R, mid;
	while(left < right) {
		mid = left + (right - left) / 2;
		if(sum[mid] > x) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
	return left;
}

int main() {
	scanf("%d%d", &n, &S);		//元素个数，和值S
	sum[0] = 0;			//初始化sum[0] = 0
	for(int i = 1; i <= n; i++) {
		scanf("%d", &sum[i]);
		sum[i] += sum[i - 1];		//求sum[i]
	}
	for(int i = 1; i <= n; i++) {	//枚举左端点
		int j = upper_bound(i, n + 1, sum[i - 1] + S);	//求右端点
		if(sum[j - 1] - sum[i - 1] == S) {		//查找成功(注意是j - 1而不是j)
			nearS = S;			//最接近S的值就是S
			break;
		}
		else if(j <= n && sum[j] - sum[i - 1] < nearS) {
			//存在大于S的解并小于nearS
			nearS = sum[j] - sum[i - 1];		//更新当前nearS
		}
	}
	for(int i = 1; i <= n; i++) {
		int j = upper_bound(i, n + 1, sum[i - 1] + nearS);		//求右端点
		if(sum[j - 1] - sum[i - 1] == nearS) {		//查找成功
			printf("%d-%d\n", i, j - 1);		//输出左端点和右端点(注意是j - 1而不是j，大概是因为upper_bound得出的位置是第一次大于...的吧)
		}
	}
	return 0;
}
