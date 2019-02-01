//example
#include <cstdio>
int hashTable[110] = {0};		//记录每个分数出现的次数
int main() {
	int n, score, k;
	scanf("%d", &n);			//学生数
	for(int i = 0; i < n; i++) {
		scanf("%d", &score);	//分数
		hashTable[score]++;		//分数score出现的次数加1
	}
	scanf("%d", &k);			//查询次数
	for(int i = 0; i < k; i++) {
		scanf("%d", &score);
		printf("%d", hashTable[score]);
		if(i < k - 1) {
			printf(" ");
		}
	}
	return 0;
}
