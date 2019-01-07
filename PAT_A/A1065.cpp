//此题的预先情况分析比代码重要。要考虑到溢出的可能性并计算溢出的边界值，得出溢出后的值的区间。
//经测试，数据种并没有A或B取到2^63的情况，因此题目种的数据范围可能是写错了，应该是[-2^63,2^63)更符合数据，否则要用带负数的大整数运算了(因为long long存储2^63时回自动变成-2^63,无法区分左右边界)
//A + B必须存放到long long型变量种才可与C进行比较，而不可以在if的条件种直接相加与C比较，否则会造成后两组数据错误。
//Example 参考答案如下
#include <cstdio>
int main() {
  int T, tcase = 1;
  scanf("%d", &T);
  while(T--) {
    long long a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    long long res = a + b;              //res存放a + b的结果_变量名命名习惯_res->result,ans->answer;
    bool flag;
    if(a > 0 && b > 0 && res < 0)             //正溢出为true
      flag = true;
    else if(a < 0 && b < 0 && res >= 0)       //负溢出为false
      flag = false;
    else if(res > c)            //无溢出时， A + B > C时为true
      flag = true;
    else                        //无溢出时， A + B <= C时为false
      flag = false;
    if(flag == true) {
      printf("Case #%d: true\n", tcase++);
    }
    else {
      printf("Case #%d: false\n", tcase++);
    }
  }
  return 0;
}
