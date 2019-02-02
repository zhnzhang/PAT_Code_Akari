//example
//HashTable数组只开100或者只多一点点导致"段错误"是常见的错误。
//这是因为在3n+1猜想的序列中，可能出现超过100的数，这时访问flag数组(其实就是标记数组)就会越界
//从而导致"段错误"，读者可以考虑当n = 99时，序列是这样的
//99: 149、224、112、56、28、14、7、11、17、26、13、20、10、5、8、4、2、1
//显然序列中的最大序列可以达到224了，远不止100了
//因此需要将HashTable数组大小设置得大一些(只设置225也是不够的，上面只是举个例子，比如当n = 95时可以达到485)，建议直接设成10000以上
//当然，也可以对计算过程中的每一个数判断其是否大于100，如果大于100，就不对HashTable进行操作，这样也是可以的
//因为本题题设中给出的数属于(1,100]，故需要输出的关键数也只在(1,100]范围内，超出范围的操作就算不进行也无所谓

#include <cstdio>
#include <algorithm>
using namespace std;
bool HashTable[10000] = {false};		//HashTable[x] == true 表示x被覆盖

bool cmp(int a, int b) {
	return a > b;			//从大到小排序
}

int main() {
	int n, m, a[110];		//m用来放需要进行3n+1猜想的数,a数组用来存输入提供的数,由于后续还要用到，所以需要a数组保留元数据，m来存需要进行处理的数据
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		m = a[i];
		while(m != 1) {		//对m进行3n+1猜想操作
			if(m % 2 == 1) {
				m = (3 * m + 1) / 2;
			}
			else {
				m /= 2;
			}
			HashTable[m] = true;		//将被覆盖的数的flag置为true
		}
	}
	int count = 0;		//count计数"关键数"个数
	for(int i = 0; i < n; i++) {
		if(HashTable[a[i]] == false) {	//没被覆盖
			count++;
		}
	}
	//由于要求从大到小顺序输出关键数，需要对a数组进行排序
	sort(a, a + n, cmp);		//从大到小排序
	for(int i = 0; i < n; i++) {
		if(HashTable[a[i]] == false) {
			printf("%d", a[i]);
			count--;
			if(count > 0) {
				printf(" ");	//通过count控制输出格式
			}
		}
	}
	return 0;
}
