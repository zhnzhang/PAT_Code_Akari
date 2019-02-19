//example
//本题由于数据范围较小，使用配套教材上rand函数版本的快速选择算法会有数据点超时，建议使用参考代码中nth_element函数版本的做法
//这道题来自扫码，但在教材上被当例题讲解，思路见书P149

//直接排序
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int n, a[maxn];		//数组a存放所有整数，n为其个数
int main() {
	int sum = 0, sum1 = 0;		//sum为所有元素的和，sum1为前n / 2小的元素之和
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];	//累计sum
	}
	sort(a, a + n);		//从小到大排序
	for(int i = 0; i < n / 2; i++) {
		sum1 += a[i];		//累计前n / 2小的元素之和
	}
	printf("%d %d\n", n % 2, (sum - sum1) - sum1);	//输出|n1 - n2|和|S2 - S1|
	return 0;
}

//快速选择算法(nth_element函数版)
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int n, a[maxn];		//数组a存放所有整数，n为其个数
int main() {
	//sum和sum1记录所有整数之和与切分后前n / 2个元素之和
	int sum = 0, sum1 = 0;
	scanf("%d", &n);	//整数个数
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);		//输入整数
		sum += a[i];			//累计所有整数之和
	}
	nth_element(a, a + n / 2, a + n);	//寻找第n / 2大的数，并进行切分
	for(int i = 0; i < n / 2; i++) {
		sum1 += a[i];		//累计较小的子集合中元素之和
	}
	printf("%d %d\n", n % 2, (sum - sum1) - sum1);		//求两个子集合的元素和之差
	return 0;
}
