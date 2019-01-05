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
