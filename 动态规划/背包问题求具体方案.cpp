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
    vector<vector<int> > f(n + 2, vector<int>(m + 1));
    vector<int> v(n + 2), w(n + 2);
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];

    for (int i = n; i >= 1; i--) {
        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i + 1][j];
            if (j >= v[i])
                f[i][j] = max(f[i][j], f[i + 1][j - v[i]] + w[i]);
        }
    }

    int j = m;
    for (int i = 1; i <= n; i++) {
        if (j >= v[i] && f[i][j] == f[i + 1][j - v[i]] + w[i]) {
            cout << i << " ";
            j -= v[i];
        }
    }


    return 0;
}