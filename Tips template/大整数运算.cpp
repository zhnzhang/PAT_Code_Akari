//bign是big number的缩写
//大整数的存储
//一般在定义结构体变量之后，需要马上初始化结构体。为了减少在实际输入代码时总是忘记初始化的问题，最好使用构造函数
//构造函数是用来初始化结构体的函数，函数名和结构体名相同、无返回值，加上后大整数结构体bign就如下
struct bign {
    int d[1000];
    int len;
    bign() {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};
//这样在每次定义结构体变量时，都会自动对该变量进行初始化

//在输入大整数时，一般都是先用字符串读入，然后再把字符串另存为至bign结构体
//由于使用char数组进行读入时，整数的高位会变成数组的低位，整数的低位会变成数组的高位，因此为了让整数在bign中是顺位存储，需要让字符串倒着赋给d[]数组：
bign change(char str[]) {       //将整数转换为bign
    bign a;
    a.len = strlen(str);        //bign的长度就是字符串的长度
    for(int i = 0; i < a.len; i++) {
        a.d[i] = str[a.len - 1 - i] - '0';      //逆着赋值
    }
    return a;
}

//如果要比较两个bign变量的大小，要先判断两者的len大小，如果不相等，则以长的为大；如果相等，则从高位到低位进行比较，直到出现某一位不等，就可以判断两个数的大小
int compare(bign a, bign b) {   //比较a和b大小，a大、相等、a小分别返回1、0、-1
    if(a.len > b.len) return 1;     //a大
    else if(a.len < b.len) return -1;   //a小
    else {
        for(int i = a.len - 1; i >= 0; i--) {   //从高位往低位比较
            if(a.d[i] > b.d[i]) return 1;   //只要有一位a大，则a大
            else if(a.d[i] < b.d[i]) return -1; //只要有一位a小，则a小
        }
        return 0;   //两数相等
    }
}

//主要介绍四个运算：高精度加法，高精度减法，高精度与低精度的乘法，高精度与低精度的除法。至于高精度与高精度的乘法和除法，考试一般不会涉及

//高精度加法
//将该位上的两个数字与进位相加，得到的结果取个位数作为该位结果，取十位数作为新的进位
bign add(bign a, bign b) {  //高精度a + b
    bign c;
    int carry = 0;  //carry是进位
    for(int i = 0; i < a.len || i < b.len; i++) {       //以较长的为界限
        int temp = a.d[i] + b.d[i] + carry;         //两个对应位与进位相加
        c.d[c.len++] = temp % 10;       //个位数为该位结果
        carry = temp / 10;      //十位数为新的进位
    }
    if(carry != 0) {        //如果最后进位不为0，则直接赋给结果的最高位
        c.d[c.len++] = carry;
    }
    return c;
}

//完整A + B的代码如下：
#include <cstdio>
#include <cstring>
struct bign {
    int d[1000];
    int len;
    bign() {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

bign change(char str[]) {       //将整数转换为bign
    bign a;
    a.len = strlen(str);        //bign的长度就是字符串的长度
    for(int i = 0; i < a.len; i++) {
        a.d[i] = str[a.len - 1 - i] - '0';      //逆着赋值
    }
    return a;
}

bign add(bign a, bign b) {  //高精度a + b
    bign c;
    int carry = 0;  //carry是进位
    for(int i = 0; i < a.len || i < b.len; i++) {       //以较长的为界限
        int temp = a.d[i] + b.d[i] + carry;         //两个对应位与进位相加
        c.d[c.len++] = temp % 10;       //个位数为该位结果
        carry = temp / 10;      //十位数为新的进位
    }
    if(carry != 0) {        //如果最后进位不为0，则直接赋给结果的最高位
        c.d[c.len++] = carry;
    }
    return c;
}

void print(bign a) {    //输出bign
    for(int i = a.len - 1; i >= 0; i--) {
        printf("%d", a.d[i]);
    }
}

int main() {
    char str1[1000], str2[1000];
    scanf("%s%s", str1, str2);
    bign a = change(str1);
    bign b = change(str2);
    print(add(a, b));
    return 0;
}
//补充：如上这样的写法的条件是两个对象都是非负整数。
//如果有一方是负的，可以在转换到数组这一步时去掉其负号，然后采用高精度减法
//如果两个都是负的，就都去掉负号后用高精度加法，最后再把负号加回去

//高精度减法
bign sub(bign a, bign b) {      //高精度a - b
    bign c;
    for(int i = 0; i < a.len || i < b.len; i++) {   //以较长的为界限
        if(a.d[i] < b.d[i]) {       //如果不够减
            a.d[i + 1]--;       //向高位借位
            a.d[i] += 10;       //当前位加10
        }
        c.d[c.len++] = a.d[i] - b.d[i];     //减法结果为当前为结果
    }
    while(c.len - 1 >= 1 && c.d[c.len - 1] == 0) {
        c.len--;        //去除高位的0，同时至少保留一位最低位
    }
    return c;
}

//高精度减法的完整代码即为把上面的sub函数替代高精度加法中add函数的位置即可，当然调用也得改
//最后指出，使用sub函数前要比较两个数的大小，如果被减数小于减数，需要交换两个变量，然后输出负号，再使用sub函数

//高精度与低精度的乘法
//所谓低精度就是可以用基本数据类型存储的数据，例如int型
//对某步来说就是这样的步骤：取bign的某位与int型整体相乘，再与进位相加，所得结果的个位数作为该位结果，高位部分作为新的进位
bign multi(bign a, int b) {     //高精度乘法
    bign c;
    int carry = 0;      //进位
    for(int i = 0; i < a.len; i++) {
        int temp = a.d[i] * b + carry;
        c.d[c.len++] = temp % 10;       //个位作为该位结果
        carry = temp / 10;      //高位部分作为新的进位
    }
    while(carry != 0) {     //和加法不一样，乘法的进位可能不止一位，因此用while，将多位数的每个位都存入数组，这也符合大整数的结构定义。别直接存，一定要分位存！
        c.d[c.len++] = carry % 10;
        carry /= 10;
    }
    return c;
}
//完整的A x B的代码只需要把高精度加法里的add函数改成这里的multi函数，并注意输入的时候b是作为int型输入即可
//如果a和b中存在负数，那就需要先记录下其负号，然后取它们的绝对值代入函数

//高精度与低精度的除法
//归纳其中某一步的步骤：上一步的余数乘以10加上该步的位，得到该步临时的被除数，将其与除数比较：
//如果不够除，则该位的商为0；如果够除，则商即为对应的商，余数即为对应的余数。
//最后一步注意减法后高位可能有多余的0，要去除它们，但也要保证结果至少有一位数
bign divide(bign a, int b, int &r) {
    bign c;     //c是商
    c.len = a.len;      //被除数的每一位和商的每一位是一一对应的，因此先令长度相等
    for(int i = a.len - 1; i >= 0; i--) {   //从高位开始
        r = r * 10 + a.d[i];        //和上一位遗留的余数组合
        if(r < b) c.d[i] = 0;       //不够除，该位为0
        else {  //够除
            c.d[i] = r / b;     //商
            r %= b; //获得新的余数
        }
    }
    while(c.len - 1 >= 1 && c.d[c.len - 1] == 0) {
        c.len--;        //去除高位的0，同时至少保留一位最低位
    }
    return c;
}

//在上述代码中，考虑到函数每次只能返回一个数据，而很多题目里面会经常要求得到余数，因此把余数写成"引用"的形式直接作为参数传入，或是把r设成全局变量。
//这样当函数结束时，r的值就是最终的余数。
