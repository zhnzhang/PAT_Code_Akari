//这里求a^b % m ，对问题本身有两种做法，对% m的运算也有两种做法
//对% m的第一种写法就是先算出a^b本身，再%m
//另一种嵌在下面两种对问题本身解法中，虽然我对这种做法的逻辑还不是很能理解
//但是，我觉得，特别对于这种，数量级比较大的情况下，一般是不推荐求出最终结果后再取模
//而是推荐每步运算都取一次模，可能它们的效果是等价的吧
//但每步运算取一次模或许可以规避数据溢出？

//针对不同的题目，可能有两个细节需要注意:
//1.如果初始时a有可能大于等于m，那么需要在进入函数前就让a对m取模
//2.如果m为1，可以直接在函数外部特判为0，不需要进入函数来计算，因为任何正整数对1取模一定等于0

//第一种常规做法，没用二分幂，这种的时间复杂度为O(b)，在b大了之后不能接受
typedef long long LL;
LLpow(LL a, LL b, LL m) {
	LL ans = 1;
	for(int i = 0; i < b; i++) {
		ans = ans * a % m;
	}
	return ans;
}

//第二种时间复杂度O(logb)，用到快速幂的做法，这里采用快速幂的递归写法
typedef long long LL;
//求a^b % m，递归写法
LL binaryPow(LL a, LL b, LL m) {
	if(b == 0)
		return 1;		//如果b为0，那么a^0 = 1  这里是递归边界
	//b为奇数，转换为 b - 1
	if(b % 2 == 1)
		return a * binaryPow(a, b - 1, m) % m;
	else {		//b为偶数，转换为b / 2
		LL mul = binaryPow(a, b / 2, m);
		return mul * mul % m;
	}
}

//另外还要注意，当b % 2 == 0时，不要直接返回binaryPow(a, b / 2, m) * binaryPow(a, b / 2, m)
//而应当算出单个binaryPow(a, b / 2, m)之后再乘起来
//这是因为前者每次都会调用两个binaryPow函数，导致复杂度变成O(2^(log(b))) = O(b)

//这样的思想或者说做法在其他地方也会体现到，比如以前遇到过的，不要在循环参数设定的时候采用函数调用的写法，而是在之前函数调用后存于每个变量里，把这个变量设为循环参数
//总的来讲就是要规避重复调用，避免不必要的时间复杂度增长

//快速幂的迭代写法
//原理见算法笔记用书P136
typedef long long LL;
//求a^b % m ，迭代写法
LL binaryPow(LL a, LL b, LL m) {
	LL ans = 1;
	while(b > 0) {
		if(b & 1) {		//如果b的二进制末尾位1(也可以写成if(b % 2))
			ans = ans * a % m;		//令ans累积上a
		}
		a = a * a % m;		//令a平方
		b >>= 1;			//将b的二进制右移1位，即 b = b >> 1或者b = b / 2
	}
	return ans;
}

//在实际应用中，递归写法和迭代写法在效率上的差别不那么明显，因此随自己喜欢使用
