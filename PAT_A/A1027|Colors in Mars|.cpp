#include <cstdio>
//做一个基数映射数组来实现题意

char radix [15] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};

void ChangeScale(int a[], int n) {          //十进制转十三进制，字母的实现借由基数映射数组来进行
    int i = 0;
    do {
        a[i++] = n % 13;
        n /= 13;
    } while (n != 0);
}

int main() {
    int r, g, b;
    int red[5] = {0}, green[5] = {0}, blue[5] = {0};
    scanf("%d %d %d", &r, &g, &b);
    ChangeScale(red, r);
    ChangeScale(green, g);
    ChangeScale(blue, b);
    printf("#%c%c%c%c%c%c\n", radix[red[1]], radix[red[0]],
           radix[green[1]], radix[green[0]], radix[blue[1]], radix[blue[0]]);
    return 0;
}


//example
//由于题目的数据范围为[0, 168]，因此给定的整数x在十三进制下一定可以表示为x = a * 13^1 + b * 13^0(因为168 < 13^2)，于是只要想办法求出a跟b即可
//本题也可以采用正常的进制转换写法，然后输出转换的结果（同时要根据位数来确认是否需要输出多余的0）
#include <cstdio>
char radix[13] = {    //建立0～13与'0'～'9'、'A'、'B'、'C'的关系  radix意为基数
  '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'
};
int main() {
  int r, g, b;    //这个变量名可以
  scanf("%d%d%d", &r, &g, &b);
  printf("#");
  //输出radix[a], radix[b]
  printf("%c%c", radix[r / 13], radix[r % 13]);
  printf("%c%c", radix[g / 13], radix[g % 13]);
  printf("%c%c", radix[b / 13], radix[b % 13]);
  return 0;
}

/*
//自炊，有两个例子没过，总体部分正确 得分16/20
#include <cstdio>
char mp[3] = {'A', 'B', 'C'};

int main() {
  int a[3], ans[10] = {0}, num = 0;
  scanf("%d %d %d", &a[0], &a[1], &a[2]);
  for(int i = 0; i < 3; i++) {
    do {
      ans[num++] = a[i] % 13;
      a[i] /= 13;
    } while(a[i] != 0);
  }
  printf("#");
  for(int i = 0; i < 6; i += 2) {
    for(int j = 1; j >= 0; j--) {
      if(ans[i + j] == 10)
        printf("%c", mp[0]);
      else if(ans[i + j] == 11)
        printf("%c", mp[1]);
      else if(ans[i + j] == 12)
        printf("%c", mp[2]);
      else
        printf("%d", ans[i + j]);
    }
  }
  return 0;
}
*/
