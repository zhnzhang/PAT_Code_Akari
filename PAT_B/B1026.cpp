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
  mm = (allss - hh * 3600) / 60;
  ss = (allss - hh * 3600) % 60;
  printf("%02d:%02d:%02d", hh, mm, ss);
  return 0;
}
