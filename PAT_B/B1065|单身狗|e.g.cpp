//example
//这么秀的吗？存在伴侣但是没来派对也被算成单身人士给予特殊关爱？
//定义int型数组couple，用以存放每个人的伴侣编号
//对输入的每组情侣id1和id2，令couple[id1] = id2、couple[id2] = id1。这样对任意的ID，都能找到他的伴侣编号
//couple数组可以初始化为-1，表示没有伴侣
//定义bool型数组isInParty，用以标记每个ID是否在派对中，针对每个在派对中的ID，令isInParty[ID] = true
//遍历所有ID(0到99999)，如果当前ID在派对中(即isInParty[ID] == true)并且他不存在伴侣(couple[ID] == -1)|或者有伴侣但是伴侣不在派对中(isInParty[couple[ID]] == false)
//那么他就是单身狗，将其加入到用来存放所有单身狗ID的数组singleDog中
//注意要将单身狗数组元素从小到大排序后再输出
//本题的单身狗数组使用set会比较方便
//如果一个人有伴侣，但该伴侣不在派对中，仍然视为单身狗
//本题还可以把在派对中的所有ID都直接记录在一个数组里，这样后续就只需要遍历这个数组而不是0-99999所有这些编号，可以认为是以空间换时间的一种做法

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100010;		//编号上限(0-99999)
const int maxm = 10010;			//派对中的人数上限
int couple[maxn];			//伴侣编号
bool isInParty[maxn] = {false};		//标记每个ID是否在派对中
int numSingleDog = 0, singleDog[maxm];	//单身狗数量，单身狗数组

int main() {
	int n, m, ID;
	scanf("%d", &n);		//输入情侣对数
	memset(couple, -1, sizeof(couple));		//情侣数组编号初始化为-1，表示没有情侣
	for(int i = 0; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);		//输入每对情侣编号
		couple[a] = b;	//互相设置情侣编号
		couple[b] = a;
	}
	scanf("%d", &m);	//输入派对中的人数
	for(int i = 0; i < m; i++) {
		scanf("%d", &ID);		//输入某个派对中的人的ID
		isInParty[ID] = true;	//设置这个ID为在派对中
	}
	for(int i = 0; i < maxn; i++) {		//遍历 所有编号
		//如果编号i在派对中，并且他没有伴侣或伴侣不在派对中
		if(isInParty[i] == true && (couple[i] == -1 || !isInParty[couple[i]])) {
			singleDog[numSingleDog++] = i;	//将他加入到单身狗数组
		}
	}
	sort(singleDog, singleDog + numSingleDog);	//对单身狗数组从小到大排序
	printf("%d\n", numSingleDog);		//输出单身狗人数
	for(int i = 0; i < numSingleDog; i++) {		//输出所有单身狗
		printf("%05d", singleDog[i]);
		if(i < numSingleDog - 1) {
			printf(" ");	//控制最后一个单身狗后面的空格
		}
	}
	return 0;
}
