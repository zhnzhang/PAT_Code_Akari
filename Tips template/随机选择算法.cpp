//随机选择算法，从A[left, right]中返回第K大的数，并进行切分(这里第K大意指K越大，所指的数越大)(从我正常的认知来看，这难道不是第K小吗...第1大才是最大的不是吗...)
//虽然随机选择算法的最坏时间复杂度是O(n^2)，但是其对任意输入的期望时间复杂度却是O(n)，这意味着不存在一组特定的数据能使这个算法出现最坏情况，是个相当实用和出色的算法
//递归写法
int randSelect(int A[], int left, int right, int K) {
	if(left == right) return A[left];		//边界
	int p = randPartition(A, left, right);		//划分后主元的位置为p,应用随机划分
	int M = p - left + 1;	//A[p]是A[left, right]中的第M大
	if(K == M) return A[p];		//找到第K大的数
	if(K < M) {		//第K大的数在主元左侧
		return randSelect(A, left, p - 1, K);	//往主元左侧找第K大
	} else {	//第K大的数在主元右侧
		return randSelect(A, p + 1, right, K - M);	//往主元右侧找第K - M大
	}
}
