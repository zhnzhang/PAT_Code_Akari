//example
//本题使用二维char数组进行sort排序的写法会比较麻烦，因此这里使用string进行编写代码
//对此输入输出需要配套使用cin和cout
//结果串的所有前导零都需要去除。但也要注意，如果去除前导零后串的长度变为0(说明结果串应为0)，则输出"0"
//对String，要输入和输出整个字符串，只能用cin和cout，虽然用printf输出string的方法也有就是了
//对本题来说，只考虑按字典序从小到大排序在局部会出问题，不能拼接出最小的数
//而且本题的贪心策略，体现在，cmp函数中，应用于sort函数

//虽然我还不怎么理解这里为什么这么写cmp

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 10010;
string str[maxn];		//字符串数组，每个值是一个字符串

bool cmp(string a, string b) {
	//本题贪心策略体现在此
	return a + b < b + a;		//如果a + b < b + a，就把a排在前面
}

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> str[i];
	}
	sort(str, str + n, cmp);		//排序
	string ans;		//结果字符串
	for(int i = 0; i < n; i++) {
		ans += str[i];				//将排序后的数字串进行拼接
	}
	while(ans.size() != 0 && ans[0] == '0') {
		ans.erase(ans.begin());		//去除前导零
	}
	if(ans.size() == 0) {
		cout << 0;			//去除前导零后为空，输出0(这个情况不能落下)
	}
	else {
		cout << ans;		//否则输出结果
	}
	return 0;
}
