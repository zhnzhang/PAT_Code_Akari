#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct student {
    char id[10];
    int score[5];             //平均分是四舍五入的，这里我用总分替代，因为线性相关的，所以效果是一样的
    int rank[5];              //顺序就按a c m e 对 0 1 2 3吧
}student;

student stu[2020];
int now;                        //全局变量，用于数据的同步处理!重要的点
char mp[5] = {'A', 'C', 'M', 'E'};

bool cmp(student a, student b) {
    return a.score[now] > b.score[now];
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d", stu[i].id, &stu[i].score[1], &stu[i].score[2], &stu[i].score[3]);
        stu[i].score[0] = stu[i].score[1] + stu[i].score[2] + stu[i].score[3];
    }
    for (now = 0; now < 4; now++) {
        sort(stu, stu + n, cmp);
        stu[0].rank[now] = 1;
        for (int i = 1; i < n; i++) {           //常用的作排名的方法，现成的
            if (stu[i].score[now] == stu[i - 1].score[now]) {
                stu[i].rank[now] = stu[i - 1].rank[now];
            } else {
                stu[i].rank[now] = i + 1;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        char str[10];
        bool flag = false;  //标记是否找到
        scanf("%s", str);
        for (int j = 0; j < n; j++) {
            if (!strcmp(str, stu[j].id)) { //这里特别标注：要做字符串的比较最好用strcmp，我直接用==就做不出答案，可能因为没有初始化
                flag = true;
                int min = n + 1;            //最靠前的名次，因为我的顺序是排好的，所以逻辑上没有问题
                int u;                      //用来记录最考前的名次是哪种分数对应的
                for (int k = 0; k < 4; k++) {
                    if (stu[j].rank[k] < min) {         //得是 < 才行
                        min = stu[j].rank[k];
                        u = k;
                    }
                }
                printf("%d %c\n", min, mp[u]);
                break;
            }
        }
        if (flag == false) {
            printf("N/A\n");
        }
    }
    return 0;
}





//example
//相关数据结构要设置好
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct Student {
  int id;     //存放6位整数的ID
  int grade[4];     //存放4个分数,0~3号
} stu[2010];

char course[4] = {'A', 'C', 'M', 'E'};      //按优先级顺序，方便输出
int Rank[1000000][4] = {0};     //Rank[id][0]~Rank[id][3]为4门课对应的排名，初值赋为0.这个级别的数组还是要在主函数外面定义,不要忽略这个数组的设置
int now;          //cmp函数中使用，表示当前按now号分数排列stu数组，不要忽略这个变量的设置

bool cmp(Student a, Student b) {        //stu数组按now号分数递减排序,这种cmp的用法需要掌握，利用变量进行的
  return a.grade[now] > b.grade[now];
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  //读入分数，其中grade[0]~grade[3]分别代表A、C、M、E,要对应好顺序
  for(int i = 0; i < n; i++) {
    scanf("%d%d%d%d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
    stu[i].grade[0] = round((stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3]) / 3.0);
  }
  //读入分数完成后，进行枚举分数排名
  for(now = 0; now < 4; now++) {    //枚举A、C、M、E 4个中的一个进行排名
    sort(stu, stu + n, cmp);        //对所有考生按该分数从大到小排序
    Rank[stu[0].id][now] = 1;       //排序完，将分数最高的设为rank1
    for(int i = 1; i < n; i++) {    //对于剩下的考生
      //若与前一位考生分数相同
      if(stu[i].grade[now] == stu[i - 1].grade[now]) {
        Rank[stu[i].id][now] = Rank[stu[i - 1].id][now];    //则他们排名相同
      }
      else {
        Rank[stu[i].id][now] = i + 1;   //否则，为其设置为正确的排名（数组下标加1）（前提数组下标从0开始）
      }
    }
  }
  int query;      //查询的考生ID
  for(int i = 0; i < m; i++) {
    scanf("%d", &query);
    if(Rank[query][0] == 0) {     //如果这个考生ID不存在，则输出"N/A"(Rank数组中对应ID那一行如果是不存在考生的话，应该哪项都是之前赋的初值0才对)
      printf("N/A\n");
    }
    else {
      int k = 0;          //选出Rank[query][0~3]中最小的(rank值越小，排名愈高)
      for(int j = 0; j < 4; j++) {
        if(Rank[query][j] < Rank[query][k])
          k = j;
      }
      printf("%d %c\n", Rank[query][k], course[k]);
    }
  }
  return 0;
}
