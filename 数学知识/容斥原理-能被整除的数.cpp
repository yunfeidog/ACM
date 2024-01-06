/**
 * https://www.acwing.com/problem/content/892/
 */
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
    int ans = 0;
    vector<int> p(m);
    for (int i = 0; i < m; ++i) cin >> p[i];
    for (int i = 1; i < (1 << m); i++) {
        int t = 1, sign = -1;
        for (int j = 0; j < m; j++) {
            if (i >> j & 1) {
                t *= p[j];
                if (t > n) {
                    t = 0;
                    break;
                }
                sign = -sign;
            }
        }
        if (t)ans += sign * (n / t);
    }
    cout << ans << endl;
    return 0;
}