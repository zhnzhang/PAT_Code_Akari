//0和任意一个整数a的最大公约数都是a(注意，不是0)，这个结论就可以当作递归边界
//递归式：gcd(a, b) = gcd(b, a % b)
//递归边界：gcd(a, 0) = a;
//此次为多点测试写法

#include <cstdio>
//求最大公约数的辗转相除法的递归写法
int gcd(int a, int b) {
	if(b == 0) return a;
	else return gcd(b, a % b);
}

/*
int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}
 */

int main() {
	int m, n;
	while(scanf("%d%d", &m, &n) != EOF) {
		printf("%d\n", gcd(m, n));
	}
	return 0;
}
