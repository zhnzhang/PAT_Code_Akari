//由算法笔记示例代码推算来
//示例如下
#include <iostream>
#include <string>
using namespace std;
int main() {
	string str = "abcdefg";
	//删除在[str.begin() + 2, str.end() - 1) 内的元素，即cdef
	str.erase(str.begin() + 2, str.end() - 1);
	cout<<str<<endl;
	return 0;
}

//输出如下
//abg

//可知 str.end() - 1 指向g
//str.end() 指向g的下一个地址
