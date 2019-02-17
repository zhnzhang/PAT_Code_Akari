//example
//这道题记录来自柳婼的代码，算法笔记给的代码最后一个测试点会内存超限
//count计数当前的位置数
//但代码书写风格仍按照算法笔记来，因为我看柳婼的代码书写风格也和算法笔记的差不多，如下这个应该只是特例或者随意写了吧
#include <iostream>
using namespace std;
int k[200005];
int main(){
    int n, m, temp, count = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &k[i]);
    k[n + 1] = 0x7fffffff;
    cin >> m;
    int midpos = (n + m + 1) / 2, i = 1;		//经模拟可知这里midpos = (n + m + 1) / 2 合适
    for (int j = 1; j <= m; j++) {
        scanf("%d", &temp);
        while (k[i] < temp) {
            count++;
            if (count == midpos) cout << k[i];
            i++;
        }
        count++;
        if (count == midpos) cout << temp;
    }
    while (i <= n) {
        count++;
        if (count == midpos) cout << k[i];
        i++;
    }
    return 0;
}





//算法笔记给出的这道题的解法如下，但它最后一个测试点会内存超限，改用柳婼的解法可AC
//为了使代码更加简练，不妨令两个序列的最后都添加一个很大的数INF(本题为int类型的最大值)
//这样在two pointers的扫描过程中，就可以在其中一个序列已经扫描完但count还没到中位数的情况下解决访问越界的问题
//这样做的可行性是因为每次填入新序列的数都是原序列两个中的较小的那个
//最后需要选择S1[i]和S2[j]的较小值输出的原因是，当count达到中位数的位置时，在while循环中还没有对S1[i]和S2[j]的大小进行判断
//使用cin和cout会超时，请使用scanf和printf(不一定，见柳婼的代码就没超时)

#include <cstdio>
const int maxn = 1000010;		//序列最大长度
const int INF = 0x7fffffff;		//int上限，本题设成10^7也能过
int S1[maxn], S2[maxn];			//两个递增序列

int main() {
	int n, m;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &S1[i]);		//输入第一个序列
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
		scanf("%d", &S2[i]);		//输入第二个序列
	}
	S1[n] = S2[m] = INF;			//两个序列的最后一个元素设为int上限
	int medianPos = (n + m - 1) / 2;	//medianPos为中间位置
	int i = 0, j = 0, count = 0;	//count计数当前的位置数
	while(count < medianPos) {		//只要count未达到medianPos,就继续循环
		if(S1[i] < S2[j]) {
			i++;				//S1[i]更小，则选择S1[i]
		}
		else {
			j++;		//S2[j]更小，则选择S2[j]
		}
		count++;		//count加1
	}
	if(S1[i] < S2[j]) {	//输出两个序列当前位置较小的元素
		printf("%d\n", S1[i]);
	}
	else {
		printf("%d\n", S2[j]);
	}
	return 0;
}
