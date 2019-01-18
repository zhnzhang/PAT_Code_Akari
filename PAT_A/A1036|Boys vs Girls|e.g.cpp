//example 边读边更新，目标变量反向设置初值

#include <cstdio>
struct person {
  char name[15];
  char id[15];
  int score;
} temp, M, F; //M为男生最低分数的信息，F为女生最高分数的信息

void init() {
  M.score = 101;  //初始化男生最低分数为较大值101
  F.score = -1;   //初始化女生最高分数为较小值-1
}

int main() {
  init(); //初始化
  int n;
  char gender;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%s %c %s %d", temp.name, &gender, temp.id, &temp.score);
    if(gender == 'M' && temp.score < M.score)
      M = temp;
    else if(gender == 'F' && temp.score > F.score)      //选用else if是因为每读入的是一行，这两种情况只用判断其中一种.故不选两句if
      F = temp;
  }
  if(F.score == -1)
    printf("Absent\n");
  else
    printf("%s %s\n", F.name, F.id);
  if(M.score == 101)
    printf("Absent\n");
  else
    printf("%s %s\n", M.name, M.id);
  if(F.score == -1 || M.score == 101)
    printf("NA");
  else
    printf("%d\n", F.score - M.score);
  return 0;
}
