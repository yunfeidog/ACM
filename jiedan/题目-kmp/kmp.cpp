#include <bits/stdc++.h>

using namespace std;

const int N = 100010, M = 1000010;

int n, m;
int ne[N];
char s[M], p[N];
char substr[N];
bool flag=false;

bool kmp() {
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j++;
        ne[i] = j;
    }

    for (int i = 1, j = 0; i <= m; i++) {
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j++;
        if (j == n) {
            return true;
        }
    }
    return false;
}

int main() {
    while (cin >> substr + 1 >> s + 1, p[1] != '0' && s[1] != '0') {
        n = strlen(substr + 1);
        m = strlen(s + 1);
        for (int i = m + 1; i <= 2 * m + 1; i++) {
            substr[i] = substr[i - m];
        }

        for (int i = 1; i <= m + 1; i++) {
            flag=false;
            memset(ne, 0, sizeof ne);
            for (int j = 1, cnt = i; j <= m + 1; j++)p[j] = substr[cnt++];
            if (kmp()) {
                flag= true;
                break;
            }
        }
        if (flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }


    return 0;
}

