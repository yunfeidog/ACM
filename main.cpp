#include <bits/stdc++.h>

#define int long long
using namespace std;


signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n, m;
    cin >> m >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> f(m + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= a[i]; j--) {
            f[j] = max(f[j], f[j - a[i]] + a[i]);
        }
    }
    cout << m - f[m] << endl;

    return 0;
}