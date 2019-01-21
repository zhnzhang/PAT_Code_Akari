//example
//本题流程比较冗长，见算法笔记习题集P84
//共分三节，四位一节，个节，万节，亿节
//这个过程分析说实话我并不能自己完成
#include <cstdio>
#include <cstring>
char num[10][5] = {     //num[0] = "ling", num[1] = "yi", ...
  "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"
};
char wei[5][5] = {      //wei[0] = "Shi", wei[1] = "Bai", ...
  "Shi", "Bai", "Qian", "Wan", "Yi"
};

int main() {
  char str[15];
  scanf("%s", str);     //按字符串方式输入数字
  int len = strlen(str);      //字符串长度
  //left指向当前需要输出的位，而right指向与left同节的个位
  int left = 0, right = len - 1;    //left与right分别指向字符串首尾元素，left指向高位，right指向低位
  //先判断正负，如果是负数，则输出“FU”,并把left右移1位，因为负号占一位！
  if(str[0] == '-') {
    printf("Fu");       //对空格的控制体现在整个程序的循环逻辑
    left++;
  }
  while(left + 4 <= right) {
    right -= 4;         //将right每次左移4位，直到left与right在一节,四位一节
  }
  while(left < len) {   //循环 | 每次处理数字的其中一节(4位或小于4位)
    bool flag = false;    //初始化bool型变量标记，flag == false表示没有累积的0
    bool isPrint = false;   //isPrint == false表示该节没有输出过其中的位
    while(left <= right) {    //从左至右处理数字中某节的每一位
      if(left > 0 && str[left] == '0') {    //如果当前位位0(left > 0意为不是首位)
        flag = true;      //令标记flag为true
      }
      else {              //如果当前位不为0
        if(flag == true) {    //如果存在累积的0
          printf(" ling");
          flag = false;       //相当于清空累积了
        }
        //只要不是首位（包括符号），后面的每一位前都要输出空格
        if(left > 0)
          printf(" ");
        printf("%s", num[str[left] - '0']);      //输出当前位数字(如果说特殊数据0的输出那就是在这里了)
        isPrint = true;               //该节至少有一位被输出
        if(left != right) {           //某节中除了个位外，都需要输出十百千
          printf(" %s", wei[right - left - 1]);
        }
      }
      left++;       //left右移1位
    }
    if(isPrint == true && right != len - 1) {     //只要不是个位，就输出万或亿
      printf(" %s", wei[(len - 1 - right) / 4 + 2]);    //计算结果自行模拟
    }
    right += 4;     //right右移4位，继续进行下一节的输出
  }
  return 0;
}
