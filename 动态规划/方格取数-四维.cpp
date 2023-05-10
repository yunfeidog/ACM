#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 20;
int g[N][N];
int f[N][N][N][N];
int n;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n;
    int a, b;
    while (cin >> a >> b >> g[a][b], a);
    for (int x1 = 1; x1 <= n; x1++) {
        for (int y1 = 1; y1 <= n; y1++) {
            for (int x2 = 1; x2 <= n; x2++) {
                for (int y2 = 1; y2 <= n; y2++) {
                    int &x = f[x1][y1][x2][y2];
                    x = max(x, f[x1 - 1][y1][x2 - 1][y2]);
                    x = max(x, f[x1 - 1][y1][x2][y2 - 1]);
                    x = max(x, f[x1][y1 - 1][x2 - 1][y2]);
                    x = max(x, f[x1][y1 - 1][x2][y2 - 1]);
                    if (x1 == x2 && y1 == y2) x += g[x1][y1];
                    else x += g[x1][y1] + g[x2][y2];
                }
            }
        }
    }
    cout << f[n][n][n][n];

    return 0;
}