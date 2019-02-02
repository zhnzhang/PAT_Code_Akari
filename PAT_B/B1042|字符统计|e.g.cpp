//example
//统计时大小写不区分，核心代码部分的逻辑体现了不区分大小写的做法
//输出时输出对应小写字母(字典序最小的)
//本题换用scanf则部分正确只有第三组数据对，换用fgets可AC
#include <cstdio>
#include <cstring>
const int maxn = 1010;
char str[maxn];			//字符串
int hashTable[30] = {0};	//记录'a(A)' ~ 'z(Z)'的出现次数
int main() {
	fgets(str, maxn, stdin);		//输入字符串
	int len = strlen(str);	//字符串长度
	if(str[len - 1] == '\n') {
		str[len - 1] = '\0';
	}
	for(int i = 0; i < len; i++) {
		if(str[i] >= 'a' && str[i] <= 'z') {	//str[i]是小写字母
			hashTable[str[i] - 'a']++;			//str[i]出现次数加1
		}
		else if(str[i] >= 'A' && str[i] <= 'Z') {	//str[i]是大写字母
			hashTable[str[i] - 'A']++;			//str[i]对应的小写字母出现次数加1
		}
	}
	int k = 0;		//记录数组中最大的元素下标
	for(int i = 0; i < 26; i++) {			//这样按顺序循环其实就顺带满足字典序最小的要求了
		if(hashTable[i] > hashTable[k]) {
			k = i;
		}
	}
	printf("%c %d\n", 'a' + k, hashTable[k]);
	return 0;
}
