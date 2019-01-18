//example
//常用技法，使用数组来存储权重和校验码的对应关系，也即用下标和数组值的对应关系来联系两个概念
//只检查前17位是否全为数字且最后1位校验码计算准确，这两种情况若有出错，都需要输出错误的身份证号
#include <cstdio>
#include <cstring>
//权重，w[0] = 7, w[1] = 9...
int w[20] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
//校验码，change[0] = '1', change[1] = '0',...这里用char表示校验码是因为身份证存储以字符数组为载体
char change[15] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

int main() {
  int n;
  scanf("%d", &n);
  bool flag = true;     //记录是否所有身份证都是正确的，若均正确，则flag = true
  char str[20];
  for(int i = 0; i < n; i++) {    //每个每读进来，进行处理
    scanf("%s", str);
    int j, last = 0;        //j定义在下个for循环之外，last记录前17位的加权和
    for(j = 0; j < 17; j++) {
      if(!(str[j] >= '0' && str[j] <= '9'))
        break;              //非数字
      last += (str[j] - '0') * w[j];    //每位加权求和
    }
    if(j < 17) {      //有非数字的存在
      flag = false;   //存在身份证号错误
      printf("%s\n", str);
    }
    else {
      if(change[last % 11] != str[17]) {  //校验码不等于身份证号最后一位
        flag = false;       //存在身份证号错误
        printf("%s\n", str);
      }
    }
  }
  if(flag == true) {      //所有身份证号均正确，输出All passed
    printf("All passed\n");
  }
  return 0;
}
