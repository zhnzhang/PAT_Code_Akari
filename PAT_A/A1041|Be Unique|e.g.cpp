//example
#include <cstdio>
int a[100010], HashTable[10010] = {0};		//a[]为输入数字，HashTable[]为散列函数
int main() {
	int n;
	scanf("%d", &n);		//n个数
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);		//当前输入的数为a[i]
		HashTable[a[i]]++;		//数字a[i]出现的次数加1
	}
	int ans = -1;			//存放第一次出现的在序列中只有一个的数字
	for(int i = 0; i < n; i++) {
		if(HashTable[a[i]] == 1) {		//如果a[i]只出现了一次
			ans = a[i];				//答案就是a[i]，退出循环
			break;
		}
	}
	if(ans == -1) {
		printf("None");			//找不到只出现一次的数字，输出"None"
	}
	else {
		printf("%d\n", ans);
	}
	return 0;
}
