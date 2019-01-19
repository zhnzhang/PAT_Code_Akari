//example
//同A1073
//本题主要是以E的位置为主要研究对象，分明白情况，讨论时计算好小数点移动后的位置
//由于一个char变量需要1Byte来存储，因此9999Byte就说明这个数字的长度不超过9999
//从完整性来考虑，指数为0的情况需要特判输出，不过本题似乎不需要考虑这种情况，数据中也没有指数为0的数据, 但代码中依然包括了特判的情况
#include <cstdio>
#include <cstring>
char str[10010];

int main() {
  scanf("%s", str);
  int len = strlen(str);
  if(str[0] == '-')
    printf("-");      //如果是负数，输出负号
  int pos = 0;      //pos存放字符串中E的位置
  while(str[pos] != 'E') {
    pos++;
  }
  int exp = 0;    //exp存放指数(先不考虑正负)
  for(int i = pos + 2; i < len; i++) {    //这个for循环中的技法需要掌握，即如何从高位向低位增加位数，如何进行字符型与数字型的转换
    exp = exp * 10 + (str[i] - '0');
  }
  if(exp == 0) {  //特判指数为0的情况(科学计数法)，指数是针对于基数10的
    for(int i = 1; i < pos; i++) {
      printf("%c", str[i]);
    }
  }
  if(str[pos + 1] == '-') {   //如果指数为负
    printf("0.");
    for(int i = 0; i < exp - 1; i++) {
      printf("0");
    }
    //输出除了小数点以外的数字
    printf("%c", str[1]);
    for(int i = 3; i < pos; i++) {
      printf("%c", str[i]);
    }
  }
  else {        //如果指数为正
    for(int i = 1; i < pos; i++) {    //输出小数点移动之后的数
      if(str[i] == '.')
        continue;                 //略过 原 小数点
      printf("%c", str[i]);       //输出当前数位
      if(i == exp + 2 && pos - 3 != exp) {    //小数点加在位置(exp + 2)上
      //原小数点和E之间的数字个数(pos - 3)不能等于小数点右移位数exp
        printf(".");
      }
    }
    //如果指数exp较大，输出多余的0
    for(int i = 0; i < exp - (pos - 3); i++) {
      printf("0");
    }
  }
  return 0;
}
