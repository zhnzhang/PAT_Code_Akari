#include <cstdio>

int abs(int x) {
    if (x >= 0) {
        return x;
    } else {
        return -x;
    }
}

int MakeCoin(int g, int s, int k) {         //全换成零钱形式
    return g * 17 * 29 + s * 29 + k;
}

int main() {
    int p, a, sub, subabs, g, s, k;         //sub是指作差，subabs是对作差求绝对值
    scanf("%d.%d.%d", &g, &s, &k);
    p = MakeCoin(g, s, k);
    scanf("%d.%d.%d", &g, &s, &k);
    a = MakeCoin(g, s, k);
    sub = a - p;
    subabs = abs(sub);
    k = subabs % 29;
    g = subabs / (29 * 17);
    s = (subabs - g * 29 * 17) / 29;
    if (sub >= 0) {                         //这里必须>=，最后一个检测点考察这里0的情况
        printf("%d.%d.%d\n", g, s, k);
    } else {
        printf("-%d.%d.%d\n", g, s, k);
    }
    return 0;
}



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
