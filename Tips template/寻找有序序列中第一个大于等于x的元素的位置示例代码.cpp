//A[]为递增序列，x为欲查询的数，函数返回第一个大于等于x的元素的位置
//二分上下界为左闭右闭的[left, right]，传入的初值为[0, n]
int lower_bound(int A[], int left, int right, int x) {
	int mid;		//mid为left和right的中点
	while(left < right) {	//对[left, right]来说，left == right意味着找到唯一位置
		mid = left + (right - left) / 2;		//取中点
		if(A[mid] >= x) {		//中间的数大于等于x
			right = mid;		//往左子区间[left, mid]查找
		}
		else {					//中间的数小于x
			left = mid + 1;		//往右子区间[mid + 1, right]查找
		}
	}
	return left;	//返回夹出来的位置
}
