#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 20;
int n;
int w[N][N];
int f[1 << N][N];
//fij表示从0走到j，当前状态为i的最小值

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }
    memset(f, 0x3f, sizeof f);
    f[0][0] = 0;
    for (int i = 0; i < 1 << n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >> j & 1) {
                for (int k = 0; k < n; k++) {
                    if (i >> k & 1) {
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]);
                    }
                }
            }
        }
    }
    cout << f[(1 << n) - 1][n - 1];


    return 0;
}