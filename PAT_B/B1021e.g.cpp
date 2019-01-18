//利用到数组下标，为下标也赋予意义
//1000位的数，明显是要放到字符数组里了，这就涉及到如何将字符型的数字转换为整数型的数字了
//利用ASCII码之间的距离差的思想，可以进行大小写字符转换或者数字类型转换

#include <cstdio>
#include <cstring>
int main() {
  char str[1010];
  scanf("%s", str);
  int len = strlen(str);
  //见上方注释常用的技法，记录数字0～9的出现次数，初值均为0
  int count[10] = {0};
  for(int i = 0; i < len; i++) {
    count[str[i] - '0']++;    //见上方注释，将str[i]对应的数字的count值加1
  }
  //枚举0～9
  for(int i = 0; i < 10; i++) {
    if(count[i] != 0) {
      printf("%d:%d\n", i, count[i]);
    }
  }
  return 0;
}
