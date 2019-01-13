//example
//获得Knut为单位的找零的钱change后，要将它取绝对值，才能进行后面的计算。不能直接把负数代入后续格式转换的计算
#include <cstdio>
const int Galleon = 17 * 29;    //1个Galleon兑换17 * 29个Knut
const int Sickle = 29;          //1个Sickle兑换29个Knut

int main() {
  int a1, b1, c1;
  int a2, b2, c2;
  scanf("%d.%d.%d %d.%d.%d", &a1, &b1, &c1, &a2, &b2, &c2);
  int price = a1 * Galleon + b1 * Sickle + c1;  //价格，兑换成Knut单位
  int money = a2 * Galleon + b2 * Sickle + c2;  //付款，兑换成Knut单位
  int change = money - price;   //找零的钱,以Knut为单位
  if(change < 0) {      //如果是负数
    printf("-");        //输出符号
    change = -change;   //取绝对值
  }
  //转换成原先的格式
  printf("%d.%d.%d\n", change / Galleon, change % Galleon / Sickle, change % Sickle);
  return 0;
}
