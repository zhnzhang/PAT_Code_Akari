//PAT甲级1007的测试点5是一群负数中间夹着一个0，如：-1 -5 0 -7 -3
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[10010];
int dp[10010] = {0};    //dp[i]表示以索引i为末尾的subarray的最大值
bool join[10010] = {false}; //join[i] = true表示dp[i - 1] > 0，即dp[i]是在第i个数加入之前的最大子数组的情况下取得的
                            //这个数组设立的意义就是为了求最大子数组的分布范围

int main() {
    int k, sum, t = 0, s = 0;      //t是dp数组最大值的索引（也即最大子序列的末尾索引），s是最大子序列的首个数字的索引
    bool flag = true;               //flag = true表示数组中数字全为负数
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", arr + i);
        if (arr[i] >= 0) {          //这里取等于是为了过上面的测试点5
            flag = false;
        }
    }
    if (flag) {
        printf("0 %d %d\n", arr[0], arr[k - 1]);
        return 0;
    }
    dp[0] = arr[0];
    for (int i = 1; i < k; i++) {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        if (dp[i - 1] > 0) {
            join[i] = true;
        }
    }
    sum = dp[0];
    for (int i = 0; i < k; i++) {
        if (dp[i] > sum) {
            sum = dp[i];
            t = i;
        }
    }
    for (int i = t; i >= 0; i--) {
        if (!join[i]) {
            s = i;
            break;
        }
    }
    printf("%d %d %d\n", sum, arr[s], arr[t]);
    return 0;
}
