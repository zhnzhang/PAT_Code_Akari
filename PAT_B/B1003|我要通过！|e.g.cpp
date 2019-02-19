//example
//思路见算法笔记训练习题集P191
//条件2是条件3的基础
//记录P左边A的个数为x、P和T中间A的个数为y、T右边A的个数为z

#include <cstdio>
#include <cstring>
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		char str[110];
		scanf("%s", str);	//输入字符串
		int len = strlen(str);
		//分别代表P的个数、T的个数、除PAT外字符的个数
		int num_p = 0, num_t = 0, other = 0;
		int loc_p = -1, loc_t = -1;		//分别代表P的位置、T的位置
		for(int i = 0; i < len; i++) {
			if(str[i] == 'P') {			//若当前字符为P，则P的个数加1、位置变为i
				num_p++;
				loc_p = i;
			}
			else if(str[i] == 'T') {	//若当前字符为T，则T的个数加1、位置变为i
				num_t++;
				loc_t = i;
			}
			else if(str[i] != 'A') {
				other++;		//如果不是P、A、T中的一个，other++
			}
		}
		//如果P的个数不为1，或者T的个数不为1
		//或者存在除PAT外的字符，或者P和T之间没有字符
		if((num_p != 1) || (num_t != 1) || (other != 0) || (loc_t - loc_p <= 1)) {
			printf("NO\n");
			continue;
		}
		//x、y、z的含义见注释，可以通过loc_p和loc_t得到
		int x = loc_p, y = loc_t - loc_p - 1, z = len - loc_t - 1;
		if(z - x * (y - 1) == x) {	//条件2成立的条件
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}
