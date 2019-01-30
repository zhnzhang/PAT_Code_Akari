//直接把输入的数作为数组的下标来对这个数的性质进行统计，前面有许多题目用到这里的技巧，下面举两个用散列判断数是否存在或存在几个的小例子
#include <cstdio>
const int maxn = 100010;
int hashTable[maxn] = {0};

int main() {
	int n, m, x;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%d", &x);
		hashTable[x]++;
	}
	for(int i = 0; i < m; i++) {
		scanf("%d", &x);
		printf("%d\n", hashTable[x]);
	}
	return 0;
}

#include <cstdio>
const int maxn = 100010;
bool hashTable[maxn] = {false};

int main() {
	int n, m, x;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%d", &x);
		hashTable[x] = true;
	}
	for(int i = 0; i < m; i++) {
		scanf("%d", &x);
		if(hashTable[x]) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}
	return 0;
}
