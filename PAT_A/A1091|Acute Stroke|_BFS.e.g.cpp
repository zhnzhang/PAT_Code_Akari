//example
//三维01矩阵不可设置为bool型，否则最后两组数据会答案错误
//本题使用DFS非常容易在最后两组数据中出现段错误，原因是当三维矩阵中所有元素均为1时，DFS的深度过深，会使系统栈达到上限，从而爆栈
//输入数据时是按多个二维矩阵的方式读入的，因此3层for循环中的第一层需要遍历矩阵编号，第二、三层才是单个矩阵的数据读入

#include <cstdio>
#include <queue>
using namespace std;
struct node {
    int x, y, z;    //位置(x, y, z)
} Node;

int n, m, slice, T;     //矩阵为n * m，共有slice层，T为卒中核心区中1的个数的下限
int pixel[1290][130][61];       //三维01矩阵
bool inq[1290][130][61] = {false};      //记录位置(x, y, z)是否已入过队
int X[6] = {0, 0, 0, 0, 1, -1};     //增量矩阵
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {1, -1, 0, 0, 0, 0};

bool judge(int x, int y, int z) {       //判断坐标(x, y, z)是否需要访问
    //越界返回false
    if(x >= n || x < 0 || y >= m || y < 0 || z >= slice || z < 0) return false;
    //若当前位置为0或(x, y, z)已入过队，则返回false
    if(pixel[x][y][z] == 0 || inq[x][y][z] == true) return false;
    //以上都不满足，返回true
    return true;
}

//BFS函数访问位置(x, y, z)所在的块，将该块中所有"1"的inq都设置为true
int BFS(int x, int y, int z) {
    int tot = 0;        //计数当前块中1的个数
    queue<node> Q;      //定义队列
    Node.x = x, Node.y = y, Node.z = z; //结点Node的位置为(x, y, z)
    Q.push(Node);       //将结点Node入队
    inq[x][y][z] = true;        //设置位置(x, y, z)已入过队
    while (!Q.empty()) {
        node top = Q.front();   //去除队首元素
        Q.pop();        //队首元素出队
        tot++;      //当前块中1的个数加1
        for(int i = 0; i < 6; i++) {    //循环6次，得到6个增量方向的位置
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            int newZ = top.z + Z[i];
            if(judge(newX, newY, newZ)) {   //新位置(newX, newY, newZ)需要访问
                //设置Node的坐标
                Node.x = newX, Node.y = newY, Node.z = newZ;
                Q.push(Node);       //将结点Node入队
                inq[newX][newY][newZ] = true;   //设置(newX, newY, newZ)已入过队
            }
        }
    }
    if(tot >= T) return tot;    //如果大于等于阈值，则返回
    else return 0;      //否则不记录该块1的个数
}

int main() {
    scanf("%d%d%d%d", &n, &m, &slice, &T);
    for(int z = 0; z < slice; z++) {        //注意先枚举切片层号
        for(int x = 0; x < n; x++) {
            for(int y = 0; y < m; y++) {
                scanf("%d", &pixel[x][y][z]);
            }
        }
    }
    int ans = 0;        //记录卒中核心区中1的个数总和
    for(int z = 0; z < slice; z++) {
        for(int x = 0; x < n; x++) {
            for(int y = 0; y < m; y++) {
                //如果当前位置为1，且未被访问，则BFS当前块
                if(pixel[x][y][z] == 1 && inq[x][y][z] == false) {
                    ans += BFS(x, y, z);
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
