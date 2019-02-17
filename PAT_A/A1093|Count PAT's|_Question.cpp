//example
//直接暴力会超时，换个角度看，对一个确定位置的A来说，以它形成的PAT的个数等于它左边P的个数乘以它右边T的个数
//用数组记录每一位左边P的个数是含当前位的，下同
//为了节省代码量，不妨在统计每一位右边T的个数的过程中直接计算答案ans
//采用分别遍历P、A、T的位置来统计的方法会超时
//记得取模
//也注意取模的做法(有疑问的不懂的地方)
//本题与PAT B1045/A1101的思路很像，注意认真体会这两道题的思想

#include <cstdio>
#include <cstring>
const int MAXN = 100010;
const int MOD = 1000000007;
char str[MAXN];		//字符串
int leftNumP[MAXN] = {0};	//每一位左边(含当前位)P的个数

int main() {
	scanf("%s", str);		//读入字符串
	int len = strlen(str);	//长度
	for(int i = 0; i < len; i++) {		//从左到右遍历字符串
		if(i > 0) {		//如果不是0号位
			leftNumP[i] = leftNumP[i - 1];		//继承上一位的结果
		}
		if(str[i] == 'P') {		//当前位是P
			leftNumP[i]++;		//令leftNumP[i]加1
		}
	}
	int ans = 0, rightNumT = 0;		//ans为答案，rightNumT记录右边T的个数
	for(int i = len - 1; i >= 0; i--) {		//从右到左遍历字符串
		if(str[i] == 'T') {		//当前位是T
			rightNumT++;		//右边T的个数加1
		}
		else if(str[i] == 'A') {	//当前位是A
			ans = (ans + leftNumP[i] * rightNumT) % MOD;	//累计乘积,每步都取模，而不是最后一块取模(区别在哪...为什么最后一起取模有的测试点过不去)
		}
	}
	printf("%d\n", ans);		//输出结果
	return 0;
}
