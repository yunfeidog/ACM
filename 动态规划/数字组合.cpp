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
    vector<int> f(m + 1, -INT_MAX), c(m + 1);
    c[0] = 1;
    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        for (int j = m; j >= v; j--) {
            if (f[j - v] + v > f[j]) {
                f[j] = f[j - v] + v;
                c[j] = c[j - v];
            } else if (f[j] == f[j - v] + v) {
                c[j] += c[j - v];
            }
        }
    }
    cout << c[m] << endl;

    return 0;
}