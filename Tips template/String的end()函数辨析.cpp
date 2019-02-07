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

//顺便提下，很多STL容器里面相应的函数的参数，涉及到区间范围
//基本上是表示[ , )  即左闭右开的
//那么相应的，参数的填写要满足这样的要求，示例如下
//str.erase(first, last)，其中first为需要删除的区间的起始迭代器，而last则为需要删除的区间的末尾迭代器的下一个地址
//也即为删除[first, last)
