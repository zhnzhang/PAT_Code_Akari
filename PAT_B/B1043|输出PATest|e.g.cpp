//example
//直接对原字符串反复循环判断的话会超时
//所以开了一个char型数组dict，存放6个字符，下标与hashTable对应，省得重复写判断
#include <cstdio>
#include <cstring>
const int maxn = 10010;
//字符串、字典
char str[maxn], dict[6] = {'P', 'A', 'T', 'e', 's', 't'};
int hashTable[6] = {0};			//记录PATest这6个字符的个数

int main() {
	fgets(str, maxn, stdin);		//输入字符串
	int len = strlen(str), sum = 0;		//长度、总共需要输出的字符个数
	if(str[len - 1] == '\n') {
		str[len - 1] = '\0';
	}
	for(int i = 0; i < len; i++) {		//str[i]
		for(int j = 0; j < 6; j++) {	//遍历dict字典
			if(str[i] == dict[j]) {		//str[i]在字典中的下标为j
				hashTable[j]++;			//个数加1
				sum++;					//需要输出的字符个数加1
			}
		}
	}
	while(sum > 0) {					//当输出的字符个数变成0时退出
		for(int i = 0; i < 6; i++) {	//遍历hashTable数组,按题目要求顺序输出
			if(hashTable[i] > 0) {		//hashTable[i] > 0则输出
				printf("%c", dict[i]);
				hashTable[i]--;
				sum--;					//需要输出的字符个数减1
			}
		}
	}
	return 0;
}
