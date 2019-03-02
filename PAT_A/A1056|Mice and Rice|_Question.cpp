//example
//题目中给出的老鼠们的初识顺序其实是编号的顺序，按题目给的数据举例：即6号老鼠排第一个，0号老鼠排第二个，......，3号老鼠排最后一个。
//输出老鼠的排名，是按照原输入质量的顺序输出排名
//每轮比赛把老鼠分成的组数group：设当前轮的参赛老鼠数有temp只，如果temp % NG为0，那么说明能够把老鼠完整划分，因此group = temp / NG;否则，说明最后会有少于NG只老鼠会单独分为一组，此时组数group = temp / NG + 1
//由于每组晋级1只老鼠，因此当前轮晋级的总老鼠数等于group，且该轮未晋级的老鼠的排名均为group + 1
//当前轮老鼠的排名可在选出最大老鼠的过程中直接对每只老鼠都进行赋值(晋级的老鼠在下一轮比赛时会得到新的排名，覆盖掉旧的，所以没关系)
//有些写法会使只有1个老鼠时其排名出错，一般可以在循环后单独将排名第一的老鼠的排名进行赋值
//在运行时输入数据弹出错误提示的原因一般是没有处理最后一组老鼠不足NG只的情况，即没有注意控制每轮老鼠的总数，导致某步在队列内没有老鼠却使用了q.front()取队首老鼠

#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 1010;
struct mouse {  //老鼠
    int weight; //质量
    int R;      //排名
}mouse[maxn];

int main() {
    int np, ng, order;
    scanf("%d%d", &np, &ng);
    for(int i = 0; i < np; i++) {
        scanf("%d", &mouse[i].weight);
    }
    queue<int> q;       //定义一个队列
    for(int i = 0; i < np; i++) {
        scanf("%d", &order);        //题目给出的顺序
        q.push(order);      //按顺序把老鼠们的标号入队，（队列中放的是老鼠的编号）
    }
    int temp = np, group;       //temp为当前轮的比赛总老鼠数，group为组数
    while(q.size() != 1) {
        //计算group，即当前轮分为几组进行比赛
        if(temp % ng == 0) group = temp / ng;
        else group = temp / ng + 1;
        //枚举每一组，选出该组老鼠中质量最大的
        for(int i = 0; i < group; i++) {
            int k = q.front();          //k存放该组质量最大的老鼠的编号
            for(int j = 0; j < ng; j++) {
                //在最后一组老鼠数不足NG时起作用，退出循环
                if(i * ng + j >= temp) break;
                int front = q.front();      //队首老鼠编号
                if(mouse[front].weight > mouse[k].weight) {
                    k = front;      //找出质量最大的老鼠
                }
                mouse[front].R = group + 1;     //该轮老鼠排名为group + 1
                q.pop();    //出队这只老鼠
            }
            q.push(k);      //把胜利的老鼠晋级
        }
        temp = group;       //group只老鼠晋级，因此下轮总老鼠数为group
    }
    mouse[q.front()].R = 1;     //当队列中只剩1只老鼠时，令其排名为1
    //输出所有老鼠的信息
    for(int i = 0; i < np; i++) {
        printf("%d", mouse[i].R);
        if(i < np - 1) {
            printf(" ");
        }
    }
    return 0;
}
