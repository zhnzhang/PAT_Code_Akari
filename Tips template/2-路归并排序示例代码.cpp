//2-路归并排序核心在于如何将两个有序序列合并为一个有序序列

//递归实现
const int maxn = 100;
//将数组A的[L1, R1]与[L2, R2]区间合并为有序区间(此处L2即为R1 + 1)
void merge(int A[], int L1, int R1, int L2, int R2) {
	int i = L1, j = L2;		//i指向A[L1], j指向A[L2]
	int temp[maxn], index = 0;	//temp临时存放合并后的数组，index为其下标
	while(i <= R1 && j <= R2) {
		if(A[i] <= A[j]) {		//如果A[i] <= A[j]
			temp[index++] = A[i++];		//将A[i]加入序列temp
		}
		else {
			temp[index++] = A[j++];		//将A[j]加入序列temp
		}
	}
	while(i <= R1) {
		temp[index++] = A[i++];		//将[L1, R1]的剩余元素加入序列temp
	}
	while(j <= R2) {
		temp[index++] = A[j++];		//将[L2, R2]的剩余元素加入序列temp
	}
	for(int i = 0; i < index; i++) {
		A[L1 + i] = temp[i];		//将合并后的序列赋值回数组A
	}
}

//将array数组当前区间[left, right]进行归并排序
void mergeSort(int A[], int left, int right) {
	if(left < right) {		//只要left小于right(这貌似是递归边界)
		int mid = (left + right) / 2;	//取[left, right]的中点
		mergeSort(A, left, mid);		//递归，将左子区间[left, mid]归并排序
		mergeSort(A, mid + 1, right);	//递归，将右子区间[mid + 1, right]归并排序
		merge(A, left, mid, mid + 1, right);	//将左子区间和右子区间合并
	}
}

//非递归实现(这里选择数组下标从1开始)
//每次分组时组内元素个数上限都是2的幂次
//令步长step的初值为2，然后将数组中每step个元素作为一组，将其内部进行排序(即把左step / 2个元素与右step / 2个元素合并，而若元素个数不超过step / 2，则不操作)
//再令step乘以2，重复上面的操作，直到step / 2超过元素个数n(结合代码想想为什么此处是step / 2)
//另外数组下标也可以从0开始，但要修改下方代码的某些部位的参数
void mergeSort(int A[]) {
	//step为组内元素个数，step / 2为左子区间元素个数，  注意 等号可以不取(这个等号可以不取指的是step / 2 <= n里的等号吗)
	for(int step = 2; step / 2 <= n; step *= 2) {
		//每step个元素一组，组内前step / 2和后step / 2个元素进行合并
		for(int i = 1; i <= n; i += step) {		//对每一组
			int mid = i + step / 2 - 1;			//左子区间元素个数为step / 2
			if(mid + 1 <= n) {		//右子区间存在元素则合并
				//左子区间为[i, mid],右子区间为[mid + 1, min(i + step - 1, n)]
				merge(A, i, mid, mid + 1, min(i + step - 1, n));
			}
		}
	}
}

//当然，如果题目中只要求给出归并排序每一趟结束时的序列，那么完全可以使用sort函数来代替merge函数(只要时间限制允许)
//(这属于只看结果不追究过程了？)
void mergeSort(int A[]) {
	//step为组内元素个数，step / 2为左子区间元素个数，注意等号可以不取(这个等号可以不取指的是step / 2 <= n里的等号吗)
	for(int step = 2; step / 2 <= n; step *= 2) {
		//每step个元素一组，组内[i, min(i + step, n + 1))进行排序 (左闭右开)
		for(int i = 1; i <= n; i += step) {
			sort(A + i, A + min(i + step, n + 1));	(注意sort的第二个参数填写的是...的下一个地址)
		}
		//此处可以输出归并排序的某一趟结束的序列
	}
}
