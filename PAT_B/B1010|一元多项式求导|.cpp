//注意“零多项式”的指数和系数都是 0，但是表示为 0 0（这个是为只有常数项的情况准备的吧）
//注意这类以scanf返回值为判别条件的输入方法

//虽然题意是最高1000次幂，没有负幂次，可以先放数组再遍历
//但我选择一次就接到数并进行处理，利用返回值是否是EOF进行判别
#include <cstdio>

int main() {
    int c, e;               //c是系数，e是指数
    int count = 0;          //输入计数
    while (scanf("%d%d", &c, &e) != EOF) {          //这样写可以避免运行超时
        if (e != 0 && count != 0)                   //用于控制空格
            printf(" ");
        count += 2;
        if (e != 0) {
            printf("%d %d", c * e, e - 1);
        } else {                                    //此时e == 0
            if (count == 2) {                       //这就是常数项的情况
                printf("0 0");
                break;
            } else {
                break;
            }
        }
    }
    return 0;
}





//Example 参考答案如下
#include <cstdio>

int main() {
  int a[1010] = {0};    //初始化.
  int k, e, count = 0;  //k为系数，e为指数，count用于计数不为零的导数项的个数
  while(scanf("%d%d", &k, &e) != EOF) {     //输入系数和指数直到文件末尾
    a[e] = k;           //数组a[]，用来存放对应指数的系数，例如a[e]就是指数为e的项的系数
  }
  a[0] = 0;     //零次项求导之后直接为0
  for(int i = 1; i <= 1000; i++) {      //从一次项开始枚举
    a[i - 1] = a[i] * i;                //求导公式
    a[i] = 0;                 //此句不可省，在求导后，当前系数必须清空为0，否则可能后面无法被覆盖（实际上在求导过程中确实是这样的。求导后，求导前的指数对应系数就相当于是清零了）。这大概也是为什么求导必须从低次项枚举到高次项吧。
    if(a[i - 1] != 0)
      count++;                //count用于计数不为零的导数项的个数（求导后）
  }
  if(count == 0)
    printf("0 0");    //特判，即如果求导之后没有任何非零项，需要输出0 0，这是本题的一个“陷阱”
  else {
    for(int i = 1000; i >= 0; i--) {      //指数从高到低输出,注意循环条件
      if(a[i] != 0) {
        printf("%d %d", a[i], i);
        count--;                          //count个数与循环逻辑是契合的故这个逻辑是可以满足最后不能有多余空格的,count == 0时，循环也正好会结束的
        if(count != 0)
          printf(" ");
      }
    }
  }
  return 0;
}




/* 失败作，不能得到任何输出...
#include <cstdio>
int main() {
  int i = 0, a[1100], b[1100], c[1100];    //a为求导前多项式系数，b为求导前多项式指数，c为求导后多项式系数
  while(scanf("%d%d", &a[i++], &b[i++]) != EOF) {
    if(b[i - 1] - 1 < 0)
      break;
    c[i - 1] = a[i - 1] * b[i - 1];
    if(i != 1)
      printf(" ");
    printf("%d %d", c[i - 1], b[i - 1] - 1);
  }
  return 0;
}
*/
