//题意是想这样的呈现 1,555   1,777,776

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    int a, b, i = 0, len = 0, sum;  //i用于取位时的循环计数，len是和的位数
    char ans[15];
    fill(ans, ans + 15, '\0');      //这步还蛮重要的，不赋上初值容易随机出现一些奇怪的答案
    scanf("%d %d",&a, &b);
    sum = a + b;
    if (sum < 0) {
        printf("-");
        sum = sum * -1;
    }
    do {
        int tmp = sum % 10;
        ans[i++] = '0' + tmp;
        sum /= 10;
    } while (sum != 0);
    len = strlen(ans);
    reverse(ans, ans + len);
    if (len <= 3) {                         //不用逗号
        for (int j = 0; j < len; j++) {
            printf("%c", ans[j]);
        }
    } else {
        if (len % 3 == 0) {                 //举个实例，再推广成规律
            for (int j = 0; j < len; j++) {
                printf("%c", ans[j]);
                if (j % 3 == 2 && j != len - 1) {       //注意最后面不要加逗号
                    printf(",");
                }
            }
        } else if (len % 3 == 1) {
            for (int j = 0; j < len; j++) {
                printf("%c", ans[j]);
                if (j == 0) {
                    printf(",");
                }
                if ((j - 1) % 3 == 2 && j != len - 1) {
                    printf(",");
                }
            }
        } else {
            for (int j = 0; j < len; j++) {
                printf("%c", ans[j]);
                if (j == 1) {
                    printf(",");
                }
                if ((j - 2) % 3 == 2 && j != len - 1) {
                    printf(",");
                }
            }
        }
    }
    return 0;
}



//example
//说明比较冗长，见算法笔记习题集P73-74
//正常解法 两个步骤，步骤1不能省，步骤2在简洁写法里可以略去。其实我感觉这个参考答案的变量名的设置不怎么合我的习惯，结果数组我还是习惯ans，数组指针用num表示
/*
#include <cstdio>
int num[10];

int main() {
  int a, b, sum;
  scanf("%d%d", &a, &b);
  sum = a + b;            //将a + b赋值给sum
  if(sum < 0) {     //sum为负数时，输出负号并取sum的相反数
    printf("-");
    sum = -sum;
  }
  int len = 0;    //len存放sum的长度
  do {
    num[len++] = sum % 10;
    sum /= 10;
  } while(sum);       //对这种技法，我比较习惯do...while的形式解决
  
  //if(sum == 0)
  //  num[len++] = 0;   //sum为0时特殊处理
  //将sum存入输出num[]中，其中sum的低位对应存放到num[]的低位
  //while(sum) {
    //将sum的末位sum % 10存放到num[len]，然后len++
  //  num[len++] = sum % 10;
  //  sum /= 10;    //去除sum的末位
  //}
  for(int i = len - 1; i >= 0; i--) {     //从高位开始输出
    printf("%d", num[i]);
    if(i > 0 && i % 3 == 0)
      printf(",");        //每3位一个逗号，最后一位除外(体现在i > 0)
  }
  return 0;
}
*/


//example
//活用printf格式控制符，简洁的写法如下 步骤1对负数的处理不能省，步骤2可以省下了
#include <cstdio>
int ans[10];

int main() {
  int a, b, sum;
  scanf("%d%d", &a, &b);
  sum = a + b;
  if(sum < 0) {
    printf("-");
    sum = -sum;
  }
  if(sum >= 1000000)
    printf("%d,%03d,%03d", sum / 1000000, sum % 1000000 / 1000, sum % 1000);
  else if(sum >= 1000)
    printf("%d,%03d", sum / 1000, sum % 1000);
  else
    printf("%d", sum);
  return 0;
}
