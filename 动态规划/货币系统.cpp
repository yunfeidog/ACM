#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    std::sort(a.begin() + 1, a.end());
    vector<int> f(a[n] + 1);
    f[0] = 1; //当前体积为j的所有方案。
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (f[a[i]]) continue;
        ans++;
        for (int j = a[i]; j <= a[n]; j++) {
            f[j] |= f[j - a[i]];
        }
    }
    cout << ans << endl;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int _;
    cin >> _;
    while (_--) solve();


    return 0;
}