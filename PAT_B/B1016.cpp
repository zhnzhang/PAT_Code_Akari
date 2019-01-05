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


/*
#include <cstdio>
int main() {
  long long a, b, da, db;
  scanf("%lld%lld%lld%lld", &a, &da, &b, &db);
  long long pa = 0, pb = 0;
  while(a != 0) {                 //枚举a的每一位
    if(a % 10 == da) {            //如果当前位为da,给pa增加一位da
      pa = pa * 10 + da;
      a = a / 10;
    }
  }
  while(b != 0) {                 //枚举b的每一位
    if(b % 10 == db) {            //如果当前位为db,给pb增加一位db
      pb = pb * 10 + db;
      b = b / 10;
    }
  }
  printf("%lld\n", pa + pb);
  return 0;
}
*/
