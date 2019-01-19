//example
//Same as A1061
//我在参考代码的基础上有改动，改用数组进行存储及运算
//本题说明比较繁琐，详情见算法笔记习题集P67
#include <cstdio>
#include <cstring>
int main() {
  char week[7][5] = {
    "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"
  };
  char str[5][70] = {0};
  for(int i = 1; i <= 4; i++) {
    scanf("%s", str[i]);
  }
  int len[5] = {0};
  for(int i = 1; i <= 4; i++) {
    len[i] = strlen(str[i]);
  }
  int i;      //数组指针
  //寻找str[1]和str[2]中第一对相同位置的A～G的大写字母
  for(i = 0; i < len[1] && i < len[2]; i++) {
    if(str[1][i] == str[2][i] && str[1][i] >= 'A' && str[1][i] <= 'G') {      //限定区域必须完整
      printf("%s ", week[str[1][i] - 'A']);    //输出对应是星期几
      break;
    }
  }
  //在上面的基础上，往后继续寻找相同位置的0～9或者A～N的字符
  for(i++; i < len[1] && i < len[2]; i++) {
    if(str[1][i] == str[2][i]) {
      if(str[1][i] >= '0' && str[1][i] <= '9') {
        printf("%02d:", str[1][i] - '0');   //输出0～9，字符型与数字型通过ASCII码差进行转换
        break;
      }
      else if(str[1][i] >= 'A' && str[1][i] <= 'N') {
        printf("%02d:", str[1][i] - 'A' + 10);    //输出10～23
        break;
      }
    }
  }
  //寻找str[3]和str[4]中第一对相同位置的A～Z或a～z的英文字母
  for(i = 0; i < len[3] && i < len[4]; i++) {
    if(str[3][i] == str[4][i]) {
      if((str[3][i] >= 'A' && str[3][i] <= 'Z') || (str[3][i] >= 'a' && str[3][i] <= 'z')) {
        printf("%02d\n", i);      //输出当前位置
        break;
      }
    }
  }
  return 0;
}
