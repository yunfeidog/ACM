#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 2010;
int n, m, v, e;
int c[N], d[N];
double p[N], f[N][N][2], dist[N][N];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n >> m >> v >> e;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) cin >> d[i];
    for (int i = 1; i <= n; i++) cin >> p[i];

    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            if (i != j) dist[i][j] = 1e18;
        }
    }

    for (int i = 1; i <= e; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        dist[x][y] = dist[y][x] = min(dist[x][y], 1.0 * w);
    }

    for (int k = 1; k <= v; k++) {
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i][j][0] = f[i][j][1] = 1e18;
        }
    }
    f[1][0][0] = f[1][1][1] = 0;


    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= min(i, m); j++) {
            //上次不换，这次不换
            double t1 = f[i - 1][j][0] + dist[c[i - 1]][c[i]];
            //上次换，这次不换
            double t2 = f[i - 1][j][1] + dist[c[i - 1]][c[i]] * (1 - p[i - 1]) + dist[d[i - 1]][c[i]] * p[i - 1];
            f[i][j][0] = min(t1, t2);
            //上次不换，这次换
            if (j == 0) continue;
            double t3 = f[i - 1][j - 1][0] + dist[c[i - 1]][c[i]] * (1 - p[i]) + dist[c[i - 1]][d[i]] * p[i];
            //上次换，这次换
            double t4 = f[i - 1][j - 1][1];
            t4 += dist[c[i - 1]][c[i]] * (1 - p[i - 1]) * (1 - p[i]);
            t4 += dist[c[i - 1]][d[i]] * (1 - p[i - 1]) * p[i];
            t4 += dist[d[i - 1]][c[i]] * p[i - 1] * (1 - p[i]);
            t4 += dist[d[i - 1]][d[i]] * p[i - 1] * p[i];
            f[i][j][1] = min(t3, t4);
        }
    }
    double res = 1e18;
    for (int j = 0; j <= m; j++) {
        res = min(res, min(f[n][j][0], f[n][j][1]));
    }
    std::printf("%.2f", res);


    return 0;
}