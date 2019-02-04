#include <cstdio>
const int maxn = 11;
//P为当前排列，hashTable记录整数x是否已经在P中
int n, P[maxn], hashTable[maxn] = {0};
//当前处理排序的第index号位
void generateP(int index) {
	if(index == n + 1) {	//递归边界，已经处理完排列的1~n位
		for(int i = 1; i <= n; i++) {
			printf("%d", P[i]);		//输出当前排列
		}
		printf("\n");
		return;
	}
	for(int x = 1; x <= n; x++) {	//枚举1~n，试图将x填入P[index]
		if(hashTable[x] == false) {	//如果x不在P[1]~P[index - 1]中
			P[index] = x;		//令P的第index位为x，即把x加入当前排列
			hashTable[x] = true;	//记x已在P中
			generateP(index + 1);	//处理排序的第index + 1号位
			hashTable[x] = false;	//已处理完P[index]为x的子问题，还原状态
		}
	}
}

int main() {
	scanf("%d", &n);		//欲输出1~n的全排列
	generateP(1);
	return 0;
}
