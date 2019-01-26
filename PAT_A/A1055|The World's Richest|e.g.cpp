//example
//注意到M的范围仅在100以内，因此可以进行预处理，即将每个年龄中财富在前100名以内的人全都存到另外一个新数组中(因为某个年龄中财富值在100名以外的人永远不会被输出)
//后面查询的操作均在这个新数组中进行。这个预处理操作将显著降低查询的复杂度，使得K次查询不会超时
//如果不进行步骤2的预处理，那么2号测试点会超时。如果在查询时单独对某个年龄区间的人排序，也会超时
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100010;

int Age[maxn] = {0};        //某年龄的人数
struct Person {
  int age, worths;          //年龄、财富值
  char name[10];            //姓名
} ps[maxn], valid[maxn];    //所有人、在各自年龄中财富值在100名以内的人

bool cmp(Person a, Person b) {
  if(a.worths != b.worths)
    return a.worths > b.worths;           //按财富值从大到小排序
  else if(a.age != b.age)
    return a.age < b.age;                 //按年龄从小到大排序
  else
    return strcmp(a.name, b.name) < 0;    //按姓名字典序从小到大排序
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);            //总人数、查询次数
  for(int i = 0; i < n; i++) {
    scanf("%s %d %d", ps[i].name, &ps[i].age, &ps[i].worths);
  }
  sort(ps, ps + n, cmp);            //先对所有人进行题目要求的排序
  int validNum = 0;                 //存放到valid数组中的人数,面向valid的数组指针
  for(int i = 0; i < n; i++) {
    if(Age[ps[i].age] < 100) {      //年龄ps[i].age的人数小于100人时
      Age[ps[i].age]++;             //年龄ps[i].age的人数加1
      valid[validNum++] = ps[i];    //将ps[i]加入新数组中
    }
  }
  int m, ageL, ageR;
  for(int i = 1; i <= k; i++) {
    scanf("%d%d%d", &m, &ageL, &ageR);      //前M人、年龄区间[ageL, ageR]
    printf("Case #%d:\n", i);
    int printNum = 0;                       //已输出的人数
    for(int j = 0; j < validNum && printNum < m; j++) {     //从新数组中查找符合条件的前m人，注意一下循环条件
      if(valid[j].age >= ageL && valid[j].age <= ageR) {
        printf("%s %d %d\n", valid[j].name, valid[j].age, valid[j].worths);
        printNum++;
      }
    }
    //对无人的特判
    if(printNum == 0)
      printf("None\n");
  }
  return 0;
}
