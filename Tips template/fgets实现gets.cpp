//就我个人的实际提交体验来看
// CSDN有人提出:要想把fgets()接收的字符串变得和gets()一样还需要str[len - 2] = '\0';因为fgets()会把空格也接收到
//但经过我的实际提交，这样的做法会导致答案错误
//故我还是保持原来的做法
//只取其中的语句即可
语句void fgetstogets(char * str) {
 int len = strlen(str);
	if(str[len - 1] == '\n' && str[len] == '\0') {
		str[len - 1] = '\0';
	}
 return;
}

//if的判断条件中,str[len - 1] == '\n'是最重要的
//语句向表达的核心意思也就是把最后接受到的换行符替换为'\0'
//&& str[len] == '\0'不加也能过AC
