//example 边读边做
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct pNode {
  char id[20];
  int hh, mm, ss;   //ans1存放最早签到时间，ans2存放最晚签离时间
} temp, ans1, ans2;

bool great(pNode node1, pNode node2) {    //若node1时间大于node2时间，则返回true
  if(node1.hh != node2.hh)
    return node1.hh > node2.hh;
  else if(node1.mm != node2.mm)
    return node1.mm > node2.mm;
  else
    return node1.ss > node2.ss;
}

int main() {
  int n;
  scanf("%d", &n);      //技巧!：反向设初值.比如求最早签到时间，就把目标变量签到时间的初值设置为最大，以使循环逻辑正常运行，得出正确结果
  ans1.hh = 24, ans1.mm = 60, ans1.ss = 60;   //把初始签到时间设成最大
  ans2.hh = 0, ans2.mm = 0, ans2.ss = 0;     //把初始签离时间设成最小
  for(int i = 0; i < n; i++) {
    //先读入签到时间
    scanf("%s %d:%d:%d", temp.id, &temp.hh, &temp.mm, &temp.ss);
    if(!great(temp, ans1))
      ans1 = temp;
    //temp再作为签离时间读入
    scanf("%d:%d:%d", &temp.hh, &temp.mm, &temp.ss);
    if(great(temp, ans2))
      ans2 = temp;
  }
  printf("%s %s\n", ans1.id, ans2.id);
  return 0;
}
