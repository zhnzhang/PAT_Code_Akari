//NKW 甲级真题1012
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn1 = 110;
const int maxn2 = 260;
char v[maxn1][maxn2];
int main(){
	int n, num = 0, minlen = 300;
	scanf("%d", &n);
	char kuchiguse[maxn2];
	char c;
	bool flag = true;
	getchar();				//接收数字后的换行符
	for (int i = 0; i < n; i++){
		fgets(v[i], maxn2, stdin);		//PTA网站如果使用C++(g++)编译不能使用get(),如果使用c(gcc)编译不能使用C++头文件
		if (v[i][strlen(v[i]) - 1] == '\n')	//此处需用fgets()替代gets()，并且把换行符去了，fgets()把换行符也接收了
		    v[i][strlen(v[i]) - 1] = '\0';	//还能使用getline(cin,v[i]),#include <iostream> #include <string>
		if (minlen > strlen(v[i]))
			minlen = strlen(v[i]);
		reverse(v[i], v[i] + strlen(v[i]));
	}
	for (int i = 0; i < minlen; i++){
		for (int j = 0; j < n; j++){
			c = v[0][i];
			if (c != v[j][i]){
				flag = false;
				break;
			}
		}
		if (flag)
			kuchiguse[num++] = c;
		else
			break;
	}
	kuchiguse[num] = '\0';
	reverse(kuchiguse, kuchiguse + strlen(kuchiguse));
	if (strlen(kuchiguse))
		printf("%s\n", kuchiguse);
	else
		printf("nai\n");
	system("pause");
	return 0;
}