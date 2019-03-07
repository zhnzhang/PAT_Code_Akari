//example
//题目中seniority level的意思是从第一层(根结点)开始逐层输出叶子结点的个数
//要能考虑到只有一个结点的情况，例如下面这个例子应该输出1(只有根结点的情况下，根结点也是叶子结点)
//1 0(输入)
//若出现格式错误的情况，请注意最后一个整数输出之后不能有空格
//再次强调，queue队列中存放的其实是原元素的一个副本，所以在将元素压入队列后修改原元素的值不会是队列中的元素发生改变
//而修改队列中的元素值也不会使原元素发生改变。写程序时要注意由此带来的一些bug

//DFS版本
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 110;

vector<int> G[N];		//存放树
int leaf[N] = {0};		//存放每层的叶子结点个数
int max_h = 0;	//树的深度

void DFS(int index, int h) {		//index为当前遍历到的结点编号，h为当前深度
	max_h = max(h, max_h);
	if(G[index].size() == 0) {		//如果该结点是叶子结点
		leaf[h]++;
		return;
	}
	for(int i = 0; i < G[index].size(); i++) {		//枚举所有子结点
		DFS(G[index][i], h + 1);
	}
}

int main() {
	int n, m, parent, child, k;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) {
		scanf("%d%d", &parent, &k);		//父结点编号及子结点个数
		for(int j = 0; j < k; j++) {
			scanf("%d", &child);
			G[parent].push_back(child);		//加边
		}
	}
	DFS(1, 1);	//初始入口为根结点与第一层
	printf("%d", leaf[1]);
	for(int i = 2; i <= max_h; i++) printf(" %d", leaf[i]);
	return 0;
}


//BFS版本
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int N = 105;

vector<int> G[N];
int h[N] = {0};
int leaf[N] = {0};
int max_h = 0;

void BFS() {
	queue<int> Q;
	Q.push(1);
	while(!Q.empty()) {
		int id = Q.front();
		Q.pop();
		max_h = max(max_h, h[id]);
		if(G[id].size() == 0) {
			leaf[h[id]]++;
		}
		for(int i = 0; i < G[id].size(); i++) {
			h[G[id][i]] = h[id] + 1;
			Q.push(G[id][i]);
		}
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) {
		int parent, k, child;
		scanf("%d%d", &parent, &k);
		for(int i = 0; i < k; i++) {
			scanf("%d", &child);
			G[parent].push_back(child);
		}
	}
	h[1] = 1;
	BFS();
	for(int i = 1; i <= max_h; i++) {
		if(i == 1) printf("%d", leaf[i]);
		else printf(" %d", leaf[i]);
	}
	return 0;
}
