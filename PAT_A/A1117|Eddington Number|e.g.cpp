//example
//注意到天数和超过的英里数是负相关的
//如果当前位置是E，其骑车距离为miles[E],则说明有E天骑车超过miles[E] - 1英里
//此时如果(miles[E] - 1) >= E成立，那么就会同时满足"至少有E天骑车超过E英里"
//对整个题目来说，我们只需要寻找最大的E，使得E <= miles[E] - 1(也即最后一个满足E < miles[E])成立
//只需要找到第一个满足E >= miles[E]的E，然后输出E - 1即可(因为E的逐1增加的)
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int miles[maxn];			//英里数(这个级别的数组要定义在主函数外面)

bool cmp(int a, int b) {
	return a > b;			//从大到小排序
}

int main() {
	int n;
	scanf("%d", &n);		//输入天数
	for(int i = 1; i <= n; i++) {		//为了程序书写逻辑，下标要从1开始
		scanf("%d", &miles[i]);			//输入英里数(注意下标从1开始)
	}
	sort(miles + 1, miles + 1 + n, cmp);		//将英里数从大到小排序
	int E = 1;				//让E从小到大遍历数组
	while(E <= n && E <= (miles[E] - 1)) {		//因为E初值为1，下标也是从1开始的，故这里写E <= n
		E++;			//找到第一个E >= miles[E]的E
	}
	printf("%d\n", E - 1);		//E - 1即为结果
	return 0;
}
