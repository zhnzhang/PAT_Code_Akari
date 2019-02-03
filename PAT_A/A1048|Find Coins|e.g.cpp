//example
//本题可以使用散列法、二分查找及two pointers方法解决，本次使用散列法
//以int型HashTable[]数组存放每个数字出现的个数，其中HashTable[i]表示数字i出现的次数(1 <= i <= 10^3)
//枚举1~m中的每一个数字i，若i存在于数列(即HashTable[i] > 0)且m - i存在于数列(HashTable[m - i])
//则找到了一对数i与m - i，它们的和为m
//但要注意当i == m - i 时，必须保证数字i的个数大于等于2，因为这就相当于需要两个自己，否则是不行的
//散列表的大小其实不需要开10^5那么大，因为题目中说明了m的范围为10^3以内，所以最多也就会用到10^3大小的数据
//但也不能只开500(数列中数的范围)，因为m - a[i]可能会大于500，这样就会产生"段错误"
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1010;
int HashTable[N] = {0};

int main() {
	int n, m, a;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a);
		HashTable[a]++;
	}
	for(int i = 1; i < m; i++) {		//因为不可能有面额为0的硬币，故循环从1开始，且小于m
		if(HashTable[i] && HashTable[m - i]) {
			if(i == m - i && HashTable[i] < 2) {	//但要注意当i == m - i 时，必须保证数字i的个数大于等于2，因为这就相当于需要两个自己，否则是不行的
				continue;
			}
			printf("%d %d", i, m - i);	//由循环顺序可以保证输出的是v1最小的那一对
			return 0;
		}
	}
	printf("No Solution\n");
	return 0;
}
