#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 210;
int n;
int a[N];
int f[N][N];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    for (int len = 3; len <= n + 1; len++) {
        for (int l = 1; l + len - 1 <= 2 * n; l++) {
            int r = l + len - 1;
            for (int k = l + 1; k < r; k++) {
                f[l][r] = max(f[l][r], f[l][k] + f[k][r] + a[l] * a[k] * a[r]);
            }
        }
    }
    int res = 0;
    for (int i = 0; i <= n; i++) res = max(res, f[i][i + n]);
    cout << res << endl;

    return 0;
}