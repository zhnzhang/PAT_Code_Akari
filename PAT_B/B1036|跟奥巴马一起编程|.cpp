#include <cstdio>

int main() {
    int n;
    char c;
    scanf("%d %c", &n, &c);
    for (int i = 0; i < n; i++) {
        printf("%c", c);
    }
    printf("\n");
    if (n % 2 == 1) {                                   //从奇偶的角度解决四舍五入的要求
        for (int i = 0; i < n / 2 + 1 - 2; i++) {
            printf("%c", c);
            for (int j = 0; j < n - 2; j++) {
                printf(" ");
            }
            printf("%c", c);
            printf("\n");
        }
    } else {
        for (int i = 0; i < n / 2 - 2; i++) {
            printf("%c", c);
            for (int j = 0; j < n - 2; j++) {
                printf(" ");
            }
            printf("%c", c);
            printf("\n");
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%c", c);
    }
    printf("\n");
    return 0;
}




//example
//输出由三部分组成，第1行，第2～row-1行，第row行
//重点说下2～row-1行，先输出一个a再输出col-2个空格，再输出一个a
//技巧！：整数除以2进行四舍五入的操作可以通过判断它是否是奇数来解决，以避免浮点数的介入，省的麻烦。
//当列数col是奇数时，行数row就是col / 2 + 1；当列数col是偶数时，行数row就是col / 2

#include <cstdio>
int main() {
  int row, col; //行、列
  char c;
  scanf("%d %c", &col, &c);   //涉及到字符的输入，输入格式的空格最好照常大，以免出现违背正常逻辑的错误
  if(col % 2 == 1)
    row = col / 2 + 1;
  else
    row = col / 2;
  //第一行
  for(int i = 0; i < col; i++) {
    printf("%c", c);
  }
  printf("\n");
  //2~row-1行
  for(int i = 0; i < row - 2; i++) {
    printf("%c", c);
    for(int j = 0; j < col - 2; j++) {
      printf(" ");
    }
    printf("%c\n", c);
  }
  //最后一行
  for(int i = 0; i < col; i++) {
    printf("%c", c);
  }
  printf("\n");
  return 0;
}
