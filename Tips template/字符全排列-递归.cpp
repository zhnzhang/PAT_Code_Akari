#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

map<char, int> mp;
int len;
char p[100];

void func(int index) {
    if (index == len + 1) {
        for (int i = 1; i <= len; i++) {
            printf("%c", p[i]);
        }
        printf("\n");
        return;
    }
    for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        if (it -> second == 0) {
            it -> second = 1;
            p[index] = it -> first;
            func(index + 1);
            it -> second = 0;
        }
    }
}

int main() {
    char str[100];
    scanf("%s", str);
    len = strlen(str);
    for (int i = 0; i < len; i++) {
        mp[str[i]] = 0;
    }
    func(1);
    return 0;
}
