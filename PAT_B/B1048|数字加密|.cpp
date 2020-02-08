#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

void reverse(char str[]) {                  //反转字符串
    int len = strlen(str);
    char tmp;
    for (int i = 0; i < len / 2; i++) {
        tmp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = tmp;
    }
}

int main() {
    int lena = 0, lenb = 0, len = 0;
    char a[110], b[110], ans[110];
    scanf("%s %s", a, b);
    reverse(a);
    reverse(b);                 //反转后由于从0号位开始，题意中的奇偶数位处理方法要交换一下才能对得上
    lena = strlen(a);
    lenb = strlen(b);
    len = lena > lenb ? lena : lenb;
    fill(a + lena, a + 102, '0');       //用于多出的位数的处理
    fill(b + lenb, b + 102, '0');
    fill(ans + len, ans + 102, '\0');   //放好初值以防干扰
    for (int i = 0; i < len; i++) {
        int numa = a[i] - '0';
        int numb = b[i] - '0';
        int sum = 0;
        if (i % 2 == 0) {       //由于反转，用奇数位处理方法
            sum = numa + numb;
            sum %= 13;
            if (sum == 10) {
                ans[i] = 'J';
            } else if (sum == 11) {
                ans[i] = 'Q';
            } else if (sum == 12) {
                ans[i] = 'K';
            } else {
                ans[i] = '0' + sum;
            }
        } else {                //由于反转，用偶数位处理方法
            if (numb - numa < 0) {
                ans[i] = '0' + (numb - numa + 10);
            } else {
                ans[i] = '0' + (numb - numa);
            }
        }
    }
    reverse(ans);       //再反转一次才能回归原位
    printf("%s\n", ans);
    return 0;
}



//example
//为方便整数对齐和让最低位从数组0号开始，首先将字符串反转,处理好加密后，输出时，应将char型数组ans[]再反转进行输出
//因为反转后的情况且字符串下标从0开始，要根据题设有针对性的调整
//本题中的reverse操作是自行写函数，而不是使用STL中的reverse函数
#include <cstdio>
#include <cstring>
const int maxn = 110;
char A[maxn], B[maxn], ans[maxn] = {0};

void reverse(char s[]) {      //反转字符串
  int len = strlen(s);
  for(int i = 0; i < len / 2; i++) {    //由于字符串下标从0开始，故这里不能写成i <= len / 2
    int temp = s[i];
    s[i] = s[len - 1 - i];
    s[len - 1 - i] = temp;
  }
}

int main() {
  scanf("%s %s", A, B);     //整数A和B，一般%s的格式控制符，就按照输入的格式写吧，该空格的空格，以免误伤
  reverse(A);         //将A和B反转，使整数对齐
  reverse(B);
  int lenA = strlen(A);   //A和B对应的长度
  int lenB = strlen(B);
  int len = lenA > lenB ? lenA : lenB;      //A和B的较大长度
  for(int i = 0; i < len; i++) {        //从低位开始（核心处理代码部分）
    int numA = i < lenA ? A[i] - '0' : 0;     //numA对应A[i], 字符转数字
    int numB = i < lenB ? B[i] - '0' : 0;     //numB对应B[i]
    if(i % 2 == 0) {          //当前位是偶数，对应题设奇数要求
      int temp = (numA + numB) % 13;      //和再模上13
      if(temp == 10) {      //特判10、11、12 往结果字符数组里放
        ans[i] = 'J';
      }
      else if(temp == 11) {
        ans[i] = 'Q';
      }
      else if(temp == 12) {
        ans[i] = 'K';
      }
      else {
        ans[i] = temp + '0';    //0～9
      }
    }
    else {            //当前位i是奇数，对应题设偶数要求
      int temp = numB - numA;   //差
      if(temp < 0)
        temp += 10;           //如果小于0，则加上10
      ans[i] = temp + '0';    //勿忘进行转换，赋上对应字符
    }
  }
  reverse(ans);     //反转结果字符串，符合题目要求的格式
  puts(ans);      //输出结果
  return 0;
}
