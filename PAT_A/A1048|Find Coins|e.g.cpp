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


//example
//对应A1048.Find Coins
//给出二分查找的做法
//使用二分查找法找到m - a[i]时，必须判断其是否就是a[i]，即下标是否相同。
//如果下标相同，则说明找到的其实是同一个位置的数字，应该跳过这种情况(区别于普通做法，这是直接跳过去了？)

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[100010];

//left和right初始分别为0和n - 1，key即m - a[i]
//二分查找函数如下
int Bin(int left, int right, int key) {
	int mid;
	while(left <= right) {
		mid = left + (right - left) / 2;	//取left和right的中点
		if(a[mid] == key) {
			return mid;		//如果找到了key,则返回下标mid
		}
		else if(a[mid] > key) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return -1;		//如果没有找到key，则返回-1
}

int main() {
	int i, n, m;
	scanf("%d%d", &n, &m);
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);		//从小到大排序
	for(i = 0; i < n; i++) {
		int pos = Bin(0, n - 1, m - a[i]);		//寻找m - a[i]
		if(pos != -1 && i != pos) {		//找到
			printf("%d %d\n", a[i], a[pos]);
			break;
		}
	}
	if(i == n) {
		printf("No Solution\n");		//找不到
	}
	return 0;
}
