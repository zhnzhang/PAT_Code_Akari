//n皇后问题，在全排列的基础上进行,比纯的组合数枚举要来的简练得多
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn = 11;    //修改maxn数值可增加 可计算全排列的位数，目前仅以11为例
//count,表示合法的方案数，P为当前排列，hashTable记录整数x是否已经在P中
int n, count = 0, P[maxn], hashTable[maxn] = {0};
//当前处理排序的第index号位
void generateP(int index) {
	if(index == n + 1) {		//递归边界，生成一个排列
		bool flag = true;		//flag为true表示当前排列为一个合法方案
		for(int i = 1; i <= n; i++) {	//遍历任意两个皇后
			for(int j = i + 1; j <= n; j++) {	//双重for循环，用于判断是否合法
				if(abs(i - j) == abs(P[i] - P[j])) {	//用直角坐标系来解释就是两点横坐标差的绝对值等于纵坐标差的绝对值
					flag = false;		//如果在一条对角线上，判为不合法
				}
			}
		}
		if(flag) {
			count++;		//若当前方案合法，令count加1
		}
		return;
	}
	for(int x = 1; x <= n; x++) {
		if(hashTable[x] == false) {
			P[index] = x;
			hashTable[x] = true;
			generateP(index + 1);
			hashTable[x] = false;
		}
	}
}

int main() {
	scanf("%d", &n);
	generateP(1);			//欲输出n皇后问题的结果
	printf("%d\n", count);
	return 0;
}

