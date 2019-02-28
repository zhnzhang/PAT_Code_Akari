//example
//本题需要掌握map<string, set<int> >的写法
//值得一提的是关键词的提取。由于题目中的每本书都可能有多个关键词，因此需要将这些关键词分离开来。一个比较好的办法是使用cin来读入单个关键词，然后用getchar接收在这个关键词后面的字符：
//如果是换行符，则说明关键词的输入结束；如果是空格，则继续读入。这样做的原因是，cin读入字符串是以空格或换行为截止标志的。
//至于书名、作者、出版社及出版年份则是作为整体读入，因此使用getline来读入整行。
//如果单独把查询操作提炼成一个函数，那么一定要对参数使用引用，否则最后一组数据会超时。
//由此可见，字符串以及map的参数传递速度较慢，如果需要作为函数的参数的话需要尽可能加上引用
//在scanf或者cin输入书的编号id后，必须用getchar接收掉id后面的换行，否则getline将会换行读入(这里要注意，也就是scanf后面接getline的话，中间要加个getchar()收集换行，这是由scanf与getline的特性来决定的)

#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <string>
using namespace std;
//5个map变量分别建立书名、作者、关键词、出版社及出版年份与id的映射关系
map<string, set<int> > mpTitle, mpAuthor, mpKey, mpPub, mpYear;

void query(map<string, set<int> > &mp, string &str) {       //在mp中查找str
    if(mp.find(str) == mp.end()) printf("Not Found\n");     //找不到
    else {      //找到str
        for(set<int>::iterator it = mp[str].begin(); it != mp[str].end(); it++) {
            printf("%07d\n", *it);      //输出str对应的所有id
        }
    }
}

int main() {
    int n, m, id, type;
    string title, author, key, pub, year;
    scanf("%d", &n);        //书的数目
    for(int i = 0; i < n; i++) {
        scanf("%d", &id);               //id
        char c = getchar();             //接收掉id后面的换行
        getline(cin, title);            //读入书名title
        mpTitle[title].insert(id);      //把id加入title对应的集合中
        getline(cin, author);           //读入作者author
        mpAuthor[author].insert(id);    //把id加入author对应的集合中
        while(cin >> key) {             //每次读入单个关键词key
            mpKey[key].insert(id);      //把id加入key对应的集合中
            c = getchar();              //接收关键词key之后的字符
            if(c == '\n') break;        //如果是换行，说明关键词输入结束(注意这里的单引号，'\n')
        }
        getline(cin, pub);              //输入出版社pub
        mpPub[pub].insert(id);          //把id加入pub对应的集合中
        getline(cin, year);             //输入年份year
        mpYear[year].insert(id);        //把id加入year对应的集合中
    }
    string temp;
    scanf("%d", &m);                    //查询次数
    for(int i = 0; i < m; i++) {
        scanf("%d: ", &type);               //查询类型
        getline(cin, temp);                 //欲查询的字符串
        cout << type << ": " << temp << endl;       //输出类型和该字符串
        if(type == 1) query(mpTitle, temp);         //查询书名对应的所有id
        else if(type == 2) query(mpAuthor, temp);   //查询作者对应的所有id
        else if(type == 3) query(mpKey, temp);      //查询关键词对应的所有id
        else if(type == 4) query(mpPub, temp);      //查询出版社对应的所有id
        else query(mpYear, temp);       //查询出版年份对应的所有id
    }
    return 0;
}
