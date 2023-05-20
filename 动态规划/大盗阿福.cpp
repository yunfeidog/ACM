#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), f(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    f[1]=a[1],f[2]= max(a[1],a[2]);
    for (int i = 3; i <= n; i++) {
        f[i]= max(f[i-1],f[i-2]+a[i]);
    }
    cout<<f[n]<<endl;
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