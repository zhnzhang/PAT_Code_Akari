//example
//题目中指的是十进制的1的个数，而不是二进制的
//题目中给出的范围是1 <= N <= 2^30，所以尽量测一下边界数据，这是做任何题都要学会的
//像PAT这种单点测试，每个数据点都会有分，而边界数据又是考验思维缜密程度的绝好利器
//所以数据里都会设置些边界数据，想要完全正确，就必须考虑这些边界情况
//设当前处理至第k位，那么记left为第k位的高位所表示的数，now为第k位的数，right为第k位的低位所表示的数

#include <cstdio>
int main() {
	int n, a = 1, ans = 0;		//控制一个a，每次乘10表示进一位
	int left, now, right;
	scanf("%d", &n);
	while(n / a != 0) {
		left = n / (a * 10);
		now = n / a % 10;
		right = n % a;
		if(now == 0) ans += left * a;
		else if(now == 1) ans += left * a + right + 1;
		else ans += (left + 1) * a;
		a *= 10;
	}
	printf("%d\n", ans);
	return 0;
}
