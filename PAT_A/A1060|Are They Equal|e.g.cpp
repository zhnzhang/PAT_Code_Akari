//example
//由于本题所讨论的数的范围，所以应用字符串来处理而不是整型，本题应用STL容器String进行处理
//本题分两种情况进行讨论
//第一种 0.a1a2a3...		(数字在a的后下角作标识)
//第二种 b1b2...bm.a1a2a3...
//对第一种，指数e则是小数点与该非零位之间0的个数的相反数，指数e初值为0
//对第二种，指数e则是小数点前的数位的总位数m，指数e初值为0
//讨论的主体就是科学记数法中指数和本体部分
//本题详细思路比较冗长，不易记录在此，需复查可翻看算法笔记用书P210
#include <iostream>
#include <string>
using namespace std;
int n;				//有效位数
string deal(string s, int &e) {			//处理函数，以便获取指数e，与此同时单独提取本体部分
	int k = 0;		//s的下标
	while(s.length() > 0 && s[0] == '0') {
		s.erase(s.begin());			//去掉s的前导零
	}
	if(s[0] == '.') {		//去掉前导零后是小数点，说明s是小于1的小数
		s.erase(s.begin());			//去掉小数点
		while(s.length() > 0 && s[0] == '0') {
			s.erase(s.begin());		//去掉小数点后非零位前的所有零
			e--;					//每去掉一个0，指数e减1
		}
	}
	else {					//去掉前导零后不是小数点，则找到后面的小数点删除
		while(k < s.length() && s[k] != '.') {		//寻找小数点
			k++;
			e++;					//只要不碰到小数点就让指数e++
		}
		if(k < s.length()) {		//while结束后k < s.length(),说明碰到了小数点
			s.erase(s.begin() + k);		//把小数点删除(注意erase的参数是迭代器)
		}
	}
	if(s.length() == 0) {
		e = 0;		//如果去除前导零后s的长度变为了0，说明这个数就是0，要把e的值赋回来
	}
	int num = 0;
	k = 0;			//可以 看成 数组指针(在这里这么说不太准确)
	string res;
	//开始单独提取主体部分,放置在res字符串中
	while(num < n) {		//只要精度还没有到n
		if(k < s.length()) {
			res += s[k++];		//只要还有数字，就加到res末尾
		}
		else {
			res += '0';		//否则res末尾补0
		}
		num++;				//精度加1
	}						//注意控制变量的变化，别写成死循环
	return res;
}

int main() {
	string s1, s2, s3, s4;
	cin >> n >> s1 >> s2;
	int e1 = 0, e2 = 0;		//e1, e2为s1与s2的指数
	s3 = deal(s1, e1);
	s4 = deal(s2, e2);		//s3, s4放单独提取出来的主体部分，e1，e2通过引用后也得到了指数值
	if(s3 == s4 && e1 == e2) {		//主体相同且指数相同则YES
		cout << "YES 0." << s3 << "*10^" << e1 <<endl;
	}
	else {
		cout << "NO 0." << s3 << "*10^" << e1 << " 0." << s4 << "*10^" << e2 << endl;
	}
	return 0;
}
