//这种题就开mp数组做
//最后一个测试点卡人，推测它为全0，即结果为0项多项式。很容易漏掉判断，导致格式错误。
//一定要注意，所有的多项式的系数对应相加后为0时为0项多项式，此时应该有判别这种情况的
//如果不判别，就会导致输出的0后面多出个空格，导致最后一个测试点格式错误。
#include <cstdio>

int main() {
    int k1, k2, count = 0;                      //k1,k2分别记录两个多项式的项数,count用于多项式和的项数计数
    int min = -1;                                    //记录最小幂次
    double mp[1010] = {0};                      //数组下标指代对应的幂次，对应数组内容指代对应项的系数
    int e; double c;                            //e接收指数，c接收系数
    scanf("%d", &k1);
    for (int i = 0; i < k1; i++) {
        scanf("%d%lf", &e, &c);
        mp[e] += c;
    }
    scanf("%d", &k2);
    for (int i = 0; i < k2; i++) {
        scanf("%d%lf", &e, &c);
        mp[e] += c;
    }
    for (int i = 0; i <= 1000; i++) {
        if (mp[i] != 0) {
            count++;
            if (count == 1) {
                min = i;
            }
        }
    }
    printf("%d", count);
    if (count == 0) {                           //这里对应处理对最后一个测试点的判别
        return 0;                               //也就是和为0项多项式时
    } else {
        printf(" ");
    }
    for (int i = 1000; i >= 0; i--) {
        if (mp[i] != 0) {
            printf("%d %.1f", i, mp[i]);
        }
        if (i != min && mp[i] != 0) {           //这样设置条件可以避免多打空格
            printf(" ");
        } else if (i == min) {
            break;
        }
    }
    return 0;
}





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
