//example
//本题特点是上档键
//第一个字符串中的所有字母均为大写，因此为了统一写法，均先转换为小写字母
//第二个字符串中出现大写字母时，必须保证其小写字母的键位与上档键"+"同时完好才能进行输出
//并且应当输出大写字母
//由于PAT不能用gets()，换用scanf的话，第三组数据会部分正确，总分仅为19，换用fgets()后可AC
#include <cstdio>
#include <cstring>
const int maxn = 100010;
bool hashTable[256];		//散列数组，用以记录键盘上的字符是否完好，在这里直接初始化需要注意，同赋false不同，直接赋true只能让首个值为true，而赋false则全是false
char str[maxn];				//故布尔数组hash表的初始化为全true利用到了memset

int main() {
	memset(hashTable, true, sizeof(hashTable));		//初值为true表示所有键都完好
	fgets(str, maxn, stdin);		//读入所有失效的键位
	int len = strlen(str);
	if(str[len - 1] == '\n') {
		str[len - 1] = '\0';
	}
	for(int i = 0; i < len; i++) {
		if(str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] - 'A' + 'a';			//如果是大写字母，则化为小写字母
		}
		hashTable[str[i]] = false;					//设置键str[i]失效
	}
	fgets(str, maxn, stdin);		//读入欲输出的字符串
	len = strlen(str);
	if(str[len - 1] == '\n') {
		str[len - 1] = '\0';
	}
	for(int i = 0; i < len; i++) {
		if(str[i] >= 'A' && str[i] <= 'Z') {
			int low = str[i] - 'A' + 'a';			//如果是大写字母，则化为小写字母，赋给临时变量low
			if(hashTable[low] == true && hashTable['+'] == true) {
				printf("%c", str[i]);				//只有小写字母的键位与上档键均完好，才能进行大写字母的输出
			}
		}
		else if(hashTable[str[i]] == true) {
			printf("%c", str[i]);					//对于其他字符，只要键位完好，即输出
		}
	}
	printf("\n");
	return 0;
}
