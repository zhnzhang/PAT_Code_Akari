#include <cstdio>         //答案给的逻辑比我的要简单，我属于先考虑同赢同输，饶了个弯子，其实
                          //这道题可以直接切入两种情况就行，甲对乙不对乙喝，甲不对乙对甲喝，即可。
int main() {
  int n, ta = 0, tb = 0, a1[150], a2[150], b1[150], b2[150];
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d%d%d%d", &a1[i], &a2[i], &b1[i], &b2[i]);
    if(a1[i] + b1[i] == a2[i] && a1[i] + b1[i] == b2[i]) {
      continue;
    }
    else if(a1[i] + b1[i] != a2[i] && a1[i] + b1[i] != b2[i]) {
      continue;
    }
    else {
      if(a1[i] + b1[i] == a2[i]) {
        tb++;
      }
      else if(a1[i] + b1[i] == b2[i]) {
        ta++;
      }
      else {
        continue;
      }
    }
  }
  printf("%d %d", ta, tb);
  return 0;
}

/*
#include <cstdio>                     //example
int main() {
  int n, failA = 0, failB = 0;        //甲乙输的次数
  scanf("%d", &n);      //记录条数
  for(int i = 0; i < n; i++) {
    int a1, a2, b1, b2;
    scanf("%d%d%d%d", &a1, &a2, &b1, &b2);      //甲喊、甲划、乙喊、乙划
    if(a1 + b1 == a2 && a1 + b1 != b2) {        //甲猜中乙没有猜中
      failB++;    //乙输
    }
    else if(a1 + b1 != a2 && a1 + b1 == b2) {   //甲没有猜中乙猜中
      failA++;    //甲输
    }
  }
  printf("%d %d", failA, failB);    //输出结果
}
*/
