//本题就是进制转换和回文数判断的结合
//前者用除基取余法(do...while)，后者利用数组指针完成
#include <cstdio>
int ans[40];

int main() {
  int n, b;
  scanf("%d%d", &n, &b);
  int num = 0;
  do {
    ans[num++] = n % b;
    n /= b;
  } while(n != 0);
  int i, j;
  for(i = 0, j = num - 1; i != j; i++, j--) {
    if(ans[i] == ans[j])
      continue;
    else
      break;
  }
  if(i == j)
    printf("Yes\n");
  else
    printf("No\n");
  for(i = num - 1; i >= 0; i--) {
    printf("%d", ans[i]);
    if(i != 0)
      printf(" ");
  }
  return 0;
}

/*
//example
//例子用的判断回文数的方法，即比较位置i与其对称位置num - 1 - i的数字是否相同，只要有一对位置不相同，就说明不是回文数
//与我的方法相比，它只用一个变量充当指针，利用对称性
#include <cstdio>

bool Judge(int z[], int num) {    //判断数组z所存的数是否为回文数，num为位数
  for(int i = 0; i <= num / 2; i++) {
    if(z[i] != z[num - 1 -i]) {   //如果位置i与其对称位置num - 1 - i不相同
      return false;
    }
  }
  return true;                    //所有对称位置都相同
}

int main() {
  int n, b, z[40], num = 0;   //数组z存放转换结果，num为其位数
  scanf("%d%d", &n, &b);      //输入题目给定的n与b
  do {                        //将n转换为b进制，结果存在数组z中
    z[num++] = n % b;         //除基取余
    n /= b;
  } while(n != 0);            //当n变为0时退出循环
  bool flag = Judge(z, num);  //判断数组z保存的数是否回文
  if(flag == true)
    printf("Yes\n");          //回文
  else
    printf("No\n");           //不回文
  for(int i = num - 1; i >= 0; i--) {     //输出数组z
    printf("%d", z[i]);
    if(i != 0)
      printf(" ");
  }
  return 0;
}
*/
