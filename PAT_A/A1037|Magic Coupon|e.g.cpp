//example
//贪心算法都需要对策略进行证明，而且我感觉基本也都涉及到先排序
//题目要求的是只追求乘积之和的最大值，并不规定这个相同数量具体是多少对吧?
//具体实现中，可以不单独拆开正数和负数，而对整个集合进行从小到大的排序，这样绝对值最大的负数就在数组最左侧，绝对值最大的正数就在数组最右侧
//然后从左到右进行负数乘积的累加，从右到左进行正数乘积的累加，即可得到结果
//代码要能处理正数和负数个数不相同且有0的情况
//在进行排序后取两个集合的最大正数时，应当是分别取位置n - 1与m - 1,而不是它们的最小值min{n - 1, m - 1}
//在累加的循环中，不能以coupon[i] * product[i] > 0(处理负数时)或coupon[i] * product[j] > 0(处理正数时)作为判断条件，因为会在两个集合正数个数相等、负数个数相等时发生错误
//题目中"it is guaranteed that all the numbers will not exceed 2^30"的表述应当包括了乘积之和不超过2^30的含义
//因为数据中没有超过int的计算结果，但为了保险起见，可以令结果的数据类型为long long，以免越界

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int coupon[maxn], product[maxn];

int main() {
	int n, m;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &coupon[i]);
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
		scanf("%d", &product[i]);
	}
	sort(coupon, coupon + n);		//从小到大排序
	sort(product, product + m);		//从小到大排序
	//下面要设置数组指针了，具体计算过程见上面注释
	//计算负数那部分
	int i = 0, j;
	long long ans = 0;			//ans存放乘积之和
	while(i < n && i < m && coupon[i] < 0 && product[i] < 0) {
		ans += coupon[i] * product[i];	//当前位置均小于0时，累加乘积
		i++;
	}
	//计算正数那部分
	i = n - 1;
	j = m - 1;		//设置好数组指针初值
	while(i >= 0 && j >= 0 && coupon[i] > 0 && product[j] > 0) {
		ans += coupon[i] * product[j];	//当前位置均大于0时，累加乘积
		i--;
		j--;
	}
	printf("%d\n", ans);
	return 0;
}
