//example
//读入第二串珠子后，对其中每颗珠子的颜色，令hashTable数组对应颜色的个数减1.如果该颜色的个数小于0，那么说明缺少一颗该颜色的珠子，令miss加1
//对于输出YES的情况，只要把两个串的长度相减即可得到富余的珠子个数，不需要进行统计
//怪了 这道题就需要改为scanf(),用fgets()反而最后一组数据部分正确
#include <cstdio>
#include <cstring>
const int maxn = 1010;
//hashTable记录第一串中每种颜色的个数，用miss记录缺少的珠子个数
int hashTable[80] = {0}, miss = 0;			//由于颜色由数字、大小写字母组成，共有62种颜色，因此数组大小相应的进行设置
//将数字和字母转换为hashTable的下标
int change(char c) {
	if(c >= '0' && c <= '9') {
		return c - '0';			//数字
	}
	else if(c >= 'a' && c <= 'z') {
		return c - 'a' + 10;	//小写字母
	}
	else if(c >= 'A' && c <= 'Z') {
		return c - 'A' + 36;	//大写字母
	}
}

int main() {
	char whole[maxn], target[maxn];
	scanf("%s", whole);
	scanf("%s", target);
	int len1 = strlen(whole);
	int len2 = strlen(target);
	for(int i = 0; i < len1; i++) {		//遍历第一串
		int id = change(whole[i]);		//字符->hashTable下标
		hashTable[id]++;				//该颜色个数加1
	}
	for(int i = 0; i < len2; i++) {		//遍历第二串
		int id = change(target[i]);		//字符->hashTable下标
		hashTable[id]--;				//该颜色个数减1
		if(hashTable[id] < 0) {			//该颜色个数小于0
			miss++;						//缺少的珠子个数加1
		}
	}
	if(miss > 0) {
		printf("No %d", miss);			//有缺少
	}
	else {
		printf("Yes %d", len1 - len2);	//有多余
	}
	return 0;
}
