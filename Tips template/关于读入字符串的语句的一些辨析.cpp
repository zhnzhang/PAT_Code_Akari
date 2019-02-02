//在读入字符串时，可以用gets函数直接读入整一行，也可以使用getchar()函数一次读入一个字符，直接读到'\n'为止。例如：
char s[MAX_N], a;
int lenA = 0;
while(true) {
	s[lenA++] = getchar();
	if(s[lenA - 1] == '\n') {
		break;		//必须有'\n'作为字符串的结束标识符
	}
}

//除此之外！！不建议使用scanf读取需要一次读取一整行字符串的情况。
//因为scanf读取字符串是用 空格 作为 截断标志 的，像"       "这种只有空格的字符串或者"abcd  abc"这类的字符串会因此而读不完整！
