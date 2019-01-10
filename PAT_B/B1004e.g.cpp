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
