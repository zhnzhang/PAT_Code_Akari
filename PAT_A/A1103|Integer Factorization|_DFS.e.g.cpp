//example
//具体流程见习题集P279
//做好逻辑上的预处理，多方案时判断是否更优的做法的时间复杂度最好是O(1),否则容易超时，因此必须在DFS的参数中记录当前底数之和facSum，避免在找到一组解时计算序列的底数之和
//不要再找到一组解时才判断temp序列与ans序列的字典序关系，而应该让index从大到小进行选择，这样fac[index]大的就会相对早地被选中

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
//n,k,p即将N表示成K个正整数(可以相同，递减排序)的P次方的和,maxFacSum记录最大底数之和
int n, k, p, maxFacSum = -1;
//fac记录0^p, 1^p...i^p，是的i^p为不超过n的最大数
//ans存放最优底数序列，temp存放递归中的临时底数序列
vector<int> fac, ans, temp;

//power函数计算x^p
int power(int x) {
    int ans = 1;
    for(int i = 0; i < p; i++) {
        ans *= x;
    }
    return ans;
}

//init函数预处理fac数组，注意把0也存进去
void init() {
    int i = 0, temp = 0;
    while(temp <= n) {      //当i^p没有超过n时，不断把i^p加入fac
        fac.push_back(temp);
        temp = power(++i);
    }
}

//DFS函数，当前访问fac[index],nowK为当前选中个数
//sum为当前选中的数之和，facSum为当前选中的底数之和
void DFS(int index, int nowK, int sum, int facSum) {
    if(sum == n && nowK == k) {     //找到一个满足的序列
        if(facSum > maxFacSum) {        //底数之和更优
            ans = temp;         //更新最优底数序列
            maxFacSum = facSum;     //更新最大底数之和
        }
        return;
    }
    if(sum > n || nowK > k) return; //这种情况下不会产生答案，直接返回
    if(index - 1 >= 0) {        //fac[0]不需要选择
        temp.push_back(index);      //把底数index加入临时序列temp
        DFS(index, nowK + 1, sum + fac[index], facSum + index); //"选"的分支（与不能重复选数的区别在于"选"的分支的第一个参数）
        temp.pop_back();       //"选"的分支结束后把刚加进去的数pop掉
        DFS(index - 1, nowK, sum, facSum);      //"不选"的分支
    }
}

int main() {
    scanf("%d%d%d", &n, &k, &p);
    init();     //初始化fac数组
    DFS(fac.size() - 1, 0, 0, 0);               //从fac的最后一位开始往前搜索
    if(maxFacSum == -1) printf("Impossible\n");     //没有找到满足的序列
    else {
        printf("%d = %d^%d", n, ans[0], p);     //输出ans的结果
        for(int i = 1; i < ans.size(); i++) {
            printf(" + %d^%d", ans[i], p);
        }
    }
    return 0;
}
