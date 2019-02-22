//example
//对于某一排来说，每次都是左右交替进行人的放置，因此按此排内部的序号来说一定是一侧奇数一侧偶数
//最后从后排往前排一依次输出每排的人的姓名
//将所有人按身高从高到低排序，身高相同时按照姓名字典序从小到大排序
//定义变量num表示当前排的人数，初值为n - (k - 1) * (n / k),即最后一排人数
//再定义变量leftPos表示该排身高最高的人在数组中的编号，于是该排所有人在数组中的编号范围是[leftPos, leftPos + num - 1]
//当处理完一排后，将leftPos加上num即可得到前一排身高最高的人在数组中的编号
//本题必须在最后一行输出换行，否则会有若干组数据"格式错误"
//姓名的数组大小至少需要开9
//本体也可以用双端队列解决，或是使用数组模拟双端队列来实现

//直接做法
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 10010;
struct Person {
	char name[10];		//姓名
	int height;			//身高
} person[maxn];

bool cmp(Person a, Person b) {	//先按身高从高到低，再按姓名字典序从小到大
	if(a.height != b.height) return a.height > b.height;
	else return strcmp(a.name, b.name) < 0;
}

int main() {
	int n, k;		//n为人数，k为排数
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++) {	//输入每个人的姓名和身高
		scanf("%s%d", person[i].name, &person[i].height);
	}
	sort(person, person + n, cmp);		//排序
	//num为当前排人数，leftPos为当前排的身高最高者的位置
	int num = n - (k - 1) * (n / k), leftPos = 0;
	while(leftPos < n) {	//每次处理一排
		for(int i = (num % 2) ? (num - 2) : (num - 1); i >= 1; i -= 2) {
			printf("%s ", person[leftPos + i].name);		//从最大奇数到最小奇数输出
		}
		for(int i = 0; i < num; i += 2) {
			printf("%s", person[leftPos + i].name);		//从最小偶数到最大偶数
			if(i < num - 2) printf(" ");
			else printf("\n");		//本题必须换行
		}
		leftPos += num;		//前一排的身高最高者的位置
		num = n / k;		//除最后一排外，前面所有排的人数都是n / k
	}
	return 0;
}
