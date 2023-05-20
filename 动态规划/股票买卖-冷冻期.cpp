#include <bits/stdc++.h>

#define int long long
using namespace std;


signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i++) cin >> w[i];
    vector<vector<int>> f(n + 1, vector<int>(3));

    f[0][1] = f[0][0] = -INT_MAX;
    for (int i = 1; i <= n; i++) {
        f[i][1] = max(f[i - 1][1], f[i - 1][2] - w[i]);
        f[i][0] = f[i - 1][1] + w[i];
        f[i][2] = max(f[i - 1][0], f[i - 1][2]);
    }
    cout<<max(f[n][0],f[n][2])<<endl;

    return 0;
}