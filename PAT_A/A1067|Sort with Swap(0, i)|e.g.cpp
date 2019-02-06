//example
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int pos[maxn];		//存放各数字当前所处的位置编号,数组下标表示数字，数组值表示位置编号

int main() {
	int n, ans = 0;	//ans表示总交换次数
	scanf("%d", &n);
	int left = n - 1, num;		//left存放 除0以外 不在本位上的数的个数
	for(int i = 0; i < n; i++) {
		scanf("%d", &num);
		pos[num] = i;			//num所处的位置为i
		if(num == i && num != 0) {		//如果除0以外有在本位上的数
			left--;		//令left减1
		}
	}
	//贪心策略如下，注意变量k的设置，省得每次都重来，降低了时间复杂度
	//已在本位的数后续不会再动了
	int k = 1;			//k存放 除0以外 当前不在本位上的最小数
	while(left > 0) {	//只要还有数不在本位上
		//如果0在本位上，则寻找一个 当前不在本位上的数 与0交换
		if(pos[0] == 0) {
			while(k < n) {
				if(pos[k] != k) {			//找到一个当前不在本位上的数k
					swap(pos[0], pos[k]);	//将k与0交换位置
					ans++;					//交换次数加1
					break;
				}
				k++;		//进一步去判断k + 1是否在本位
			}
		}
		//只要0不在本位，就将 0所在位置的数 的当前所处位置 与 0的位置 交换，让其回到本位
		while(pos[0] != 0) {
			swap(pos[0], pos[pos[0]]);		//将0与pos[0]交换次数加1
			ans++;			//交换次数加1
			left--;			//不在本位的数的个数减1
		}
	}
	printf("%d\n", ans);
	return 0;
}
