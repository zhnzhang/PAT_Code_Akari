//example
//采用除基取余法,循环部分采用do...while语句以处理初值为0时的特殊情况
//如果进制转换的时候使用的是while语句而不是do...while语句，则要注意当A + B为0时要特判 输出0
#include <cstdio>
int main() {
  int a, b, d;
  scanf("%d%d%d", &a, &b, &d);
  int sum = a + b;
  int ans[40], num = 0;   //ans存放D进制结果的每一位，根据题目给的条件其实数组大小31就够用,num相当于数组指针
  do {            //进制转换
    ans[num++] = sum % d;
    sum /= d;
  } while(sum != 0);      //while（）后面的';'不要落下
  for(int i = num - 1; i >= 0; i--) {   //从高位向低位进行输出
    printf("%d", ans[i]);
  }
  return 0;
}
