#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 7500, M = 1010;
double f[N][M];


signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int k, q;
    cin >> k >> q;
    f[0][0] = 1.0;
    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= k; j++) {
            f[i][j] += 1.0 * f[i - 1][j - 1]  * (k - j + 1) / k;
            f[i][j] += 1.0 * f[i - 1][j]  * j / k;
        }
    }
    while (q--) {
        double p;
        cin >> p;
        double t = 1.0 * p / 2000;
        for (int i = 1; i < N; i++) {
            if (f[i][k] > t) {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}