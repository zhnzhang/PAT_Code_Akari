//解决"寻找有序序列第一个满足某条件的元素的位置"问题的固定模板(左开右闭)
//此模板写法与左闭右闭的写法等价
//写法上作如下改动:此做法下，二分区间是左开右闭区间(left, right]，因此循环条件应当是left + 1 < right,这样当退出循环时有left + 1 == right成立，使得(left, right]才是唯一位置
//由于变成了左开，left的初值要比解的最小取值小1(例如对下标从0开始的序列来说，left和right的取值应为-1和n)，同时语句left = mid + 1应当改为left = mid，并且返回的应当是right而不是left

//二分区间为左开右闭的(left, right]
//初值必须能覆盖解的所有可能取值，并且left比最小取值小1

int solve(int left, int right) {
	int mid;	//mid为left和right的中点
	while(left + 1 < right) {		//对(left, right], left + 1 == right意味着唯一位置
		mid = (left + right) / 2;	//取中点
		//mid = left + (right - left) / 2;
		if( 条件成立 ) {			//条件成立，则第一个满足条件的元素的位置 <= mid
			right = mid;			//往左子区间[left, mid]查找
		}
		else {						//条件不成立，则第一个满足条件的元素的位置 > mid
			left = mid;				//往右子区间[mid, right]查找
		}
	}
	return right;					//返回夹出来的位置
}

//这份模板与左闭右闭是等价的，只是做法稍有区别
