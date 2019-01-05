#include <cstdio>

int main() {
  long long A, B, Apart = 0, Bpart = 0;
  int a, b, anum = 0, bnum = 0;
  scanf("%lld%d%lld%d", &A, &a, &B, &b);
  while(A != 0) {                         //may ignore != 0
    if(A % 10 == a) {
      anum++;
      A = A / 10;
    }
    else {
      A = A / 10;
    }
  }
  while(B != 0) {                         //may ignore != 0
    if(B % 10 == b) {
      bnum++;
      B = B / 10;
    }
    else {
      B = B / 10;
    }
  }
  for(int i = 0; i < anum; i++) {
    Apart = 10 * Apart + a;
  }
  for(int i = 0; i < bnum; i++) {
    Bpart = 10 * Bpart + b;
  }
  printf("%lld\n", Apart + Bpart);
  return 0;
}
