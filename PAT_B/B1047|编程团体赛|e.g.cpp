//example
//注意求最值时变量MAX的初值设置得是小于0的以符合程序逻辑
#include <cstdio>
const int maxn = 1010;
int hashTable[maxn] = {0};			//每个队伍的总分
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int team, member, score;		//队伍编号、队员编号及得分
		scanf("%d-%d %d", &team, &member, &score);
		hashTable[team] += score;		//令编号为team的队伍的分数加上score
	}
	int k, MAX = -1;		//熟悉这类初值设定，求最大值或求最小值的存放最值的变量的初值设定以符合程序逻辑
	for(int i = 0; i < maxn; i++) {		//找hashTable数组的最大值
		if(hashTable[i] > MAX) {
			k = i;
			MAX = hashTable[i];
		}
	}
	printf("%d %d\n", k, MAX);			//输出结果
	return 0;
}
