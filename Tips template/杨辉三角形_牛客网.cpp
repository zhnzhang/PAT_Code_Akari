#include <cstdio>
#include <cstring>

int a[100][100] = {0};

int func(int i, int j) {                //递归求解某个位置的值
    if (i == 2 || j == 1 || j == i) {
        return 1;
    }
    return func(i - 1, j - 1) + func(i - 1, j);
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                a[i][j] = func(i, j);
            }
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                printf("%d", a[i][j]);
                if (j != i) {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
