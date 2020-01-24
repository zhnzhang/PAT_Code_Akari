//此题不涉及太多解法上的东西，主要是要带上对 溢出 的判别就行了，溢出的定义见计组的书即可
//如果按题意的范围走，要用到带负数的大整数运算的知识，所以题目中的范围应该是左闭右开才对
//不考虑a+b溢出的话，会有两组数组错误，所以要加上溢出的判别
//a+b如果正溢出，无论如何都会比c大的
//a+b如果负溢出，无论如何都会比c小的
//所谓溢出就是超出了表示范围，此时符号会发生变化
#include <cstdio>
#define ll long long

int main() {
    int t;
    ll a, b, c, res;
    scanf("%d", &t);
    bool flag;
    for (int i = 1; i <= t; i++) {                      //这里对溢出的判别条件的分析见算法笔记
        scanf("%lld%lld%lld", &a, &b, &c);
        res = a + b;                                    //要把a+b放到res里面再进行比较，否则会出错
        if (a > 0 && b > 0 && res < 0) {                //正溢出判别
            flag = true;
        } else if (a < 0 && b < 0 && res >= 0) {        //负溢出判别（注意是>=），不然最后一组数据会错
            flag = false;
        } else if (res > c) {
            flag = true;
        } else {
            flag = false;
        }
        if (flag == true) {
            printf("Case #%d: true\n", i);
        } else {
            printf("Case #%d: false\n", i);
        }
    }
    return 0;
}


//此题的预先情况分析比代码重要。要考虑到溢出的可能性并计算溢出的边界值，得出溢出后的值的区间。
//经测试，数据中并没有A或B取到2^63的情况，因此题目种的数据范围可能是写错了，应该是[-2^63,2^63)更符合数据，否则要用带负数的大整数运算了(因为long long存储2^63时回自动变成-2^63,无法区分左右边界)
//A + B必须存放到long long型变量中才可与C进行比较，而不可以在if的条件种直接相加与C比较，否则会造成后两组数据错误。
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
