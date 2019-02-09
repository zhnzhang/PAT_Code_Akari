//我先提个还没弄明白的
typedef long long LL;
//radix指的是进制数
//Map是将字符转化为数值的数组
//例a[] = "1101"
//重点是这个for循环从a[]从左到右枚举，且主要逻辑在ans = ans * radix + Map[a[i]]这句上
LL convertNum10(char a[], LL radix, LL t) {		//将a转换为十进制，t为上界
	LL ans = 0;
	int len = strlen(a);
	for(int i = 0; i < len; i++) {
		ans = ans * radix + Map[a[i]];		//进制转换(这个转换逻辑是啥样的)
		if(ans < 0 || ans > t)
			return -1;			//溢出或超过N1的十进制
	}
	return ans;
}
