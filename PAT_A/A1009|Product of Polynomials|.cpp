#include <cstdio>

int main() {
    int k1, k2;                                     //k1,k2记录poly1和poly2的非零项数
    int e, count = 0;                               //e用来接收输入的指数，count用来给乘积得出的多项式计数非零项
    int maxe1 = -1, maxe2 = -1, maxe = -1, mine1 = 1010, mine2 = 1010, mine = 1010;
                                                    //maxe1，mine1是用来记第一个多项式中最高与最低次幂
                                                    //maxe2，mine2是用来记第二个多项式中最高与最低次幂
                                                    //maxe，mine是用来记积多项式中最高与最低次幂
    double c;
    double poly1[1010] = {0}, poly2[1010] = {0}, polypro[2010] = {0};
                                                    //尤其注意积多项式的数组大小设置，由幂次决定，不然发生段错误
    scanf("%d", &k1);
    for (int i = 0; i < k1; i++) {
        scanf("%d%lf", &e, &c);
        if (i == 0) {
            maxe1 = e;
        }
        if (i == k1 - 1) {
            mine1 = e;
        }
        poly1[e] += c;
    }
    scanf("%d", &k2);
    for (int i = 0; i < k2; i++) {
        scanf("%d%lf", &e, &c);
        if (i == 0) {
            maxe2 = e;
        }
        if (i == k2 - 1) {
            mine2 = e;
        }
        poly2[e] += c;
    }
    maxe = maxe1 + maxe2;
    mine = mine1 + mine2;
    for (int i = mine1; i <= maxe1; i++) {              //多项式相乘逻辑处理
        for (int j = mine2; j <= maxe2; j++) {
            if (poly1[i] != 0 && poly2[j] != 0) {
                polypro[i + j] += poly1[i] * poly2[j];
            }
        }
    }
    for (int i = mine; i <= maxe; i++) {
        if (polypro[i] != 0) {
            count++;
        }
    }
    printf("%d", count);
    if (count == 0) {                                   //为0项式做特殊判别
        return 0;
    } else {
        printf(" ");
    }
    for (int i = maxe; i >= mine; i--) {
        if (polypro[i] != 0) {
            printf("%d %.1f", i, polypro[i]);
            if (i != mine) {                            //格式控制
                printf(" ");
            }
        }
    }
    return 0;
}



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
