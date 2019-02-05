//example
//在距离为0处必须有加油站，否则无法出发，一定无法到达终点
//Cmax、D、Davg、油价、距离都可能是浮点型，不能设置成int型
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 510;
const int INF = 1000000000;
struct station {
	double price, dis;		//油价格、与起点的距离
} st[maxn];

bool cmp(station a, station b) {
	return a.dis < b.dis;	//按距离从小到大排序
}

int main() {
	int n;
	double Cmax, D, Davg;
	scanf("%lf%lf%lf%d", &Cmax, &D, &Davg, &n);
	for(int i = 0; i < n; i++) {
		scanf("%lf%lf", &st[i].price, &st[i].dis);
	}
	st[n].price = 0;		//数组最后面放置终点(也看成一个加油站)，油价为0
	st[n].dis = D;			//终点距离为D
	sort(st, st + n, cmp);	//将所有加油站按距离从小到大排序(没算终点是因为终点距离最远而且已经在最后了)
	if(st[0].dis != 0) {	//如果排序后的第一个加油站距离不是0，说明无法前进
		printf("The maximum travel distance = 0.00\n");
	}
	else {
		int now = 0;		//当前所处的加油站编号
		//总花费、当前油量及满油行驶距离,Tank这里译为油量
		double ans = 0, nowTank = 0, MAX = Cmax * Davg;
		while(now < n) {	//每次循环将选出下一个需要到达的加油站，下面的写法是将策略1和策略2的寻找加油站的过程合在一起
		//选出从当前加油站满油能到达范围内的第一个油价低于当前油价的加油站
			//如果没有低于当前油价的加油站，则选择油价最低的那个
			int k = -1;		//存放最低油价的加油站的编号,注意初值的设置
			double priceMin = INF;		//存放最低油价
			for(int i = now + 1; i <= n && st[i].dis - st[now].dis <= MAX; i++) {	//注意循环初值为now + 1 所考察所讨论的范围为从当前加油站满油能到达范围内
				if(st[i].price < priceMin) {		//如果油价 比 当前最低油价低
					priceMin = st[i].price;			//更新最低油价
					k = i;
					//如果找到第一个油价低于当前油价的加油站，直接中断循环
					if(priceMin < st[now].price) {
						break;
					}
				}
			}
			if(k == -1) {
				break;		//满油状态下无法找到加油站，退出循环输出结果
			}
			//下面为能找到可到达的加油站k，计算转移花费
			//need为从now到k需要的油量
			double need = (st[k].dis - st[now].dis) / Davg;
			if(priceMin < st[now].price) {		//如果加油站k的油价低于当前油价
				//只买足够到达加油站k的油
				if(nowTank < need) {	//如果当前油量不足need
					ans += (need - nowTank) * st[now].price;	//补足need，然后就出发去加油站k
					nowTank = 0;		//到达加油站k后 油箱内油量为0
				}
				else {			//如果当前油量超过need
					nowTank -= need;	//直接到达加油站k
				}
			}
			else {		//如果加油站k的油价高于当前油价
				ans += (Cmax - nowTank) * st[now].price;		//将油箱加满
				//到达加油站k后油箱内油量为Cmax - need
				nowTank = Cmax - need;
			}
			now = k;		//到达加油站k，进入下一层循环
		}
		if(now == n) {		//能到达终点
			printf("%.2f\n", ans);
		}
		else {			//不能到达终点
			printf("The maximum travel distance = %.2f\n", st[now].dis + MAX);
		}
	}
	return 0;
}
