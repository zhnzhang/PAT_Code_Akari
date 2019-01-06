#include <cstdio>         //本题的解题思路如下面注释，我是借鉴了CSDN，我本身没想到用一步一步的循环做
int main() {              //temp的设置很好，但我那些一步到位的想法免不了数组的支持
  int n, m, a[150];       //还是编程的思路不到位，分治的思想缺乏，利用循环这个基本操作分而治之
  scanf("%d%d", &n, &m);  //哪有那么多一步到位的好事，计算机不怕步骤多，但它也实现不了人的跳跃思维
  m %= n;                 //利用模运算修正m(这点容易被忽视)
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  int temp = 0;
  for(int i = 0; i < m; i++) {    //(核心)不允许使用数组，那就利用循环操作分解成一步一步来实现,每次循环右移一位，循环m次
    temp = a[n - 1];
    for(int j = n - 2; j >= 0; j--) {
      a[j + 1] = a[j];
    }
    a[0] = temp;
  }
  for(int i = 0; i < n; i++) {
    printf("%d", a[i]);
    if(i != n - 1) {
      printf(" ");
    }
  }
  return 0;
}


/*
#include <cstdio>         //参考答案的做法显然根据题目提示(最后M个数循环移至最前面的M个位置)来取巧
int main() {              //它并没有实际改变数组中的顺序，而是利用规律直接将对应的顺序输出出来
  int a[110];
  int n, m, count = 0;    //count记录已经输出数的个数
  scanf("%d%d", &n, &m);
  m %= n;                 //修正m(这点容易被忽视)
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for(int i = n - m; i < n; i++) {    //输出n - m号到n - 1号
    printf("%d", a[i]);
    count++;    //已输出数的个数加1
    if(count < n)
      printf(" ");            //如果已经输出数的个数小于n,则输出空格
  }
  for(int i = 0; i < n - m; i++) {    //输出0号到n - m - 1号
    printf("%d", a[i]);
    count++;
    if(count < n)
      printf(" ");
  }
  return 0;
}
*/
