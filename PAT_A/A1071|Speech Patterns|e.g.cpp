//example
//算法分为两个步骤：从给定字符串中分割出"单词"、计数出现次数最多的单词。
//由于题目规定单词由大小写字母、数字组成，因此can1与can是两个不同的单词，不能将can1的出现次数加到can的出现次数上面
//在得到一个单词word之后，必须先查看map中是否已经存在该单词。如果单词word不存在，则不能直接对其出现次数加1，而应直接将其出现次数赋值为1
//由于字符串中可能出现连续的非有效字符，因此在得到一个单词之后必须使用while将它们全部跳过
//字符串的开头可能会存在非有效字符，此时会得到空的单词，因此务必判断得到的单词是否为空：只有当单词非空时，才能计数其出现次数。例如下面的例子就会出现问题：
//"a"   //应当输出a 1
#include <iostream>
#include <string>
#include <map>
using namespace std;

bool check(char c) {                //检查字符c是否是[0, 9]、[A, Z]、[a, z]
    if(c >= '0' && c <= '9') return true;
    if(c >= 'A' && c <= 'Z') return true;
    if(c >= 'a' && c <= 'z') return true;
    return false;
}

int main() {
    map<string, int> count;     //count计数字符串出现的次数
    string str;
    getline(cin, str);      //读入整行字符串
    int i = 0;          //定义下标
    while(i < str.length()) {           //在字符串范围内
        string word;            //单词
        while (i < str.length() && check(str[i]) == true) {     //如果是单词的字符
            if(str[i] >= 'A' && str[i] <= 'Z') {
                str[i] += 32;       //将大写字母转化为小写字母
            }
            word += str[i];     //单词末尾添上该字符
            i++;            //下标后移1位
        }
        if(word != "") {        //单词非空，令次数加1
            if(count.find(word) == count.end()) count[word] = 1;
            else count[word]++;
        }
        while (i < str.length() && check(str[i]) == false) {
            i++;        //跳过非单词字符
        }
    }
    string ans;                 //存放出现次数最多的单词
    int MAX = 0;                    //出现最多的单词的次数
    for(map<string, int>::iterator it = count.begin(); it != count.end(); it++) {
        if(it->second > MAX) {              //寻找出现次数最多的单词
            MAX = it->second;
            ans = it->first;
        }
    }
    cout << ans << " " << MAX << endl;      //输出结果
    return 0;
}
