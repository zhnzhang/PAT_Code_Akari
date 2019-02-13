//example
//问题转换成:在一个给定的递增序列中，确定一个左端点a[i]和一个右端点a[j]使得a[j] <= a[i] * p成立，且j - i最大
//从左至右扫描序列，对其中的每一个数a[i]，在a[i + 1]~a[n - 1]的二分查找第一个超过a[i] * p的数的位置j，这样j - i就是对位置i来说满足a[j] <= a[i] * p的最远长度
//取所有j - i的最大值即为所求的答案，时间复杂度为O(logn)
//二分查找的写法中，需要考虑序列中的所有数都不超过a[i] * p的情况
//二分查找普通写法
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
long long n, p, a[maxn];

//binarySearch函数在[i + 1, n - 1]范围内查找第一个大于x的数的位置
long long binarySearch(long long i, long long x) {
	if(a[n - 1] <= x) {
		return n;			//如果所有数都不大于x，返回n
	}
	long long l = i + 1, r = n - 1, mid;		//在[i + 1, n - 1]内查找
	while(l < r) {
		mid = l + (r - l) / 2;
		if(a[mid] <= x) {	//若a[mid] <= x, 说明第一个大于x的数只可能在mid后面
			l = mid + 1;	//左端点记为mid + 1
		}
		else {				//若a[mid] > x,说明第一个大于x的数在mid之前(含mid)
			r = mid;		//右端点记为mid
		}
	}
	return l;				//由于while结束时l == r,因此返回l或者r皆可
}

int main() {
	scanf("%d%d", &n, &p);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);			//递增排序
	long long ans = 1;		//最大长度，初值为1(表示至少有一个数)
	for(int i = 0; i < n; i++) {
		//在a[i + 1]~a[n - 1]中查找第一个超过a[i] * p的数，返回其位置给j
		long long j = binarySearch(i, a[i] * p);
		ans = max(ans, j - i);		//更新最大长度
	}
	printf("%d\n", ans);	//输出结果
	return 0;
}

//二分查找(使用upper_bound函数)
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int n, p, a[maxn];

int main() {
	scanf("%d%d", &n, &p);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);		//递增排序
	int ans = 1;		//最大长度，初值为1(表示至少有一个数)
	for(int i = 0; i < n; i++) {
		//在a[i + 1]~a[n - 1]中查找第一个超过a[i] * p的数，返回其位置给j
		int j = upper_bound(a + i + 1, a + n, (long long)a[i] * p) - a;
		ans = max(ans, j - i);		//更新最大长度
	}
	printf("%d\n", ans);	//输出结果
	return 0;
}

//example
//B1030/A1085.完美数列
//下面使用two pointers的解决方案，时间复杂度O(n)
//容易获得下面这个性质: 如果a[j] <= a[i] * p成立，那么对[i, j]内的任意位置k，一定有a[k] <= a[i] * p也成立
//计数器count存放满足a[j] <= a[i] * p的最大长度，j不断增加的过程中更新count(注意看下更新语句，不是单纯的加1)
//该方案将在a[j] <= a[i] * p的条件下始终控制i和j的距离最大
//建议直接把序列中的元素都定义为long long型

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int main() {
	int n, p, a[maxn];
	scanf("%d%d", &n, &p);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);		//从小到大排序
	int i = 0, j = 0, count = 1;	//注意count初值设为1
	while(i < n && j < n) {
		//j不断右移，直到恰好不满足条件
		while(j < n && a[j] <= (long long)a[i] * p) {
			count = max(count, j - i + 1);			//更新计数器count
			j++;
		}
		i++;		//i右移一位
	}
	printf("%d\n", count);			//输出结果
	return 0;
}
