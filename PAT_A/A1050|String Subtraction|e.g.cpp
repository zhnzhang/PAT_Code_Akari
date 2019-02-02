//example
//虽然说是"删去"，但是实际操作时可以用散列的思想使问题的解决更容易
//通过设置bool数组HashTable[128]表示字符是否在第二个字符串中出现
//来对第一个字符串中不能输出的字符进行控制
//本题不能使用scanf，因为它会以空格为截断标志，不适合读取一整行的字符串
#include <cstdio>
#include <cstring>
const int MAX_LEN = 10010;
char str1[MAX_LEN], str2[MAX_LEN];
bool HashTable[128] = {false};			//记录字符是否在第二个字符串里出现过,数组大小设置为128,主要是考虑到ASCII码的数量

int main() {
	fgets(str1, MAX_LEN, stdin);
	int len1 = strlen(str1);			//strlen必须在for循环之前就计算
	if(str1[len1 - 1] == '\n') {
		str1[len1 - 1] = '\0';
	}
	fgets(str2, MAX_LEN, stdin);
	int len2 = strlen(str2);
	if(str2[len2 - 1] == '\n') {
		str2[len2 - 1] = '\0';
	}
	for(int i = 0; i < len2; i++) {
		HashTable[str2[i]] = true;		//第二个字符串里的字符的table值置true
	}
	for(int i = 0; i < len1; i++) {
		if(HashTable[str1[i]] == false) {	//如果在第二个字符串中没有出现过
			printf("%c", str1[i]);
		}
	}
	return 0;
}
