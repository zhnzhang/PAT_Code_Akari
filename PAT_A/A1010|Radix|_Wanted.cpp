//example -Wanted
//思路见算法笔记习题册P169，但实话讲，这道题我不太懂
//本题可以使用二分法的点在于:对一个确定的数字串来说，它的进制越大，则将该数字串转换为十进制的结果也就越大
//使用遍历进制的暴力枚举会超时
//将已经确定进制的数放在N1，将未确定进制的数放在N2，以便后面进行统一的计算
//本题的变量尽量使用long long类型。另外，经测试得到，本题中radix的范围最大为INT_MAX，即2^31 - 1，因此必须在计算过程中判断是否溢出
//特别地，数据默认保证已知进制的那个数在转换成十进制时不超过long long(是的，题中并没有提到这一点)
//因此只需要对未知进制的数在转换成十进制时判断是否溢出(只要在转换过程中某步小于0即为溢出)
//特殊情况:当N1和N2数字串相等时，输出题目给定的radix值
//N2进制的下界为所有数位中最大的那个加1，上界为下界与N1的十进制中的较大值加1(这里假设已知的是N1的进制才这么说)(实话讲我对这里上界的界定没搞懂)
//我猜既然radix可达到INT_MAX,那要寻找的进制范围应该不止于表象上的三十六进制，所以上界才要取下界与N1的十进制中的较大值吧，大概因为二分过程中还是要跟N1的十进制进行比较所以拿N1的十进制参与上界的界定吧？这只是我的猜测

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
LL Map[256];			//0~9、a~z与0~35的对应
LL inf = (1LL << 63) - 1;	//long long 的最大值2^63 - 1，注意加括号(这种是什么表示法?)

void init() {
	for(char c = '0'; c <= '9'; c++) {
		Map[c] = c - '0';	//将'0'~'9'映射到0~9
	}
	for(char c = 'a'; c <= 'z'; c++) {
		Map[c] = c - 'a' + 10;		//将'a'~'z'映射到10~35
	}
}

LL convertNum10(char a[], LL radix, LL t) {		//将a转换为十进制，t为上界
	LL ans = 0;
	int len = strlen(a);
	for(int i = 0; i < len; i++) {
		ans = ans * radix + Map[a[i]];		//进制转换(这个转换逻辑是啥样的，我只看出来这是往十进制转的)
		if(ans < 0 || ans > t)
			return -1;			//溢出或超过N1的十进制
	}
	return ans;
}

int cmp(char N2[], LL radix, LL t) {		//N2的十进制与t比较
	int len = strlen(N2);
	LL num = convertNum10(N2, radix, t);	//将N2转换为十进制
	if(num < 0) {
		return 1;		//溢出，肯定是N2 > t
	}
	if(t > num) {
		return -1;		//t较大，返回-1
	}
	else if(t == num) {
		return 0;		//相等，返回0
	}
	else {
		return 1;		//num较大，返回1
	}
}

LL binarySearch(char N2[], LL left, LL right, LL t) {		//二分求解N2的进制
	LL mid;
	while(left <= right) {
		mid = (left + right) / 2;
		int flag = cmp(N2, mid, t);		//判断N2转换为十进制后与t比较
		if(flag == 0) {
			return mid;			//找到解，返回mid
		}
		else if(flag == -1) {
			left = mid + 1;	//往右子区间继续查找
		}
		else {
			right = mid - 1;	//往左子区间继续查找
		}
	}
	return -1;		//解不存在
}

int findLargestDigit(char N2[]) {		//求最大的数位，实际是返回进制数的下界
	int ans = -1, len = strlen(N2);
	for(int i = 0; i < len; i++) {
		if(Map[N2[i]] > ans) {
			ans = Map[N2[i]];
		}
	}
	return ans + 1;		//最大的数位式ans，说明进制数的底线是ans + 1
}

char N1[20], N2[20], temp[20];		//将已经确定进制的数放在N1，将未确定进制的数放在N2，以便后面进行统一的计算
int tag, radix;
int main() {
	init();
	scanf("%s %s %d %d", N1, N2, &tag, &radix);
	if(tag == 2) {		//交换N1和N2(根据上述N1N2的摆放自规定，这里要做一下适配处理)
		strcpy(temp, N1);
		strcpy(N1, N2);
		strcpy(N2, temp);
	}
	LL t = convertNum10(N1, radix, inf);		//将N1从radix进制转换为十进制
	LL low = findLargestDigit(N2);			//找到N2中数位最大的位加1，当成二分下界
	LL high = max(low, t) + 1;				//上界为下界与N1的十进制中的较大值加1(不太懂为啥这样界定上界)
	LL ans = binarySearch(N2, low, high, t);	//二分
	if(ans == -1) {
		printf("Impossible\n");
	}
	else {
		printf("%lld\n", ans);
	}
	return 0;
}
