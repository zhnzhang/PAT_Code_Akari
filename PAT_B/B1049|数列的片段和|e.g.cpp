//example
//目的是统计元素个数为n的序列的每一位在不同长度的连续长度中出现的次数之和
//举几个简单的例子，比如分别对n为4、5、6、7的情况，统计每一位的出现次数
//会有明显规律：如果当前是第i个数，那么其总出现次数等于i * (n + 1 - i)
//只要遍历i，然后累计总出现次数即可

#include <cstdio>
int main() {
	int n;
	double v, ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%lf", &v);		//第i位的值为v
		ans += v * i * (n + 1 - i);		//第i位的总出现次数为i * (n + 1 - i)
	}
	printf("%.2f\n", ans);
	return 0;
}
