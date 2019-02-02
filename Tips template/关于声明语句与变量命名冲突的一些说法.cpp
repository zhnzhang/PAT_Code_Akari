/*
如果引用了iostream或者vector，又加了using namespace std;这条语句，就尽量不要使用hash这样的变量名
因为这样会跟std命名空间里面的hash变量名冲突，导致编译失败或者运行出错
这种情况解决办法要么单独用std，比如std::cin、std::endl，要么直接避开hash作为变量名(可以改用HashTable)
类似的还有math.h的y1变量名，如果将其作为全局变量，就会导致编译错误
若编译有报错或者运行莫名出错，则可以考虑这些因素
*/
