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
    vector<int> v(n + 1), w(n + 1), s(n + 1);
    vector<vector<int> > f(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i] >> s[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k <= s[i] && k * v[i] <= j; k++) {
                f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + w[i] * k);
            }
        }
    }
    cout << f[n][m];


    return 0;
}