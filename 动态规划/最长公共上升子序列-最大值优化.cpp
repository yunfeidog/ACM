#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 3010;
int f[N][N];
int a[N], b[N];
int n;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) {
        int mx = 0;
        for (int j = 1; j <= n; j++) {
            if (a[i] != b[j]) f[i][j] = f[i - 1][j];
            else f[i][j] = max(f[i][j], mx + 1);
            if (a[i] > b[j]) mx = max(mx, f[i - 1][j]);
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) res = max(res, f[n][i]);
    cout << res << endl;

    return 0;
}