#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 1010, mod = 1e9 + 7;
int n, m;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n >> m;
    vector<int> f(m + 1), c(m + 1, 1);//不选也是一种方案
    for (int i = 1; i <= n; i++) {
        int v, w;
        cin >> v >> w;
        for (int j = m; j >= v; j--) {
            if (f[j - v] + w > f[j]) {
                f[j] = f[j - v] + w;
                c[j] = c[j - v];
            } else if (f[j - v] + w == f[j]) {
                c[j] = (c[j] + c[j - v]) % mod;
            }
        }
    }
    cout<<c[m]<<endl;


    return 0;
}