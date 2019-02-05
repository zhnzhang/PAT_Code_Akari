//example
//月饼库存量和总售价可以是浮点数(题目中只说是正数，没说是正整数)，需要用double型存储
//总需求量D虽然题目说是正整数，但为了计算方便，也需要定义为浮点型，很多得到"答案错误"的代码都错在这里
//当月饼库存量高于需求量时，不能先令需求量为0，然后再计算收益，这会导致该步收益为0
//当月饼库存量高于需求量时，要记得将循环中断，否则会出错
#include <cstdio>
#include <algorithm>
using namespace std;
struct mooncake {
	double store;		//库存量
	double sell;		//总售价
	double price;		//单价
} cake[1010];

bool cmp(mooncake a, mooncake b) {	//按单价从高到低排序
	return a.price > b.price;
}

int main() {
	int n;
	double D;
	scanf("%d%lf", &n, &D);
	for(int i = 0; i < n; i++) {
		scanf("%lf", &cake[i].store);
	}
	for(int i = 0; i < n; i++) {
		scanf("%lf", &cake[i].sell);
		cake[i].price = cake[i].sell / cake[i].store;		//计算单价
	}
	sort(cake, cake + n, cmp);		//先按单价从高到低排序
	double ans = 0;		//收益
	for(int i = 0; i < n; i++) {
		if(cake[i].store <= D) {	//如果需求量高于月饼库存量
			D -= cake[i].store;		//第i种月饼全部卖出
			ans += cake[i].sell;
		}
		else {		//如果月饼库存量高于需求量
			ans += cake[i].price * D;	//只卖出剩余需求量的月饼
			break;
		}
	}
	printf("%.2f\n", ans);
	return 0;
}
