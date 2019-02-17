//example
//由于数据范围较小，因此归并排序中可以不写合并函数，而直接用sort代替
//这里有个陷阱:初始序列不参与是否与目标序列相同的比较(也就是说，题目中说的中间序列是不包括初始序列的)(初始序列即是没有经过排序的序列)
//不考虑这个陷阱会导致某个数据产生双解。测试数据见算法笔记用书P179
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 111;
int origin[N], tempOri[N], changed[N];		//原始数组，原始数组备份，目标数组
int n;		//元素个数
bool isSame(int A[], int B[]) {			//判断数组A和数组B是否相同
	for(int i = 0; i < n; i++) {
		if(A[i] != B[i]) {
			return false;
		}
	}
	return true;
}

void showArray(int A[]) {			//输出数组
	for(int i = 0; i < n; i++) {
		printf("%d", A[i]);
		if(i < n - 1) {
			printf(" ");
		}
	}
	printf("\n");
}

bool insertSort() {		//插入排序
	bool flag = false;	//记录是否存在数组中间步骤与changed数组相同
	for(int i = 1; i < n; i++) {	//进行n - 1趟排序
		if(i != 1 && isSame(tempOri, changed)) {
			flag = true;		//中间步骤与目标相同，且不是初始序列
		}
		//以下为插入部分
		int temp = tempOri[i], j = i;
		while(j > 0 && tempOri[j - 1] > temp) {
			tempOri[j] = tempOri[j - 1];
			j--;
		}
		tempOri[j] = temp;
		if(flag == true) {
			return true;		//如果flag为true,则说明已达到目标数组，返回true
		}
	}
	return false;		//无法达到目标数组，返回false
}

void mergeSort() {		//归并排序
	bool flag = false;	//记录是否存在数组中间步骤与changed数组相同
	//以下为归并排序部分
	for(int step = 2; step / 2 <= n; step *= 2) {
		if(step != 2 && isSame(tempOri, changed)) {
			flag = true;	//中间步骤与目标相同，且不是初始序列
		}
		for(int i = 0; i < n; i += step) {
			sort(tempOri + i, tempOri + min(i + step, n));
		}
		if(flag == true) {	//已到达目标数组，输出tempOri数组
			showArray(tempOri);
			return;
		}
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &origin[i]);	//输入起始数组
		tempOri[i] = origin[i];		//排序过程在tempOri数组上进行，origin数组算是备份吧(我觉得书上的注释不合适)
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &changed[i]);	//目标数组
	}
	if(insertSort()) {				//如果插入排序中找到目标数组
		printf("Insertion Sort\n");
		showArray(tempOri);
	}
	else {					//到达此处时一定是归并排序
		printf("Merge Sort\n");
		for(int i = 0; i < n; i++) {
			tempOri[i] = origin[i];		//还原tempOri数组，因为在上面调用insertSort()函数后tempOri数组是发生过变化的，为了归并排序进行，需要还原数组
		}
		mergeSort();		//归并排序
	}
	return 0;
}
