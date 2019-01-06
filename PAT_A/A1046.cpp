//example 我没写出来，参考答案如下
#include <cstdio>
const int N = 54;
char mp[5] = {'S', 'H', 'C', 'D', 'J'};   //牌的编号与花色的对应关系。MP:matching pursuit 匹配追踪
int start[N + 1], end[N + 1], next[N + 1];    //next数组存放每个位置上的牌在操作后的位置

int main() {
  int K;
  scanf("%d", &K);
  for(int i = 1; i <= N; i++) {
    start[i] = i;   //初始化牌的编号
  }
  for(int i = 1; i <= N; i++) {
    scanf("%d", &next[i]);    //输入每个位置上的牌在操作后的位置
  }
  for(int step = 0; step < K; step++) {   //执行K次操作
    for(int i = 1; i <= N; i++) {
      end[next[i]] = start[i];          //把第i个位置的牌的编号存于end数组中位置next[i]
    }
    for(int i = 1; i <= N; i++) {
      start[i] = end[i];                //把end数组赋值给start数组以供下次操作使用
    }
  }
  for(int i = 1; i <= N; i++) {
    if(i != 1)              //之所以这么控制格式是因为它是先输出空格再输出元素的写法。由于开头不能是空格，故i != 1，先输出空格再输出元素在最后一趟循环的运行逻辑能保证行尾无多余空格。
      printf(" ");          //控制输出格式
    start[i]--;
    printf("%c%d", mp[start[i] / 13], start[i] % 13 + 1);   //输出结果
    //上两句也可以用一句代替:printf("%c%d", mp[(start[i) - 1) / 13]], (start[i] - 1) % 13 +1);
  }                       //mp[(x - 1) / 13] 对应花色，(x - 1) % 13 + 1即所属花色下的编号
  return 0;
}
