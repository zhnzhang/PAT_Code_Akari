//example
//使用string，则最后一组数据容易超时。像这种数据范围很大的情况，一般最好用char数组来存放数据，用string很容易超时
//如果排序时直接对字符串排序，那么会导致大量的字符串移动，非常消耗时间。因此比较合适的做法是使用字符串的下标来代替字符串本身进行排序，这样消耗的时间会少得多

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 40010;         //最大学生人数
const int maxc = 2510;          //最大课程门数

char name[maxn][5];             //maxn个学生
vector<int> course[maxc];       //course[i]存放第i门课的所有学生编号

bool cmp(int a, int b) {
    return strcmp(name[a], name[b]) < 0;    //按姓名字典序从小到大排序。规则是按照字符串字典序，但是是用字符串的下标来代替字符串本身进行排序的，从数组所存储的数据及传入的参数就能看出来
}

int main() {
    int n, k, c, courseID;
    scanf("%d%d", &n, &k);                  //学生人数及课程数
    for(int i = 0; i < n; i++) {
        scanf("%s %d", name[i], &c);            //学生姓名和选课数
        for(int j = 0; j < c; j++) {
            scanf("%d", &courseID);             //选择的课程编号
            course[courseID].push_back(i);      //将学生i加入第courseID门课中
        }
    }
    for(int i = 1; i <= k; i++) {
        printf("%d %d\n", i, course[i].size());       //第i门课的学生数
        sort(course[i].begin(), course[i].end(), cmp);      //对第i门课的学生排序，使用字符串的下标来代替字符串本身进行排序
        for(int j = 0; j < course[i].size(); j++) {
            printf("%s\n", name[course[i][j]]);     //输出学生姓名
        }
    }
    return 0;
}
