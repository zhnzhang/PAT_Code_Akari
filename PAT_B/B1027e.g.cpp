//example
//这是道数学题啊
//着重需要获取这三个数据：1.三角形的底边拥有的字符数 2.每行非空格字符输出之前需要输出的空格数 3.需要剩下多少个题目给定的字符不输出
//三角形的底边拥有的字符数是整数也是奇数；sqrt函数的参数必须是浮点数，故系数要以浮点数形式表示；向下取整可以直接强制int类型转换，也可以使用math.h头文件下的floor函数（浮点数作参数）
#include <cstdio>
#include <cmath>

int main() {
  int n;
  char c;
  scanf("%d %c", &n, &c);
  int bottom = (int)sqrt(2.0 * (n + 1)) - 1;  //用强制int类型转换来进行向下取整
  if(bottom % 2 == 0)
    bottom--;         //根据公式算出底边字符数是偶数的话，要减1，令其为奇数
  int used = (bottom + 1) * (bottom + 1) / 2 - 1;   //总共输出的非空格字符数
  //输出倒三角
  for(int i = bottom; i >= 1; i -= 2) {       //i为当前行的非空格字符数!
    for(int j = 0; j < (bottom - i) / 2; j++) {
      printf(" ");
    }
    for(int j = 0; j < i; j++) {
      printf("%c", c);
    }
    printf("\n");
  }
  //输出正三角
  for(int i = 3; i <= bottom; i += 2) {
    for(int j = 0; j < (bottom - i) / 2; j++) {
      printf(" ");
    }
    for(int j = 0; j < i; j++) {
      printf("%c", c);
    }
    printf("\n");
  }
  printf("%d\n", n - used);
  return 0;
}
