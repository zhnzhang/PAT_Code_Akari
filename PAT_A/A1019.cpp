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
*/
