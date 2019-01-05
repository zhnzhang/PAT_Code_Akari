#include <cstdio>
const int CLK_TCK = 100;

int main() {
  int c1, c2, allss, hh, mm, ss;
  scanf("%d%d", &c1, &c2);
  if((c2 - c1) % 100 >= 50) {             //从元数据解决四舍五入,避免损耗精度,此题重点在此
    allss = (c2 - c1) / CLK_TCK + 1;
  }
  else {
    allss = (c2 - c1) / CLK_TCK;
  }
  hh = allss / 3600;
  mm = allss % 3600 / 60;                 //better use % to solve problem
  ss = allss % 3600 % 60;
  printf("%02d:%02d:%02d", hh, mm, ss);
  return 0;
}


/*
#include <cstdio>
int main() {
  int c1, c2;
  scanf("%d%d", &c1, &c2);
  int ans = c2 - c1;
  if(ans % 100 >= 50) {
    ans = ans / 100 + 1;
  }
  else {
    ans /= 100;
  }
  printf("%02d:%02d:%02d\n", ans / 3600, ans % 3600 /60, ans % 3600 % 60);
  return 0;
}
*/
