#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 310;
int f[N][N]; //合并i,j所需要的最小代价
int a[N];
int s[N];
int n;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    memset(f, 0x3f, sizeof f);
    for (int i = 1; i <= n; i++) {
        f[i][i] = 0;
        s[i] = s[i - 1] + a[i];
    }
    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            for (int k = l; k < r; k++) {
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
            }
        }
    }
    cout << f[1][n] << endl;
    return 0;
}