//先看划分，对划分的实现会有很多方案，下面 提供一种速度最快的做法，思想就是two pointers
//其中用以划分区间的元素A[left]被称为主元
//对区间[left, right]进行划分
int Partition(int A[], int left, int right) {
	int temp = A[left];		//将A[left]存放至临时变量temp
	while(left < right) {	//只要left与right不相遇
		while(left < right && A[right] > temp) {
			right--;		//反复左移right
		}
		A[left] = A[right];	//将A[right]挪到A[left]
		while(left < right && A[left] <= temp) {
			left++;			//反复右移left
		}
		A[right] = A[left];	//将A[left]挪到A[right]
	}
	A[left] = temp;		//把temp放到left与right相遇的地方
	return left;		//返回相遇的下标
}

//快速排序的递归实现
//快速排序，left与right初值为序列首尾下标(例如1与n)
void quickSort(int A[], int left, int right) {
	if(left < right) {	//当前区间的长度超过1
		//[left, right]按A[left]一分为二
		int pos = Partition(A, left, right);
		quickSort(A, left, pos - 1);	//对左子区间递归进行快速排序
		quickSort(A, pos + 1, right);	//对右子区间递归进行快速排序
	}
}

//rand()函数只能生成[0, RAND_MAX]范围内的整数(RAND_MAX是stdlib.h中的一个常数，在不同系统环境中，该常数的值有所不同，本书中使用的是32767)
//因此如果想要输出给定范围[a, b]内的随机数，需要使用rand()%(b-a+1) + a   显然rand()%(b-a+1)的范围是[0, b-a], 再加上a之后就是[a, b]
//下面的代码就可以生成[0, 1]与[3, 7]范围内的随机数:
//这种做法只对左右端点相差不超过RAND_MAX的区间的随机数有效
#include <cstdio>
#include <cstdlib>		//***
#include <ctime>		//***
int main() {
	srand((unsigned)time(NULL));		//这个语句将生成随机数的种子, srand是初始化随机种子用的
	for(int i = 0; i < 10; i++) {
		printf("%d ", rand() % 2);		//[0, 1]   需要使用随机数的地方使用rand()函数
	}
	printf("\n");
	for(int i = 0; i < 10; i++) {
		printf("%d ", rand() % 5 + 3);	//[3, 7]
	}
	return 0;
}

//如果需要生成超过RAND_MAX的数，有很多方法，比如
//多次生成rand随机数，然后用位运算拼接起来，或者直接把两个rand随机数相乘，也可以随机选每一个数位的值(0~9)，然后拼接成一个大整数
//还有另一种思路:先用rand()生成一个[0, RAND_MAX]范围内的随机数，然后用这个随机数除以RAND_MAX，这样就会得到一个[0, 1]范围内的浮点数(看作比例系数)
//我们只需要用这个浮点数(比例系数)乘以(b - a)，再加上a即可，即 (int)(round((1.0 * rand() / RAND_MAX) * (b - a) + a)), 相当于这个浮点数就是[a, b]范围内的比例位置
//其实我觉得第二个思路就是借着随机数，随机生成一个比例系数，注意这个比例系数是浮点数，随后就可以自己控制随机生成的数的大小了
//下面是一个生成[10000, 60000]范围内随机数的示例:
#include <cstdio>
#include <cstdlib>
#include <ctime>
int main() {
	srand((unsigned)time(NULL));
	for(int i = 0; i < 10; i++) {	//[10000, 60000]
		printf("%d ", (int)(round(1.0 * rand() / RAND_MAX * 50000 + 10000));
	}
	return 0;
}

//在此基础上继续讨论随机快排的写法，由于现在需要在A[left...right]中随机选取一个主元，因此不妨生成一个范围在[left, right]内的随机数p，然后以A[p]作为主元来进行划分
//具体做法就是：首先随机选取一个主元A[p]，(p是范围在[left, right]内的随机数)，将A[p]与A[left]交换，然后按原先Partition函数的写法即可
//randPartition函数只需要在Partition函数的最前面加上两句话即可，显然quickSort函数的逻辑不需要进行任何改变
//代码如下

//选取随机主元，对区间[left, right]进行划分
int randPartition(int A[], int left, int right) {
	//生成[left, right]内的随机数p
	int p = (round(1.0 * rand() / RAND_MAX * (right - left) + left);
	swap(A[p], A[left]);		//交换A[p]和A[left]
	//以下为原先Partition函数的划分过程，不需要改变任何东西
	int temp = A[left];			//A[left]存放至临时变量temp
	while(left < right) {		//只要left与right不相遇
		while(left < right && A[right] > temp) {
			right--;			//反复左移right
		}
		A[left] = A[right];		//将A[right]挪到A[left]
		while(left < right && A[left] <= temp) {
			left++;				//反复右移left
		}
		A[right] = A[left];		//将A[left]挪到A[right]
	}
	A[left] = temp;			//把temp放到left与right相遇的地方
	return left;			//返回相遇的下标
}
