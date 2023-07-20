#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 1e5 + 10, mod = 1e9 + 7;
int f[N], g[N];

int qmi(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void init() {
    f[0] = g[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = f[i - 1] * i % mod;
        g[i] = g[i - 1] * qmi(i, mod - 1) % mod;
    }
}

int get(int n, int m) {
    return f[n] * g[m] % mod * g[n - m] % mod;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif


    return 0;
}