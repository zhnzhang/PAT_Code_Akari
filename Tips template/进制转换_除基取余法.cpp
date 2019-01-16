//example
//将整数n转换为b进制
int ans[40], num = 0;
do {
    ans[num++] = n % b;
    n /= b;
  } while(n != 0);
