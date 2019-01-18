#include <cstdio>
const int max_n = 100010;
int school[max_n] = {0};    //这个数量级的数组要定义在主函数外面

int main() {
  int n, id, score;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d %d", &id, &score);
    school[id] += score;
  }
  int k = 0, max = -1;
  for(int i = 0; i < max_n; i++) {
    if(school[i] > max) {
      k = i;
      max = school[i];
    }
  }
  printf("%d %d", k, max);
  return 0;
}

/*
example
#include <cstdio>
const int maxn = 100010;
int school[maxn] = {0};   //记录每个学校的总分

int main() {
  int n, schID, score;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d%d", &schID, &score);  //学校ID、分数
    school[schID] += score;     //学校schID的总分增加score
  }
  int k = 1, MAX = -1;
  for(int i = 1; i <=n; i++) {
    if(school[i] > MAX) {
      MAX = school[i];
      k = i;
    }
  }
  printf("%d %d\n", k, MAX);
  return 0;
}
*/
