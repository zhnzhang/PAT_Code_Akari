#include <cstdio>

int mp[100010] = {0};                       //下标学校标号（从1开始），内容是总分

int main() {
    int n, id, score;
    int max_id = 1, max_score = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &id, &score);
        mp[id] += score;
        if (mp[id] > max_score) {
            max_score = mp[id];
            max_id = id;
        }
    }
    printf("%d %d\n", max_id, max_score);
    return 0;
}


#include <cstdio>
int sum[100002] = {0};

int main() {
    int N, school, score, maxschool, maxscore = -1;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &school, &score);
        sum[school] += score;
    }
    for (int i = 1; i <= N; i++) {
        if (sum[i] > maxscore) {
            maxschool = i;
            maxscore = sum[i];
        }
    }
    printf("%d %d\n", maxschool, maxscore);
    return 0;
}



#include <cstdio>
const int max_n = 100010;
int school[max_n] = {0};    //这个数量级的数组要定义在主函数外面

int main() {
  int n, id, score;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d %d", &id, &score);
    school[id] += score;
  }
  int k = 0, max = -1;
  for(int i = 0; i < max_n; i++) {
    if(school[i] > max) {
      k = i;
      max = school[i];
    }
  }
  printf("%d %d", k, max);
  return 0;
}

/*
example
#include <cstdio>
const int maxn = 100010;
int school[maxn] = {0};   //记录每个学校的总分

int main() {
  int n, schID, score;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d%d", &schID, &score);  //学校ID、分数
    school[schID] += score;     //学校schID的总分增加score
  }
  int k = 1, MAX = -1;
  for(int i = 1; i <=n; i++) {
    if(school[i] > MAX) {
      MAX = school[i];
      k = i;
    }
  }
  printf("%d %d\n", k, MAX);
  return 0;
}
*/
