#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 100;
int n, m;
int f[N * 2][N][N];
int g[N][N];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    for (int k = 2; k <= n + m; k++) {
        for (int x1 = 1; x1 < k; x1++) {
            for (int x2 = 1; x2 < k; x2++) {
                int y1 = k - x1, y2 = k - x2;
                if (y1 < 1 || y1 > m || y2 < 1 || y2 > m) continue;
                int &x = f[k][x1][x2];
                x = max(x, f[k - 1][x1][x2]);
                x = max(x, f[k - 1][x1][x2 - 1]);
                x = max(x, f[k - 1][x1 - 1][x2]);
                x = max(x, f[k - 1][x1 - 1][x2 - 1]);
                if (x1 == x2 && y1 == y2) x += g[x1][y1];
                else x += g[x1][y1] + g[x2][y2];
            }
        }
    }
    cout << f[n + m][n][n];
    return 0;
}