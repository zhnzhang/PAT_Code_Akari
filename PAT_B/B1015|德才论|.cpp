#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct student {
    char id[10];
    int de;
    int cai;
    int type;           //给考生分类
}student;

student stu[100010];

bool cmp(student a, student b) {    //通过if else设定多重排序规则
    if (a.type != b.type) {
        return a.type < b.type;
    } else if ((a.de + a.cai) != (b.de + b.cai)) {
        return (a.de + a.cai) > (b.de + b.cai);
    } else if (a.de != b.de) {
        return a.de > b.de;
    } else {
        return strcmp(a.id, b.id) < 0;
    }
}

int main () {
    int n, m, l, h;                     //m为及格人数
    scanf("%d %d %d", &n, &l, &h);
    m = n;
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", stu[i].id, &stu[i].de, &stu[i].cai);
        if (stu[i].de >= h && stu[i].cai >= h) {
            stu[i].type = 1;
        } else if (stu[i].de >= h && stu[i].cai >= l) {
            stu[i].type = 2;
        } else if (stu[i].de >= stu[i].cai && stu[i].cai >= l) {
            stu[i].type = 3;
        } else if (stu[i].de < l || stu[i].cai< l) {
            stu[i].type = 5;        //不及格
            m--;
        } else {
            stu[i].type = 4;
        }
    }
    sort(stu, stu + n, cmp);
    printf("%d\n", m);
    for (int i = 0; i < n; i++) {
        if (stu[i].type != 5) {
            printf("%s %d %d\n", stu[i].id, stu[i].de, stu[i].cai);
        }
    }
    return 0;
}



//example
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Student {
  char id[10];          //准考证号
  int de, cai, sum;     //德分，才分及总分
  int flag;             //考生类别:第1类--第5类 第4类最好放最后鉴别
} stu[100010];

bool cmp(Student a, Student b) {
  if(a.flag != b.flag)
    return a.flag < b.flag;         //类别小的在前
  else if(a.sum != b.sum)
    return a.sum > b.sum;           //类别相同时，总分大的在前
  else if(a.de != b.de)
    return a.de > b.de;             //总分相同时，德分大的在前
  else
    return strcmp(a.id, b.id) < 0;  //德分相同时，准考证号小的在前
}

int main() {
  int n, L, H;
  scanf("%d%d%d", &n, &L, &H);
  int m = n;                        //m是及格人数
  for(int i = 0; i < n; i++) {
    scanf("%s %d %d", stu[i].id, &stu[i].de, &stu[i].cai);
    stu[i].sum = stu[i].de + stu[i].cai;              //计算总分
    //考生分类
    if(stu[i].de < L || stu[i].cai < L) {     //先将不及格者设为第5类
      stu[i].flag = 5;
      m--;                            //及格人数减1
    }
    else if(stu[i].de >= H && stu[i].cai >= H)
      stu[i].flag = 1;
    else if(stu[i].de >= H && stu[i].cai < H)
      stu[i].flag = 2;
    else if(stu[i].de >= stu[i].cai)              //区别else if 与多个if的语句逻辑，一个成立后就离开语句块，一个成立了后还是继续按序运行
      stu[i].flag = 3;
    else
      stu[i].flag = 4;                  //第4类情况最多，因此放在最后
  }
  sort(stu, stu + n, cmp);        //排序
  printf("%d\n", m);
  for(int i = 0; i < m; i++) {
    printf("%s %d %d\n", stu[i].id, stu[i].de, stu[i].cai);
  }
  return 0;
}
