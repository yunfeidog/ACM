#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 1010;
int n;
int a[N][N];
int f[N][N];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> a[i][j];
            f[i][j] = max(f[i - 1][j - 1], f[i - 1][j]) + a[i][j];
        }
    }
    int t = -1;
    for (int i = 1; i <= n; i++) {
        t = max(t, f[n][i]);
    }
    cout << t << endl;
    return 0;
}