//Example
#include <cstdio>
const int maxn = 1110;
struct Student {
  long long id; //准考证号
  int examseat; //考试座位号
} testseat[maxn]; //以试机座位号作为数组下标来记录考生

int main() {
  int n, m, seat, examseat;
  long long id;
  scanf("%d", &n);  //考生人数
  for(int i = 0; i < n; i++) {
    scanf("%lld%d%d", &id, &seat, &examseat); //准考证号，试机座位号，考试座位号
    testseat[seat].id = id;
    testseat[seat].examseat = examseat;
  }
  scanf("%d", &m);  //查询个数
  for(int i = 0; i < m; i++) {
    scanf("%d", &seat);                       //欲查询的试机座位号，以此位下标直接查找考生
    printf("%lld %d\n", testseat[seat].id, testseat[seat].examseat);
  }
  return 0;
}
