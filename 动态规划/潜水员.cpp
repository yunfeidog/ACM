#include <bits/stdc++.h>

#define int long long
using namespace std;
int f[30][100];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    int s;
    cin >> s;
    memset(f, 0x3f, sizeof f);
    f[0][0] = 0;
    while (s--) {
        int a, b, c;
        cin >> a >> b >> c;
        for (int j = n; j >= 0; j--) {
            for (int k = m; k >= 0; k--) {
                f[j][k] = min(f[j][k], f[max((int) 0, j - a)][max((int) 0, k - b)] + c);
            }
        }
    }
    cout << f[n][m];


    return 0;
}