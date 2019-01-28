//example
//对其中部分的写法还抱有疑惑
#include <cstdio>
#include <algorithm>
using namespace std;

struct Student {
  int GE, GI, sum;          //初试成绩、面试成绩及成绩总和
  int r, stuID;             //排名、考生编号
  int cho[6];               //K个志愿学校的编号
} stu[40010];

struct School {
  int quota;                //招生人数总额度
  int stuNum;               //当前实际招生人数
  int id[40010];            //招收的学生编号
  int lastAdmit;            //记录最后一个招收的学生编号
} sch[110];

bool cmpStu(Student a, Student b) {
  if(a.sum != b.sum) {
    return a.sum > b.sum;       //总分从高到低排序
  }
  else {
    return a.GE > b.GE;         //总分相同的，按GE从高到低排序
  }
}

bool cmpID(int a, int b) {    //?
  return stu[a].stuID < stu[b].stuID;   //按考生编号从小到大排序，联动后面使用规则的语句进行理解，其实就是抓准所排的是什么，按照什么规则进行排序,形参就是所排的东西
}

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);          //考生人数、学校数及每人可申请的学校数
  for(int i = 0; i < m; i++) {          //初始化每个学校
    scanf("%d", &sch[i].quota);         //输入招生人数总额度
    sch[i].stuNum = 0;                  //当前实际招生人数为0
    sch[i].lastAdmit = -1;              //最后一个招收的学生编号为-1，表示不存在
  }
  for(int i = 0; i < n; i++) {          //初始化每个考生
    stu[i].stuID = i;                   //考生编号为i(从0开始)
    scanf("%d%d", &stu[i].GE, &stu[i].GI);    //初试成绩及面试成绩
    stu[i].sum = stu[i].GE + stu[i].GI;       //总成绩
    for(int j = 0; j < k; j++) {
      scanf("%d", &stu[i].cho[j]);            //K个可申请学校编号
    }
  }
  sort(stu, stu + n, cmpStu);     //给n位考生按成绩排序
  //由于排名从0开始，故采用以下的排名计算逻辑
  for(int i = 0; i < n; i++) {            //计算每个考生的排名
    if(i > 0 && stu[i].sum == stu[i - 1].sum && stu[i].GE == stu[i - 1].GE){
      stu[i].r = stu[i - 1].r;
    }
    else {
      stu[i].r = i;
    }
  }
  for(int i = 0; i < n; i++) {    //对每位考生i，，判断其被哪所学校录取
    for(int j = 0; j < k; j++) {  //枚举考生i的k个选择学校
      int choice = stu[i].cho[j];     //考生i的第j个选择学校编号
      int num = sch[choice].stuNum;   //选择学校的当前招生人数
      int last = sch[choice].lastAdmit;   //选择学校最后一位录取考生编号
      //如果人数未满或该学校最后一个录取的考生与当前考生的排名相同
      if(num < sch[choice].quota || (last != -1 && stu[i].r == stu[last].r)) {
        sch[choice].id[num] = i;      //录取该考生
        sch[choice].lastAdmit = i;    //该学校的最后一个录取考生变为i
        sch[choice].stuNum++;         //当前招生人数加1
        break;
      }
    }
  }
  for(int i = 0; i < m; i++) {        //对m所学校
    if(sch[i].stuNum > 0) {           //如果有招到学生
      //按ID从小到大排序
      sort(sch[i].id, sch[i].id + sch[i].stuNum, cmpID);
      for(int j = 0; j < sch[i].stuNum; j++) {
        printf("%d", stu[sch[i].id[j]].stuID);      //?
        if(j < sch[i].stuNum - 1) {
          printf(" ");
        }
      }
    }
    printf("\n");
  }
  return 0;
}
