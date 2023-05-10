#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 20;
int g[N][N];
//f[k][x1][x2] 表示同时走k步，从1，1走到 x1,y1 x2,y2可以得到的花生的最大数量
int f[N][N][N];
int n;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n;
    int a, b, c;
    while (cin >> a >> b >> c, a || b || c)g[a][b] = c;

    for (int k = 2; k <= 2 * n; k++) {
        for (int x1 = 1; x1 <= n; x1++) {
            for (int x2 = 1; x2 <= n; x2++) {
                int y1 = k - x1, y2 = k - x2;
                if (y1 >= 1 && y1 <= n && y2 >= 1 && y2 <= n) {
                    int t = g[x1][y1];
                    if (x1 != x2) t += g[x2][y2];
                    int &x = f[k][x1][x2];
                    x = max(x, f[k - 1][x1 - 1][x2 - 1] + t);
                    x = max(x, f[k - 1][x1 - 1][x2] + t);
                    x = max(x, f[k - 1][x1][x2 - 1] + t);
                    x = max(x, f[k - 1][x1][x2] + t);
                }
            }
        }
    }
    cout << f[n + n][n][n] << endl;

    return 0;
}