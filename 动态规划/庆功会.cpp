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
    vector<int> f(m + 1);
    for (int i = 1; i <= n; i++) {
        int v, w, s;
        cin >> v >> w >> s;
        for (int j = m; j >= v; j--) {
            for (int k = 0; k <= s; k++) {
                if (j >= k * v)
                    f[j] = max(f[j], f[j - k * v] + k * w);
            }
        }
    }
    cout << f[m] << endl;


    return 0;
}
