//example
//负数无需特殊处理，只需当作分子为负数的分数
//数据范围为int，因此两个分母相乘时，最大可达long long
//计算最大公约数时，要注意是计算分子分母绝对值的公约数
//除法时，如果除数为0，则应当特判输出"Inf"

#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {    //求a与b的最大公约数
    return b == 0 ? a : gcd(b, a % b);
}

struct Fraction {   //分数
    ll up, down;    //分子、分母
}a, b;

Fraction reduction(Fraction result) {   //化简
    if(result.down < 0) {           //分母为负数，令分子和分母都变为相反数
        result.up = -result.up;
        result.down = -result.down;
    }
    if(result.up == 0) {            //如果分子为0
        result.down = 1;            //令分母为1
    } else {        //如果分子不为0，进行约分
        int d = gcd(abs(result.up), abs(result.down));      //分子分母的最大公约数
        result.up /= d;             //约去最大公约数
        result.down /= d;
    }
    return result;
}

Fraction add(Fraction f1, Fraction f2) {        //分数f1加上分数f2
    Fraction result;
    result.up = f1.up * f2.down + f2.up * f1.down;      //分数和的分子
    result.down = f1.down * f2.down;            //分数和的分母
    return reduction(result);                   //返回结果分数，注意化简
}

Fraction minu(Fraction f1, Fraction f2) {       //分数f1减去分数f2
    Fraction result;
    result.up = f1.up * f2.down - f2.up * f1.down;  //分数差的分子
    result.down = f1.down * f2.down;                //分数差的分母
    return reduction(result);           //返回结果分数，注意化简
}

Fraction multi(Fraction f1, Fraction f2) {      //分数f1乘以分数f2
    Fraction result;
    result.up = f1.up * f2.up;          //分数积的分子
    result.down = f1.down * f2.down;    //分数积的分母
    return reduction(result);       //返回结果分数，注意化简
}

Fraction divide(Fraction f1, Fraction f2) {     //分数f1除以分数f2
    Fraction result;
    result.up = f1.up * f2.down;            //分数商的分子
    result.down = f1.down * f2.up;          //分数商的分母
    return reduction(result);           //返回结果分数，注意化简
}

void showResult(Fraction r) {           //输出分数r
    r = reduction(r);
    if(r.up < 0) printf("(");
    if(r.down == 1) printf("%lld", r.up);   //整数
    else if(abs(r.up) > r.down) {           //假分数
        printf("%lld %lld/%lld", r.up / r.down, abs(r.up) % r.down, r.down);
    } else {            //真分数
        printf("%lld/%lld", r.up, r.down);
    }
    if(r.up < 0) printf(")");
}

int main() {
    scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
    //加法
    showResult(a);
    printf(" + ");
    showResult(b);
    printf(" = ");
    showResult(add(a, b));
    printf("\n");
    //减法
    showResult(a);
    printf(" - ");
    showResult(b);
    printf(" = ");
    showResult(minu(a, b));
    printf("\n");
    //乘法
    showResult(a);
    printf(" * ");
    showResult(b);
    printf(" = ");
    showResult(multi(a, b));
    printf("\n");
    //除法
    showResult(a);
    printf(" / ");
    showResult(b);
    printf(" = ");
    if(b.up == 0) printf("Inf");
    else showResult(divide(a, b));
    return 0;
}
