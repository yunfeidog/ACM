#include <iostream>
#include <cstdio>

#define int long long
using namespace std;

const int N = 130;
double p[N][N];
double f[N][N];
int n, m;

void solve() {
    m = 1 << n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lf", &p[i][j]);
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            f[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) f[0][i] = 1;

    for (int i = 1; i <= n; i++) { //多少场
        for (int j = 0; j < m; j++) {//第j个队伍
            for (int k = 0; k < m; k++) {//对手队伍
                int x = (j >> (i - 1)) ^ 1;
                int y = (k >> (i - 1));
                if (x == y) {
                    f[i][j] += f[i - 1][j] * f[i - 1][k] * p[j][k];
                }
            }
        }
    }
    int idx = 0;
    double max = -1;
    for (int i = 0; i < m; i++) {
        if (f[n][i] > max) {
            idx = i + 1;
            max = f[n][i];
        }
    }
    cout << idx << endl;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    while (scanf("%lld", &n), n != -1) solve();
    return 0;
}