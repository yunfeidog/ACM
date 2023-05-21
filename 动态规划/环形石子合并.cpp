#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 410;
int a[N], s[N];
int f[N][N], g[N][N];
int n;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    memset(f, 0x3f, sizeof f), memset(g, -0x3f, sizeof g);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int i = 1; i <= 2 * n; i++) {
        s[i] = s[i - 1] + a[i];
        g[i][i] = 0, f[i][i] = 0;
    }

    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= 2 * n; l++) {
            int r = l + len - 1;
            for (int k = l; k < r; k++) {
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
                g[l][r] = max(g[l][r], g[l][k] + g[k + 1][r] + s[r] - s[l - 1]);
            }
        }
    }
    int mi = INT_MAX, mx = -INT_MAX;
    for (int i = 1; i <= n; i++) {
        mi = min(mi, f[i][i + n - 1]);
        mx = max(mx, g[i][i + n - 1]);
    }
    cout << mi << "\n" << mx << endl;

    return 0;
}