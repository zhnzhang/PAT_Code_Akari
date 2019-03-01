//example
//如果返回了"答案错误"或者"段错误"，那么需要重点检查一下是否忘记在pop操作和top操作前判空
//最后在判断该出栈序列是否合法时，要判断是否栈空，否则会返回"答案错误"。这是因为，如果在所有元素入栈之后无法将所有元素出栈，那么这肯定是不合法的
//在每个出栈序列输入前一定要清空栈，否则，如果上个出栈序列的结果没有被清空，那么会影响下个出栈序列的过程

#include <cstdio>
#include <stack>
using namespace std;
const int maxn = 1010;
int arr[maxn];
stack<int> st;

int main() {
    int m, n, T;
    scanf("%d%d%d", &m, &n, &T);
    while(T--) {
        while(!st.empty()) {
            st.pop();
        }
        for(int i = 1; i <= n; i++) {
            scanf("%d", &arr[i]);
        }
        int current = 1;
        bool flag = true;
        for(int i = 1; i <= n; i++) {
            st.push(i);
            if(st.size() > m) {
                flag = false;
                break;
            }
            while(!st.empty() && st.top() == arr[current]) {
                st.pop();
                current++;
            }
        }
        if(st.empty() == true && flag == true) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
