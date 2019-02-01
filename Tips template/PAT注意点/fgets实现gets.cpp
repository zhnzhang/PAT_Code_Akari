//From CSDN 未进行验证
// 要想把fgets()接收的字符串变得和gets()一样还需要str[len - 2] = '\0';因为fgets()会把空格也接收到
void tostr(char * str) {
 int len = strlen(str);
 if (str[len - 1] == '\n'&&str[len] == '\0') {
  str[len - 1] = '\0';
  str[len - 2] = '\0';
 }
 return;
}
