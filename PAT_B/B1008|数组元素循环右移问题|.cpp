//这道题的题设没有限制直接输出，但我这个做法是正统的三次反转使数组循环右移的方法
#include <cstdio>

void Reverse(int a[], int l, int num) {
    int temp;
    for (int i = 0; i < num / 2; i++) {
        temp = a[l + i];
        a[l + i] = a[l + num - 1 - i];
        a[l + num - 1 - i] = temp;
    }
}

int main() {
    int a[110] = {0};
    int n, m;
    scanf("%d%d", &n, &m);
    m = m % n;                                  //易错点，Point1，2的检查点，因为m的大小没说明，所以不要思维定势
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    Reverse(a, 0, n - m);
    Reverse(a, n - m, m);
    Reverse(a, 0, n);
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            printf("%d ", a[i]);
        } else {
            printf("%d", a[i]);
        }
    }
    return 0;
}


#include <cstdio>         //本题的解题思路如下面注释，我是借鉴了CSDN，我本身没想到用一步一步的循环做
int main() {              //temp的设置很好，但我那些一步到位的想法免不了数组的支持->更新:习题集P201就可以将我的思路不用数组就实现。类比希尔排序，运用到一个临时放数据的变量
  int n, m, a[150];       //还是编程的思路不到位，分治的思想缺乏，利用循环这个基本操作分而治之
  scanf("%d%d", &n, &m);
  m %= n;                 //利用模运算修正m(这点容易被忽视)
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  int temp = 0;
  for(int i = 0; i < m; i++) {    //(核心)不允许使用数组，那就利用循环操作分解成一步一步来实现,每次循环右移一位，循环m次
    temp = a[n - 1];
    for(int j = n - 2; j >= 0; j--) {
      a[j + 1] = a[j];
    }
    a[0] = temp;
  }
  for(int i = 0; i < n; i++) {
    printf("%d", a[i]);
    if(i != n - 1) {
      printf(" ");
    }
  }
  return 0;
}


/*
#include <cstdio>         //参考答案的做法显然根据题目提示(最后M个数循环移至最前面的M个位置)来取巧
int main() {              //它并没有实际改变数组中的顺序，而是利用规律直接将对应的顺序输出出来
  int a[110];
  int n, m, count = 0;    //count记录已经输出数的个数
  scanf("%d%d", &n, &m);
  m %= n;                 //修正m(这点容易被忽视)
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for(int i = n - m; i < n; i++) {    //输出n - m号到n - 1号
    printf("%d", a[i]);
    count++;    //已输出数的个数加1
    if(count < n)
      printf(" ");            //如果已经输出数的个数小于n,则输出空格
  }
  for(int i = 0; i < n - m; i++) {    //输出0号到n - m - 1号
    printf("%d", a[i]);
    count++;
    if(count < n)
      printf(" ");
  }
  return 0;
}
*/


//example
//B1008.数组元素循环右移问题
//此处的解法利用最大公约数，让移动的次数最少
//为了避免已经得到结果后的继续枚举，设d为N和M的最大公约数，那么从N - M号位开始枚举起始位(这里的位号都是指从0开始)
//直到N - M + d - 1位结束
//例如N = 8、M = 3时，就只需要从N - M = 5号位开始、直到N - M + d - 1 = 5号位结束，也就是只需要枚举5号位作为起始位即可

#include <cstdio>

int gcd(int a, int b) {		//求a和b的最大公约数
	if(b == 0)	return a;
	else return gcd(b, a % b);
}

int main() {
	int a[110];
	int n, m, temp, pos, next;
	//temp为临时变量，pos存放当前处理的位置，next为下一个要处理的位置
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	m = m % n;		//修正m
	if(m != 0) {		//如果m == 0，直接输出数组即可，不需要执行这部分
		int d = gcd(m, n);		//d为m和n的最大公约数
		for(int i = n - m; i < n - m + d; i++) {	//枚举一个最大公约数的范围
			temp = a[i];		//把当前位置元素先拿走
			pos = i;		//记录当前要处理的位置
			do {
				//计算下一个要处理的位置
				next = (pos - m + n) % n;		//考虑到循环所以这样写
				//如果下一个位置不是初始点
				//则把下一个位置的元素赋值给当前处理位置
				if(next != i) a[pos] = a[next];
				else a[pos] = temp;	//把一开始拿走的元素赋值给最后这个空位
				pos = next;		//传递位置
			} while(pos != i);		//循环直至当前处理位置回到初始位置结束
		}
	}
	for(int i = 0; i < n; i++) {	//输出数组
		printf("%d", a[i]);
		if(i < n - 1) printf(" ");
	}
	return 0;
}
