#include <cstdio>

typedef struct student {
    char name[15];
    char gender;
    char stuid[15];
    int score;
}student;

student stu[1010];

int main() {
    int n, girl_count = 0, boy_count = 0;                                   //计数
    int max_girl_id = 0, min_boy_id = 0, max_score = -1, min_score = 110;   //max对应girl，min对应boy
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %c %s %d", stu[i].name, &stu[i].gender, stu[i].stuid, &stu[i].score);
        if (stu[i].gender == 'M') {
            boy_count++;
            if (stu[i].score < min_score) {
                min_boy_id = i;
                min_score = stu[i].score;
            }
        } else {
            girl_count++;
            if (stu[i].score > max_score) {
                max_girl_id = i;
                max_score = stu[i].score;
            }
        }
    }
    if (girl_count == 0) {
        printf("Absent\n");
    } else {
        printf("%s %s\n", stu[max_girl_id].name, stu[max_girl_id].stuid);
    }
    if (boy_count == 0) {
        printf("Absent\n");
    } else {
        printf("%s %s\n", stu[min_boy_id].name, stu[min_boy_id].stuid);
    }
    if (girl_count == 0 || boy_count == 0) {
        printf("NA\n");
    } else {
        printf("%d\n", max_score - min_score);
    }
}





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
