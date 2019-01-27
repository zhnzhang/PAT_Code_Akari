//example
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 10010;

struct Student {
  int id;               //准考证号
  int score[6];         //每道题的得分
  bool flag;            //是否有能通过编译的提交
  int score_all;        //总分
  int solve;            //完美解题数
} stu[maxn];

int n, k, m;            //n位考生，k道题，m个提交记录,全局变量
int full[6];            //每道题的满分

bool cmp(Student a, Student b) {
  if(a.score_all != b.score_all)
    return a.score_all > b.score_all;
  else if(a.solve != b.solve)
    return a.solve > b.solve;
  else
    return a.id < b.id;
}

void init() {           //初始化
  for(int i = 1; i <= n; i++) {
    stu[i].id = i;              //准考证号记为i
    stu[i].score_all = 0;       //总分初始化为0
    stu[i].solve = 0;           //完美解题数初始化为0
    stu[i].flag = false;        //初始化为没有能通过编译的提交
    memset(stu[i].score, -1, sizeof(stu[i].score));     //题目得分记为-1
  }
}

int main() {
  scanf("%d%d%d", &n, &k, &m);
  init();
  for(int i = 1; i <= k; i++) {         //从1开始
    scanf("%d", &full[i]);
  }
  int u_id, p_id, score_obtained;       //考生ID、题目ID及所获分值
  for(int i = 0; i < m; i++) {          //连续的if语句是因为每种情况都要考虑去做
    scanf("%d%d%d", &u_id, &p_id, &score_obtained);
    if(score_obtained != -1) {          //若不是编译错误，则该考生有能通过编译的提交
      stu[u_id].flag = true;
    }
    if(score_obtained == -1 && stu[u_id].score[p_id] == -1) {
      //某题 第一次 编译错误 (这是区别于没提交)，分值记为0分，便于输出
      stu[u_id].score[p_id] = 0;
    }
    if(score_obtained == full[p_id] && stu[u_id].score[p_id] < full[p_id]) {
      stu[u_id].solve++;                //某题第一次获得满分，则完美解题数加1
    }
    if(score_obtained > stu[u_id].score[p_id]) {
      stu[u_id].score[p_id] = score_obtained;
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= k; j++) {
      if(stu[i].score[j] != -1) {       //计算总分
        stu[i].score_all += stu[i].score[j];
      }
    }
  }
  sort(stu + 1, stu + n + 1, cmp);      //按要求排序
  //计算排名
  int r = 1;                            //当前排名
  for(int i = 1; i <= n && stu[i].flag == true; i++) {
    if(i > 1 && stu[i].score_all != stu[i - 1].score_all) {
    //当前考生分数低于前一位考生分数，则排名为该考生之前的总考生数
      r = i;
    }
    printf("%d %05d %d", r, stu[i].id, stu[i].score_all);
    for(int j = 1; j <= k; j++) {
      if(stu[i].score[j] == -1) {
        printf(" -");                   //没有过提交
      }
      else {
        printf(" %d", stu[i].score[j]);
      }
    }
    printf("\n");
  }
  return 0;
}
