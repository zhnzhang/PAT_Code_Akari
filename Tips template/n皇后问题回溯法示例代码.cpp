//n皇后问题，在全排列的基础上进行,比纯的组合数枚举要来的简练得多
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn = 11;		//修改maxn数值可增加 可计算全排列的位数，目前仅以11为例
//count,表示合法的方案数，P为当前排列，hashTable记录整数x是否已经在P中
int n, count = 0, P[maxn], hashTable[maxn] = {0};
//当前处理排序的第index号位
void generateP(int index) {
	if(index == n + 1) {		//递归边界，生成一个合法方案
		count++;		//能到达这里的一定是合法的
		return;
	}
	for(int x = 1; x <= n; x++) {		//第x行
		if(hashTable[x] == false) {		//第x行还没有皇后
			bool flag = true;			//flag为true表示当前皇后不会和之前的皇后冲突
			for(int pre = 1; pre < index; pre++) {	//遍历之前的皇后
			//第index列皇后的行号为x，第pre列皇后的行号为P[pre]
				if(abs(index - pre) == abs(x - P[pre])) {
					flag = false;			//与之前的皇后在一条对角线，冲突
					break;
				}
			}
			if(flag) {		//如果可以把皇后放在第x行
				P[index] = x;		//令index列皇后的行号为x
				hashTable[x] = true;	//第x行已被占用
				generateP(index + 1);	//递归处理第index + 1行皇后
				hashTable[x] = false;	//递归完毕，还原第x行为未占用
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	generateP(1);			//欲输出n皇后问题的结果
	printf("%d\n", count);
	return 0;
}
