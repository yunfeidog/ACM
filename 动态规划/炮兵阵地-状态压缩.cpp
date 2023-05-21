#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 110, M = 1 << 10;
int n, m;//行数，列数
int g[N];//保存地图各行数值
int cnt;//同一行的合法状态个数
int s[M];//同一行的合法状态集
int num[M];//每个合法状态包含1的个数
int f[N][M][M];//f[i,a,b]表示已经放好前i行，第i行第a各状态，第i-1行第b各状态时，能放置的最大数量



signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == 'P') g[i] = (g[i] << 1) + 1;
            else g[i] = g[i] << 1;
        }
    }
    for (int i = 0; i < 1 << m; i++) {
        if (!(i & i >> 1) && !(i & i >> 2)) {
            s[cnt++] = i;
            for (int j = 0; j < m; j++) num[i] += (i >> j & 1);
        }
    }
    for (int i = 1; i <= n + 2; i++) {
        for (int a = 0; a < cnt; a++) {
            for (int b = 0; b < cnt; b++) {
                for (int c = 0; c < cnt; c++) {
                    if (!(s[a] & s[b]) && !(s[a] & s[c]) && !(s[b] & s[c]) &&
                        (g[i] & s[a]) == s[a] && (g[i - 1] & s[b]) == s[b])
                        f[i][a][b] = max(f[i][a][b], f[i - 1][b][c] + num[s[a]]);
                }
            }
        }
    }
    cout << f[n + 2][0][0];


    return 0;
}