//example
//Read the gets manual. It tells you which header file needs to be included. 
//But take careful note of what it says near the end: "Never use gets(). 
//Because it is impossible to tell without knowing the data in advance how many characters gets() will read, 
//and because gets() will continue to store characters past the end of the buffer, it is extremely dangerous to use. 
//It has been used to break computer security. Use fgets() instead."

//二维数组方式,以二维数组为依托完成输出格式控制

#include <cstdio>
#include <cstring>

int main() {
  char str[100], ans[40][40];
  scanf("%s", str);     //这里我改用了scanf，否则编译错误，而且见上述注释，关于gets的使用注意
  int N = strlen(str);  //用strlen函数获取长度(位于string.h头文件中)
  int n1 = (N + 2) / 3, n3 = n1, n2 = N + 2 - n1 - n3;  //公式
  for(int i = 1; i <= n1; i++) {    //这样方便之后参数书写和理解
    for(int j = 1; j <= n2; j++) {
      ans[i][j] = ' ';  //初始化，将ans数组全部赋为空格，用空格打底
    }
  }
  int pos = 0;  //pos从0开始使用str数组，可以理解为数组指针
  for(int i = 1; i <= n1; i++) {  //正如上述所说，循环参数这样设置方便书写和理解，不易出错，数组大小设置得足够大了。
    ans[i][1] = str[pos++];       //从上往下赋值左侧n1个字符
  }
  for(int j = 2; j <= n2; j++) {
    ans[n1][j] = str[pos++];      //从左往右赋值底部n2 - 1个字符（挖去最左端）
  }
  for(int i = n3 - 1; i >= 1; i--) {
    ans[i][n2] = str[pos++];      //从下往上赋值右侧n3 - 1个字符（挖去最下端）
  }
  //采用循环输出整个二维数组
  for(int i = 1; i <= n1; i++) {
    for(int j = 1; j <= n2; j++) {
      printf("%c", ans[i][j]);
    }
    printf("\n");                 //按格式输出二维数组的话，每行输出完要换行，这是必不可少的
  }
  return 0;
}

//直接输出方式
/*
#include <cstdio>
#include <cstring>
int main() {
  char str[100];
  scanf("%s", str);
  int N = strlen(str);  //用strlen函数获取长度
  int n1 = (N + 2) /3, n3 = n1, n2 = N + 2 - n1 - n3; //公式
  for(int i = 0; i < n1 - 1; i++) {   //输出前n1 - 1行
    printf("%c", str[i]); //先输出当前行的左侧字符
    for(int j = 0; j < n2 - 2; j++) {
      printf(" ");  //输出n2 - 2个空格
    }
    printf("%c\n", str[N - i - 1]);   //输出当前行的右侧字符，并注意换行，这个不能落下
  }
  for(int i = 0; i < n2; i++) {
    printf("%c", str[n1 - 1 + i]);
  }
  printf("\n");
  return 0;
}
*/
