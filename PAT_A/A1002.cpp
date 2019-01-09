//B1010,A1002都用到了这种写法：
//开一个数组a[]或p[]表示多项式，用来存放对应指数的系数，例如a[i]就是指数为i的项的系数，初值为0
//再令一个int型变量count来表示系数非零项的个数，初值为0
//这种写法多见于含多项式的问题
//Example 参考答案如下

#include <cstdio>
const int max_n = 1110;
double p[max_n] = {};

int main() {
  int k, n, count = 0;
  double a;
  scanf("%d", &k);
  for(int i = 0; i < k; i++) {            //输入从小到大枚举
    scanf("%d%lf", &n, &a);
    p[n] += a;
  }
  scanf("%d", &k);
  for(int i = 0; i < k; i++) {
    scanf("%d%lf", &n, &a);
    p[n] += a;
  }
  for(int i = 0; i < max_n; i++) {        //有判断系数是否为零，故循环条件写成这样也无所谓，但因为幂次能取到1000，故不能写出i<1000这样的条件
    if(p[i] != 0) {
      count++;
    }
  }
  printf("%d", count);
  for(int i = max_n - 1; i >= 0; i--) {   //输出从大到小枚举，按题目格式走
    if(p[i] != 0) {
      printf(" %d %.1f", i, p[i]);        //保留1位小数
    }
  }
  return 0;
}
