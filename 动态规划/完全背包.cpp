#include <bits/stdc++.h>

#define int long long
using namespace std;


signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1), w(n + 1);
    vector<vector<int> > f(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (j < v[i]) f[i][j] = f[i - 1][j];
                else f[i][j] = max(f[i - 1][j], f[i][j - v[i]] + w[i]);
            }
        }
    cout << f[n][m] << endl;

    return 0;
}