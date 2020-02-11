#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct student {
    char regnum[15];
    int finrank;
    int locnum;
    int locrank;
    int score;
}student;

student stu[50000];

bool cmp(student a, student b) {
    if (a.score != b.score)
        return a.score > b.score;
    else
        return strcmp(a.regnum, b.regnum) < 0;      //按字典序从小到大
}

int main() {
    int n, count = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {              //分批进行
        int m;
        scanf("%d", &m);
        for (int j = count; j < count + m; j++) {               //每个考场内先做好处理
            scanf("%s %d", stu[j].regnum, &stu[j].score);
            stu[j].locnum = i;
        }
        sort(stu + count, stu + count + m, cmp);
        stu[count].locrank = 1;
        for (int j = count + 1; j < count + m; j++) {
            if (stu[j].score == stu[j - 1].score) {
                stu[j].locrank = stu[j - 1].locrank;
            } else {
                stu[j].locrank = j - count + 1;
            }
        }
        count += m;
    }
    sort(stu, stu + count, cmp);            //总排序
    stu[0].finrank = 1;
    for (int i = 1; i < count; i++) {
        if (stu[i].score == stu[i - 1].score) {
            stu[i].finrank = stu[i - 1].finrank;
        } else {
            stu[i].finrank = i + 1;
        }
    }
    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        printf("%s %d %d %d\n", stu[i].regnum, stu[i].finrank, stu[i].locnum, stu[i].locrank);
    }
    return 0;
}



//example
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Student {
  char id[15];          //准考证号
  int score;            //分数
  int location_number;  //考场号
  int local_rank;       //考场内排名
} stu[30010];

bool cmp(Student a, Student b) {
  if(a.score != b.score)
    return a.score > b.score;             //先按分数从高到低排序
  else
    return strcmp(a.id, b.id) < 0;        //分数相同按准考证号从小到大排序
}

int main() {
  int n, k, num = 0;            //k为当前考场人数，num为总考生数
  scanf("%d", &n);              //n为考场数
  for(int i = 1; i <= n; i++) {
    scanf("%d", &k);          //当前考场人数
    for(int j = 0; j < k; j++) {
      scanf("%s %d", stu[num].id, &stu[num].score);
      stu[num].location_number = i;
      num++;
    }
    sort(stu + num - k, stu + num, cmp);    //将该考场的考生排序
    stu[num - k].local_rank = 1;            //该考场第1名的local_rank记为1
    for(int j = num - k + 1; j < num; j++) {      //对该考场剩余的考生
      if(stu[j].score == stu[j - 1].score) {      //如果与前一位考生同分
        stu[j].local_rank = stu[j - 1].local_rank;    //local_rank也相同
      }
      else {          //如果与前一位考生不同分
        stu[j].local_rank = j - (num - k) + 1;    //local_rank为该考生前的人数（算上自己吧）
      }
    }
  }
  printf("%d\n", num);      //输出总考生数
  sort(stu, stu + num, cmp);  //将所有考生排序
  int r = 1;      //当前考生的排名
  for(int i = 0; i < num; i++) {
    if(i > 0 && stu[i].score != stu[i - 1].score)
      r = i + 1;
    printf("%s ", stu[i].id);
    printf("%d %d %d\n", r, stu[i].location_number, stu[i].local_rank);
  }
  return 0;
}
