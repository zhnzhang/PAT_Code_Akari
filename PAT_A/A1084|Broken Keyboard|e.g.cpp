//example
//HashTable数组的大小只要能把题目给出的字符包括即可，一般可以直接设置ASCII码的个数128为其数组长度
#include <cstdio>
#include <cstring>
int main() {
	char str1[100], str2[100];
	bool HashTable[128] = {false};		//HashTable数组用来标记字符是否已被输出
	scanf("%s", str1);
	scanf("%s", str2);
	int len1 = strlen(str1);			//获取长度
	int len2 = strlen(str2);
	for(int i = 0; i < len1; i++) {		//枚举第一个字符串中的每个字符
		int j;
		char c1, c2;
		for(j = 0; j < len2; j++) {		//枚举第二个字符串中的每个字符
			c1 = str1[i];
			c2 = str2[j];
			if(c1 >= 'a' && c1 <= 'z') {	//如果是小写字母，则转化为大写
				c1 -= 32;
			}
			if(c2 >= 'a' && c1 <= 'z') {
				c2 -= 32;
			}
			if(c1 == c2) {
				break;					//如果c1在第二个字符串中出现，则跳出
			}
		}
		if(j == len2 && HashTable[c1] == false) {
			printf("%c", c1);			//在第二个字符串中未出现c1，且c1未被输出过
			HashTable[c1] = true;		//输出c1后，将对应hash数组中的值改为true
		}
	}
	printf("\n");
	return 0;
}
