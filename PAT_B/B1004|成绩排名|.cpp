#include <cstdio>

typedef struct student {
    char name[15];
    char id[15];
    int score;
}student;

student stu[1010];

int main() {
    int n;
    int max = -1, max_id = 0;               //max记录最高分，max_id记录最高分学生的存储在数组中的下标，反向设置初值
    int min = 110, min_id = 0;              //min记录最低分，min_id记录最低分学生的存储在数组中的下标，反向设置初值
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %s %d", stu[i].name, stu[i].id, &stu[i].score);
        if (stu[i].score > max) {
            max = stu[i].score;             //相应的要更新
            max_id = i;
        }
        if (stu[i].score < min) {
            min = stu[i].score;
            min_id = i;
        }
    }
    printf("%s %s\n", stu[max_id].name, stu[max_id].id);
    printf("%s %s\n", stu[min_id].name, stu[min_id].id);
    return 0;
}






//Example
//字符数组name和id的大小必须至少是11而不能设为10，否则第一个数据和最后一个数据会得到答案错误。
//这是因为字符数组的最后一位需要预留给'\0'，所以数组大小必须比题目要求的大小至少大1位
//如果采用存储所有数据然后排序的方法，结构体数组的大小至少需要101，不然最后一组数据会“运行超时”。
//本算法是边读边做的

#include <cstdio>
struct Student {
  char name[15];
  char id[15];
  int score;
} temp, ans_max, ans_min;
//temp存放临时数据，ans_max为最高分数的学生、ans_min为最低分数的学生

int main() {
  int n;
  scanf("%d", &n);
  ans_max.score = -1;
  ans_min.score = 101;
  for(int i = 0; i < n; i++) {
    scanf("%s%s%d", temp.name, temp.id, &temp.score);
    if(temp.score > ans_max.score) {
      ans_max = temp;
    }
    if(temp.score < ans_min.score) {
      ans_min = temp;
    }
  }
  printf("%s %s\n", ans_max.name, ans_max.id);
  printf("%s %s\n", ans_min.name, ans_min.id);
  return 0;
}
