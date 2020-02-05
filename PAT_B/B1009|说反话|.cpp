#include <cstdio>

char str[100][100];

int main() {
    int i = 0;
    while (scanf("%s", str[i]) != EOF) {
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%s", str[j]);
        if (j != 0) {
            printf(" ");
        }
    }
    return 0;
}



//example1
//使用gets函数读入一整行，从左至右枚举每一个字符，以空格为分隔符对单词进行划分并
//按顺序存放到二维字符数组中，最后按单词输入顺序的逆序来输出所有单词
#include <cstdio>
#include <cstring>

int main() {
  char str[90];
  gets(str);
  int len = strlen(str), r = 0, h = 0;    //r为行，h为列
  char ans[90][90];       //ans[0]～ans[r]存放单词
  for(int i = 0; i < len; i++) {
    if(str[i] != ' ') {   //枚举字符，如果不是空格，则存放至ans[r][h]，并令h++
      ans[r][h++] = str[i];
    }
    else {                //如果是空格，说明一个单词结束，行r增加1，列h恢复至0
      ans[r][h] = '\0';   //字符数组末尾是结束符\0
      r++;
      h = 0;
    }
  }
  for(int i = r; i >= 0; i--) {   //倒着输出单词
    printf("%s", ans[i]);
    if(i > 0)
      printf(" ");
  }
  return 0;
}



//example2
//由于PAT是单点测试，因此产生了下面这种更简洁的方法，即使用EOF来判断单词是否已经输入完毕
/*
#include <cstdio>
int main() {
  int num = 0;      //单词的个数
  char ans[90][90];
  while(scanf("%s", ans[num]) != EOF) {
    num++;
  }
  for(int i = num - 1; i >= 0; i--) {
    printf("%s", ans[i]);
    if(i > 0)
      printf(" ");
  }
  return 0;
}
*/
