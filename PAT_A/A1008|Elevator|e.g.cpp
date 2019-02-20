//example
//total表示总共需要的时间，初值为0；now表示当前所在的层号，初值为0；to表示下一个目的层号，由输入得到
//可能会出现目的层to就是当前层now的情况，这是根据题意，也是需要5s的停留时间，因此只要在每次到达目的站时都加上这个5即可
//在达到当前目的站后，要记得把now设成该层层号

#include <cstdio>
int main() {
	int n, total = 0, now = 0, to;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &to);
		if(to > now) {
			total += ((to - now) * 6);
		}
		else {
			total += ((now - to) * 4);
		}
		total += 5;
		now = to;
	}
	printf("%d\n", total);
	return 0;
}
