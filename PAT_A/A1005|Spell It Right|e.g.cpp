//example
//多种写法如下
/*
#include <cstdio>
#include <cstring>

char num[10][10] = {    //数字与单词的对应
  "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
};
char s[110];  //初始字符串
int digit[10];

int main() {
  scanf("%s", s);
  int len = strlen(s);
  int sum = 0, numlen = 0;  //sum为s的数位之和，numlen计量sum的长度（其实就是数组指针）
  for(int i = 0; i < len; i++) {
    sum += (s[i] - '0');    //累加s的数位，得到sum
  }
  if(sum == 0) {      //如果sum为0，特判输出num[0]
    printf("%s", num[0]);
  }
  else {    //如果sum不为0
    while(sum) {    //将sum存放到digit数组中
      digit[numlen++] = sum % 10;
      sum /= 10;
    }
    for(int i = numlen - 1; i >= 0; i--) {    //从高位到低位输出digit数组
      printf("%s", num[digit[i]]);
      if(i != 0) {
        printf(" ");      //最后一个单词之后不输出空格
      }
    }
  }
  return 0;
}


//用do...while完成digit数组写入，可以不用特判特殊数据0
#include <cstdio>
#include <cstring>

char num[10][10] = {    //数字与单词的对应
  "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
};
char s[110];  //初始字符串
int digit[10];

int main() {
  scanf("%s", s);
  int len = strlen(s);
  int sum = 0, numlen = 0;  //sum为s的数位之和，numlen计量sum的长度（其实就是数组指针）
  for(int i = 0; i < len; i++) {
    sum += (s[i] - '0');    //累加s的数位，得到sum
  }
  do {
    digit[numlen++] = sum % 10;
    sum /= 10;
  } while(sum);
  for(int i = numlen - 1; i >= 0; i--) {    //从高位到低位输出digit数组
    printf("%s", num[digit[i]]);
    if(i != 0) {
      printf(" ");      //最后一个单词之后不输出空格
    }
  }
  return 0;
}

//用sprintf写到digit数组里，如果使用这种写法，digit必须是字符型数组
#include <cstdio>
#include <cstring>

char num[10][10] = {    //数字与单词的对应
  "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
};
char s[110];  //初始字符串
char digit[10];

int main() {
  scanf("%s", s);
  int len = strlen(s);
  int sum = 0, numlen = 0;  //sum为s的数位之和，numlen计量sum的长度（其实就是数组指针）
  for(int i = 0; i < len; i++) {
    sum += (s[i] - '0');    //累加s的数位，得到sum
  }
  sprintf(digit, "%d", sum);
  numlen = strlen(digit);
  for(int i = 0; i < numlen; i++) {    //从高位到低位输出digit数组
    printf("%s", num[digit[i] - '0']);
    if(i != numlen - 1) {
      printf(" ");      //最后一个单词之后不输出空格
    }
  }
  return 0;
}
*/

//递归写法,清爽
#include <cstdio>
#include <cstring>

char num[10][10] = {    //数字与单词的对应
  "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
};
char s[110];  //初始字符串

void dfs(int n) {
  if(n / 10 == 0) {
    printf("%s", num[n % 10]);
    return;
  }
  dfs(n / 10);
  printf(" %s", num[n % 10]);   //这里的空格位置正确，就是在格式控制符前面，理解一下递归逻辑
}

int main() {
  scanf("%s", s);
  int len = strlen(s);
  int sum = 0, numlen = 0;  //sum为s的数位之和，numlen计量sum的长度（其实就是数组指针）
  for(int i = 0; i < len; i++) {
    sum += (s[i] - '0');    //累加s的数位，得到sum
  }
  dfs(sum);
  return 0;
}
