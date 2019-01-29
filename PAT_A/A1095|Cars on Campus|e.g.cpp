//example
//时间以s为单位可以简化很多操作
//本题数据量大，尽量不要用cin跟cout，以免运行超时
//查询的时刻是按照从小到大排序的，要利用好这一点，否则会运行超时
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
const int maxn = 10010;

struct Car {
  char id[10];      //车牌号
  int time;         //记录的时刻(以s为单位)
  char status[5];   //in或者out
} all[maxn], valid[maxn];       //all为所有记录，valid为有效记录

int num = 0;      //有效记录的条数(单位为条)
map<string, int> parkTime;      //车牌号->总停留时间

//timeToInt将时间转换为以s为单位
int timeToInt(int hh, int mm, int ss) {
  return hh * 3600 + mm * 60 + ss;
}

//先按车牌号字典序从小到大排序，若车牌号相同，则按时间从小到大排序
bool cmpByIdAndTime(Car a, Car b) {
  if(strcmp(a.id, b.id)) {
    return strcmp(a.id, b.id) < 0;
  }
  else {
    return a.time < b.time;
  }
}

//按时间从小到大排序
bool cmpByTime(Car a, Car b) {
  return a.time < b.time;
}

int main() {
  int n, k, hh, mm, ss;
  scanf("%d%d", &n, &k);      //记录数，查询数
  for(int i = 0; i < n; i++) {
    scanf("%s %d:%d:%d %s", all[i].id, &hh, &mm, &ss, all[i].status);
    all[i].time = timeToInt(hh, mm, ss);
  }
  sort(all, all + n, cmpByIdAndTime);     //按车牌号和时间排序
  int maxTime = -1;         //最长总停留时间(要知道什么时候需要把初值设为-1)
  for(int i = 0; i < n - 1; i++) {      //遍历所有记录
    if(!strcmp(all[i].id, all[i + 1].id) &&     //i和i + 1是同一辆车
      !strcmp(all[i].status, "in") &&           //i是in记录
      !strcmp(all[i + 1].status, "out")) {      //i + 1是out记录
        valid[num++] = all[i];      //i和i + 1是配对的，存入valid数组
        valid[num++] = all[i + 1];
        int inTime = all[i + 1].time - all[i].time;     //此次停留时间
        if(parkTime.count(all[i].id) == 0) {
          parkTime[all[i].id] = 0;        //map中还没有这个车牌号，置零(初始化)
        }
        parkTime[all[i].id] += inTime;      //增加该车牌号的总停留时间
        maxTime = max(maxTime, parkTime[all[i].id]);    //每次都要更新一下最大总停留时间
      }
  }
  sort(valid, valid + num, cmpByTime);      //把有效记录按时间从小到大排序
  //now指向 不超过 当前查询时间 的记录，numCar为当前校园内车辆数, 强调:now指向的是 记录
  int now = 0, numCar = 0;
  for(int i = 0; i < k; i++) {
    scanf("%d:%d:%d", &hh, &mm, &ss);
    int time = timeToInt(hh, mm, ss);
    //让now处理至当前查询时间，强调:now指向的是 记录
    while(now < num && valid[now].time <= time) {
      if(!strcmp(valid[now].status, "in")) {
        numCar++;     //车辆进入
      }
      else {
        numCar--;     //车辆离开
      }
      now++;          //指向下一条记录
    }
    printf("%d\n", numCar);     //输出所查询时间校园内车辆数
  }
  //对映射进行遍历操作，使用迭代器来写
  //定义相应的迭代器
  map<string, int>::iterator it;      //遍历所有车牌号
  for(it = parkTime.begin(); it != parkTime.end(); it++) {
    if(it->second == maxTime) {     //输出所有最长总停留时间的车牌号
      printf("%s ", it->first.c_str());       //c.str()返回当前字符串首字符地址(联想一下平常也是要写字符数组的数组名，而数组名也可以表示字符数组首字符地址)
    }
  }
  //输出最长总停留时间
  printf("%02d:%02d:%02d\n", maxTime / 3600, maxTime % 3600 / 60, maxTime % 60);
  return 0;
}
