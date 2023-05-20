#include <bits/stdc++.h>

#define int long long
using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> f(n + 1, vector<int>(2));
    f[1][0] = 0, f[1][1] = a[1];
    for (int i = 2; i <= n; i++) {
        f[i][0] = max(f[i - 1][1], f[i - 1][0]);
        f[i][1] = f[i - 1][0] + a[i];
    }
    cout<<max(f[n][0],f[n][1])<<endl;

}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}