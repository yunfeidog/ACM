#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int f[N][110][2];

int main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= k; i++) f[0][i][1] = -0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1] + a[i]);//前一天空仓或者卖出
            f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j - 1][0] - a[i]);
        }
    }
    int res = 0;
    for (int j = 0; j <= k; j++) res = max(res, f[n][j][0]);
    cout << res << endl;

    return 0;
}