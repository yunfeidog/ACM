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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> f(n + 1), g(n + 1);
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[j] < a[i]) f[i] = max(f[i], f[j] + 1);
        }
    }
    for (int i = n; i >= 1; i--) {
        g[i] = 1;
        for (int j = n; j > i; j--) {
            if (a[j] < a[i]) g[i] = max(g[i], g[j] + 1);
        }
    }
    int t = 0;
    for (int i = 1; i <= n; i++) {
        t = max(t, f[i] + g[i] - 1);
    }
    cout << n-t << endl;
    return 0;
}