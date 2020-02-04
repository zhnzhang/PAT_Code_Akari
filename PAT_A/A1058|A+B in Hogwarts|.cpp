//我这种写法，在中间计算过程中可能会出现int的数据范围不够的情况，因为题中g的范围上界再加上它会乘上493
//所以需要使用long long类型
//事实证明是这样的，测试点2就是大数据，用int会溢出，导致答案错误
//当然算法笔记那种按进位来运作的写法用不到

#include <cstdio>
#define ll long long

ll MakeChange(ll g, ll s, ll k) {
    return g * 29 * 17 + s * 29 + k;
}

int main() {
    ll a, b, g, s, k, sum;
    scanf("%lld.%lld.%lld", &g, &s, &k);
    a = MakeChange(g, s, k);
    scanf("%lld.%lld.%lld", &g, &s, &k);
    b = MakeChange(g, s, k);
    sum = a + b;
    g = sum / (29 * 17);
    s = sum % (29 * 17) / 29;
    k = sum % 29;
    printf("%lld.%lld.%lld\n", g, s, k);
    return 0;
}



//example
//说明有些冗长，具体说明见算法笔记
//但这里需要用到一个变量去存储低位进位的数据，当然这里0号位没有进位限制，不需要取模或整除运算
#include <cstdio>
int main() {
  int a[3], b[3], ans[3];         //这里的几号位是看数组下标说的
  scanf("%d.%d.%d %d.%d.%d", &a[0], &a[1], &a[2], &b[0], &b[1], &b[2]);
  int carry = 0;  //进位初始化
  ans[2] = (a[2] + b[2]) % 29;      //获得2号位的结果,最低位由于没有前一位故不用加进位
  carry = (a[2] + b[2]) / 29;     //获得2号位的进位,最低位由于没有前一位故不用加进位
  ans[1] = (a[1] + b[1] + carry) % 17;    //获得1号位的结果（加上进位）
  carry = (a[1] + b[1] + carry) / 17;   //获得1号位的进位
  ans[0] = (a[0] + b[0] + carry);   //获得0号位的结果，这里0号位没有进位限制，不需要取模或整除运算
  printf("%d.%d.%d", ans[0], ans[1], ans[2]);
  return 0;
}
