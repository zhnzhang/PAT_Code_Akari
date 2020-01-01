#include <stdio.h>

int main() {
    bool flag1 = -1, flag2 = 0, flag3 = true;
    printf("%d\n%d\n%d", flag1, flag2, flag3);
    return 0;
}

//布尔型变量的取值只能是true(真)或者false(假)，分别代表非零与零
//在赋值时，可以直接使用true或false进行赋值，或是使用整形常量对其进行赋值
//只不过整形常量在赋值给布尔型变量时会自动转换为true(非零)或者false(零)
//注意："非零"是包括正整数和负整数的，即 1 和 -1 其实都会转换为true
//但是对计算机来说，true和false在存储时分别为 1 和 0
//因此如果使用%d输出bool型变量，则true和false会输出 1 和 0

//见我上面的bool型变量flag1，我是赋给它 -1 的，-1算是负整数 也就是非零，故实际上转换为true赋给了flag1，flag1的值实则为true
//由于true在计算机中是作为1存储的，故以%d的格式输出flag1时，实际输出的是1
//这就解释了 对bool型变量 flag1 ，为什么我赋值是 -1 但是 以%d的格式输出flag1时，却是1
