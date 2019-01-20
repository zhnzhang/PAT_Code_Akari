//example
#include <cstdio>
#include <cstring>

struct node {
  char name[20], password[20];
  bool ischange;    //ischange == true表示password已修改
} T[1010];

//crypt函数判断t的password是否需要修改，若需要，则对其进行修改并令计数器cnt加1
void crypt(node &t, int &cnt) {     //参数使用了引用&，可以对传入参数进行修改
  int len = strlen(t.password);
  for(int i = 0; i < len; i++) {    //枚举password的每一位
    if(t.password[i] == '1') {      //若为'1', 则修改为'@'，并标记为已修改
      t.password[i] = '@';
      t.ischange = true;
    }
    else if(t.password[i] == '0') { //若为'0',则修改为'%'，并标记为已修改
      t.password[i] = '%';
      t.ischange = true;
    }
    else if(t.password[i] == 'l') { //若为'l',则修改为'L'，并标记为已修改
      t.password[i] = 'L';
      t.ischange = true;
    }
    else if(t.password[i] == 'O') { //若为'O',则修改为'o'，并标记为已修改
      t.password[i] = 'o';
      t.ischange = true;
    }                               //可以用else continue，也可以就省略
  }
  if(t.ischange == true) {          //如果t的password已修改，则令计数器cnt加1
    cnt++;
  }
}

int main() {
  int n, cnt = 0;                   //cnt记录需要修改的password个数
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%s %s", T[i].name, T[i].password);
    T[i].ischange = false;          //初始化所有密码未修改
  }
  for(int i = 0; i < n; i++) {
    crypt(T[i], cnt);               //对T[i]的password判断是否需要修改
  }
  if(cnt == 0) {    //没有password需要修改
    if(n == 1) {
      printf("There is %d account and no account is modified", n);
    }
    else {      //注意account的单复数以及is/are的使用
      printf("There are %d accounts and no account is modified", n);
    }
  }
  else {      //有password需要修改
    printf("%d\n", cnt);      //cnt记录需要修改的password个数
    for(int i = 0; i < n; i++) {
      if(T[i].ischange == true) {
        //如果T[i]的password需要修改，则输出name和password
        printf("%s %s\n", T[i].name, T[i].password);
      }
    }
  }
  return 0;
}
