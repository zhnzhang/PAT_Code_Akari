#include <cstdio>

typedef struct student {
    char name[6];
    int year;
    int month;
    int day;
}student;

student stu[100010];

bool ValidCheck(int year, int month, int day) {                 //日期合法性检验
    int tmp = year * 10000 + month * 100 + day;                 //位数看好
    if (tmp <= 20140906 && tmp >= 18140906) {                   //这里等号要的,才符合题意
        return true;
    } else {
        return false;
    }
}

int ChangeStyle(int year, int month, int day) {                 //方便比较日期大小
    return year * 1000 + month * 100 + day;
}

int main() {
    int n, count = 0;                   //count计数合法的日期数
    int max = 100, min = 30000000;      //用于存储最年轻和最老的日期的方便比较的形式
    int max_id = 0, min_id = 0;         //max对应最年轻，min对应最老
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d/%d/%d", stu[i].name, &stu[i].year, &stu[i].month, &stu[i].day);
        if (ValidCheck(stu[i].year, stu[i].month, stu[i].day)) {
            count++;
        } else {
            continue;
        }
        int tmp = ChangeStyle(stu[i].year, stu[i].month, stu[i].day);
        if (tmp > max) {
            max = tmp;
            max_id = i;
        }
        if (tmp < min) {
            min = tmp;
            min_id = i;
        }
    }
    if (count == 0) {
        printf("0\n");                              //测试点3的考察点，没考虑这个特殊情况的输出就会错误
    } else {
        printf("%d %s %s\n", count, stu[min_id].name, stu[max_id].name);        //注意min对应最老，max对应最年轻
    }
    return 0;
}




//Example
//最年长==时间最小，最年轻==时间最大
//最后最好不要有空余空格，虽然本题没有明确要求
//边读边做
//本题对特殊情况要考虑到并作出特判

#include <cstdio>
struct person {
  char name[10];
  int yy, mm, dd;
} temp, left, right, oldest, youngest;    //left,right存放合理日期的左右边界

//把比较操作写成函数能让主函数更简洁明了

bool LessEqu(person a, person b) {        //如果a的日期小于等于b，返回true
  if(a.yy != b.yy)
    return a.yy <= b.yy;
  else if(a.mm != b.mm)
    return a.mm <= b.mm;
  else
    return a.dd <= b.dd;
}

bool MoreEqu(person a, person b) {
  if(a.yy != b.yy)
    return a.yy >= b.yy;
  else if(a.mm != b.mm)
    return a.mm >= b.mm;
  else
    return a.dd >= b.dd;
}

//对目标变量的初值设定有小技巧，比如这里。youngest与left为1814年9月6日，oldest与right为2014年9月6日
void init() {
  youngest.yy = left.yy = 1814;
  oldest.yy = right.yy = 2014;
  youngest.mm = left.mm = oldest.mm = right.mm = 9;
  youngest.dd = left.dd = oldest.dd = right.dd = 6;
}

int main() {
  init(); //初始化
  int n, num = 0; //num存放合理日期的人数
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%s %d/%d/%d", temp.name, &temp.yy, &temp.mm, &temp.dd);
    if(MoreEqu(temp, left) && LessEqu(temp, right)) {   //判断时间是否合理
      num++;
      if(MoreEqu(temp, youngest))     //等价条件:最年长==时间最小，最年轻==时间最大
        youngest = temp;
      if(LessEqu(temp, oldest))
        oldest = temp;
    }
  }
  if(num == 0)
    printf("0\n");    //特殊情况特判！所有人的日期都不合理，只输出0
  else
    printf("%d %s %s\n", num, oldest.name, youngest.name);
  return 0;
}
