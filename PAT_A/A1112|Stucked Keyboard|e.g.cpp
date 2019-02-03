//example
//关注点是k的整数倍
//设置数组isStuck，其中isStuck[c]为0时表示键位c有可能是坏的，isStuck[c]为1表示键位c一定是好的
//isStuck[c]为-1时表示键位c是已输出的坏键,isStuck数组将初始化为全0，表示初始状态下每个键位都可能是坏的
//要多次遍历输入的字符串
//坏键的输出顺序是其在字符串中的出现顺序，而非字典序
//最后一步是输出还原的字符串，遍历输入的字符串，如果当前键位的isStuck值为-1，则说明该键位是上一步已输出的坏键
//因此此处只输出一次，然后将下标增加k，以跳过重复部分;否则说明该键位是好键，在输出一次后将下标加1
#include <cstdio>
#include <cstring>
const int maxn = 1010;		//字符串长度上限
const int maxm = 128;		//ASCII码上限
char str[maxn];				//输入的字符串
//K为重复的次数，len为字符串长度, isStuck数组记录键位好坏(-1为已输出的坏键，0为可能坏，1为好)
int K, len, isStuck[maxm] = {0};

void judgeStuck() {			//judgeStuck函数判断每个键位是否可能是坏键
	int i = 0, j = 0;		//i为重复键位左端点，j为重复键位右端点,准确地说j是在最后一个重复键位的下一位
	while(i < len) {
		while(j < len && str[i] == str[j]) {
			j++;			//只要依旧重复就不断右移右端点
		}
		if((j - i) % K != 0) {		//只要重复长度不为K的倍数
			isStuck[str[i]] = 1;	//那么该键位一定是好的
		}
		i = j;		//左端点设置为当前右端点，其实就是进行下一连串的数字的处理
	}
}

int main() {
	scanf("%d%s", &K, str);		//输入重复次数和字符串本身
	len = strlen(str);			//字符串长度
	judgeStuck();			//判断每个键位是否可能是坏键
	for(int i = 0; i < len; i++) {
		if(isStuck[str[i]] == 0) {		//如果该键位可能是坏的
			printf("%c", str[i]);		//输出该键位
			isStuck[str[i]] = -1;		//标记该键位为已输出的坏键
		}
	}
	printf("\n");		//换行
	for(int i = 0; i < len;) {			//最后要输出还原的字符串，由于程序逻辑，要在循环参数上做文章
		printf("%c", str[i]);			//输出当前键位
		if(isStuck[str[i]] == -1) {		//如果当前键位是之前输出的坏键
			i += K;				//剩下的连续重复部分不重复输出，直接跳过去
		}
		else {
			i++;				//继续下一键位的输出
		}
	}
	return 0;
}
