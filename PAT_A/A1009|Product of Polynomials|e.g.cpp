//Example

#include <cstdio>
struct Poly {
  int exp;    //指数
  double cof; //系数
} poly[1010]; //结构体定义第一个多项式,区别于A+B那道题的多项式表现形式

double ans[2020];   //存放结果，略大的数组一般习惯定义在数组外,同A+B那道题的多项式表现形式

int main() {
  int n, m, count = 0;
  scanf("%d", &n);  //第一个多项式中非零系数的项数
  for(int i = 0; i < n; i++) {                    //输入从小到大枚举
    scanf("%d%lf", &poly[i].exp, &poly[i].cof);   //第一个多项式的指数和系数
  }
  scanf("%d", &m);  //第二个多项式中非零系数的项数
  for(int i = 0; i < m; i++) {
    int exp;
    double cof;
    scanf("%d%lf", &exp, &cof);   //第二个多项式的指数和系数，边读入边处理,所以设置n和m两个变量
    for(int j = 0; j < n; j++) {
      ans[exp + poly[j].exp] += (cof * poly[j].cof);    //此式是多项式乘法核心
    }
  }
  for(int i = 0; i <= 2000; i++) {
    if(ans[i] != 0) {
      count++;    //累计非零系数的项数
    }
  }
  printf("%d", count);
  for(int i = 2000; i >= 0; i--) {    //输出从大到小枚举
    if(ans[i] != 0) {
      printf(" %d %.1f", i, ans[i]);  //系数保留一位小数，此输出格式联动循环条件逻辑和上面count的输出格式可以保证最后没有多余空格
    }
  }
  return 0;
}
