#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 1010;
int f[N][N];


signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        int v, w;
        cin >> v >> w;
        for (int j = n; j >= v; j--) {
            for (int t = m - 1; t >= w; t--) {
                f[j][t] = max(f[j][t], f[j - v][t - w] + 1);
            }
        }
    }
    cout << f[n][m - 1] << " ";
    for (int i = 0; i <= m; i++) {
        if (f[n][m - 1] == f[n][i]) {
            cout << m - i << endl;
            break;
        }
    }


    return 0;
}