#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 2010, mod = 1e9 + 7;
int c[N][N];

void init() {
    for (int i = 0; i < N; i++) c[i][0] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }
    }
}


signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif


    return 0;
}