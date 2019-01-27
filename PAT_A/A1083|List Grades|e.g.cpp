#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 50;

struct Student {
  char name[11];          //姓名
  char id[11];            //准考证号
  int grade;              //分数
} stu[maxn];

bool cmp(Student a, Student b) {
  return a.grade > b.grade;         //按分数从大到小排序
}

int main() {
  int n, left, right;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%s %s %d", stu[i].name, stu[i].id, &stu[i].grade);
  }
  scanf("%d %d", &left, &right);        //区分左右端点
  //先排序，再枚举
  sort(stu, stu + n, cmp);
  bool flag = false;                    //flag记录是否存在[left, right]内的考生
  for(int i = 0; i < n; i++) {
    if(stu[i].grade >= left && stu[i].grade <= right) {     //以后写if语句最好还是打上括号，以便逻辑梳理
      printf("%s %s\n", stu[i].name, stu[i].id);
      flag = true;            //存在[left, right]范围的考生
    }
  }
  if(flag == false) {
    printf("NONE\n");
  }
  return 0;
}
