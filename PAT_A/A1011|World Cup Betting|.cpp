#include <cstdio>

int main() {
    double w, t, l;
    double a[5] = {0};                          //存储每场比赛最大的那个数字
    for (int i = 0; i < 3; i++) {
        scanf("%lf %lf %lf", &w, &t, &l);
        if (w > t && w > l) {
            a[i] = w;
            printf("W ");
        } else if (t > w && t > l) {
            a[i] = t;
            printf("T ");
        } else {
            a[i] = l;
            printf("L ");
        }
    }
    printf("%.2f\n", (a[0] * a[1] * a[2] * 0.65 - 1) * 2);
    return 0;
}


//example
#include <cstdio>
char mp[3] = {'W', 'T', 'L'};

int main() {
  double ans = 1.0, tmp, a;
  int idx;  //记录每行最大数字的下标
  for(int i = 0; i < 3; i++) {
    tmp = 0.0;
    for(int j = 0; j < 3; j++) {    //寻找该行最大的数字存于tmp
      scanf("%lf", &a);
      if(a > tmp) {
        tmp = a;
        idx = j;
      }
    }
    ans *= tmp;
    printf("%c ", mp[idx]);
  }
  printf("%.2f\n", (ans * 0.65 - 1) * 2);
  return 0;
}
