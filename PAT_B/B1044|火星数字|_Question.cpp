//example
//因为直接针对给出的输入进行模拟会相对复杂，考虑到数据范围最多不超过168，因此不妨将[0, 168]的所有数都预处理出来(即打表)
//然后查询一个输出一个，这比直接通过输入来模拟要简单得多
//考虑对个位为[0, 12]、十位为0的数与十位为[0, 12]、个位为0的数进行特殊处理。对十位为[0, 12]、个位为0的数来说，它们是13的倍数，也就是"tret"~"jou"
//数字到火星文的映射用string数组即可，而火星文到数字的映射就得要map了
//考虑个位和十位均不为0的数，可以直接通过十位的火星文拼接上个位的火星文得到。那么在打表完成后，就可以直接对输入进行查询了
//注意：13的倍数不应当输出个位的"tret"，例如13应当输出"tam"而不是"tam tret"

#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;
//[0, 12]的火星文
string unitDigit[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun",
                        "jly", "aug", "sep", "oct", "nov", "dec"};
//13的[0, 12]倍的火星文
string tenDigit[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes",
                       "hei", "elo", "syy", "lok", "mer", "jou"};
string numToStr[170];       //数字->火星文
map<string, int> strToNum;  //火星文->数字

void init() {       //打表过程
    for(int i = 0; i < 13; i++) {
        numToStr[i] = unitDigit[i];     //个位为[0, 12],十位为0
        strToNum[unitDigit[i]] = i;
        numToStr[i * 13] = tenDigit[i]; //十位为[0, 12],个位为0
        strToNum[tenDigit[i]] = i * 13;
    }
    for(int i = 1; i < 13; i++) {       //十位
        for(int j = 1; j < 13; j++) {   //个位
            string str = tenDigit[i] + " " + unitDigit[j];      //火星文
            numToStr[i * 13 + j] = str;     //数字->火星文
            strToNum[str] = i * 13 + j;     //火星文->数字
        }
    }
}

int main() {
    init();     //打表
    int T;
    scanf("%d%*c", &T);     //查询个数(话说我也不知道为什么要写%*c，这个是紧接着接收但不赋值，丢弃的意思)
    while(T--) {
        string str;
        getline(cin, str);      //查询的数(以string形式读入？)
        if(str[0] >= '0' && str[0] <= '9') {        //如果是数字
            int num = 0;        //字符串转换成数字
            for(int i = 0; i < str.length(); i++) {
                num = num * 10 + (str[i] - '0');
            }
            cout << numToStr[num] << endl;      //直接查表
        } else {        //如果是火星文
            cout << strToNum[str] << endl;      //直接查表
        }
    }
    return 0;
}
