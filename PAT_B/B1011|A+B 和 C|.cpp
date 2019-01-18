#include <cstdio>
int main(){
  int T;
  long long A[20], B[20], C[20];
  scanf("%d", &T);
  for(int i = 0; i < T; i++) {
    scanf("%lld%lld%lld", &A[i], &B[i], &C[i]);
  }
  for(int i = 0; i < T; i++) {
    if(A[i] + B[i] > C[i]) {
      printf("Case #%d: true\n", i + 1);
    }
    else {
      printf("Case #%d: false\n", i + 1);
    }
  }
  return 0;
}




/*
#include <cstdio>                     //这里单点测试，输出是按照输出样例这样一整组还是说可以一组输入一组输出？这关系到写法
int main() {                          //下面的是书上给的代码
  int T, tcase = 1;
  long long a, b, c;
  scanf("%d", &T);
  while(T--) {
    scanf("%lld%lld%lld", &a, &b, &c);
    if(a + b > c) {
      printf("Case #%d: true\n", tcase++);
    }
    else {
      printf("Case #%d: false\n", tcase++);
    }
  }
  return 0;
}
*/
