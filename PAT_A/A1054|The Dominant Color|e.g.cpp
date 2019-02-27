//example
//即给出N行M列的数字矩阵，求其中超过半数的出现次数最多的数字
//如果使用普通的数组来进行计数，那么由于数据范围过大，可能导致内存超限
//机试思路：建立map<int, int>，作为数字与其出现次数的映射关系：map<int, int> count;
//这样count[24] = 8就表示数字24出现了8次。那么每读入一个x，就是用map的find函数寻找是否已经存在x，如果存在，则将其出现次数加1；否则，将其出现次数置为1。
//最后遍历map，寻找出现次数最多的数字并将其输出。由于题目保证一定有解，因此不需要判断是否超过半数
//笔试思路：由于题目要求必须超过半数，因此有超过半数的数相同的，如果采用两两不相同的数相互抵消的做法，最后一定会剩下那个超过半数的数字。
//于是可以设置一个变量ans存放答案，设置另一个变量count计数ans出现的次数，然后在读入时判断ans与读入的数字是否相等：
//如果不相等，则令其抵消一次ans(即令count--)，如果相等，则令count加1。当然，如果某步count被抵消至0，则令新的数字为ans。这样最后剩下的数字一定是所求数字

#include <cstdio>
#include <map>
using namespace std;

int main() {
    int n, m, col;
    scanf("%d%d", &n, &m);      //行与列
    map<int, int> count;        //数字与出现次数的map映射
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &col);      //输入数字
            if(count.find(col) != count.end()) count[col]++;    //若已存在，则次数加1
            else count[col] = 1;    //若不存在，则次数置为1
        }
    }
    int k = 0, MAX = 0;     //最大数字及该数字出现次数
    for(map<int, int>::iterator it = count.begin(); it != count.end(); it++) {
        if(it->second > MAX) {
            k = it->first;      //获取第一关键字，即数字
            MAX = it->second;   //获取第二关键字，即出现次数
        }
    }
    printf("%d\n", k);
    return 0;
}
