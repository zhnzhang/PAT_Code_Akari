#include <stdio.h>

bool BSTLRN(int A[], int n) {
    if(n == 1)
        return true;
    int i, lcount = 0, rcount = 0;
    bool lflag, rflag;
    bool flag = false;
    int root = A[n - 1];
    for(int i = 0; i < n; i++) {
        if(!flag) {
            if(A[i] < root) {
                lcount++;
            }
            else if(A[i] > root) {
                flag = true;
                lflag = BSTLRN(A, lcount);
                rcount++;
            }
        }
        else {
            if(A[i] < root)
                return false;
            else if(A[i] > root)
                rcount++;
            else {
                rflag = BSTLRN(A, rcount);
            }
        }
    }
    if(lflag && rflag)
        return true;
    else
        return false;
}

int main() {
    int A[100];
    int i = 0;
    int num;
    while(1) {
        scanf("%d", &num);
        char c = getchar();
        A[i++] = num;
        if(c == '\n') {
            break;
        }
    }
    bool flag = BSTLRN(A, i);
    if(flag)
        printf("True");
    else
        printf("False");
    return 0;
}
