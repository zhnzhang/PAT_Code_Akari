/*
在for循环枚举时把循环条件写成i < strlen(str),这个是一个很不好的习惯。原因如下：
strlen函数的内部实现是使用一个循环扫描数组来累计长度，直到遇到'\0'结束
所以strlen本身就有O(N)的复杂度，这样会使得步骤2跟步骤3中遍历字符串的复杂度从O(N)上升到O(N^2),导致超时
恰当的做法是在for循环之前就定义int型变量len来记录str的长度，即 int len = strlen(str)
这样在for循环时循环条件可以直接写 i < len,省去了 每次都要 重新计算strlen(str)的时间
*/
