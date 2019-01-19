//example
//字符串存放在一维字符数组中
#include <cstdio>
#include <cstring>
int main() {
  char str[110];
  scanf("%s", str);
  int len = strlen(str);
  int sum = 0;    //sum存放所有数位之和
  for(int i = 0; i < len; i++) {
    sum += str[i] - '0';    //将每一位累加
  }
  //num表示sum的位数
  int num = 0, ans[10];
  do {
    ans[num++] = sum % 10;
    sum /= 10;
  } while(sum != 0); //将sum中每一位存到数组中，sum的低位存到ans[]的低位
  char change[10][5] = {
    "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"
  };    //定义二维字符数组，来对应数字与字符串的关系，即change[0] = "ling", change[1] = "yi"... 常用技法，简洁
  for(int i = num - 1; i >= 0; i--) {
    printf("%s", change[ans[i]]);
    if(i != 0)
      printf(" ");
  }
  return 0;
}
