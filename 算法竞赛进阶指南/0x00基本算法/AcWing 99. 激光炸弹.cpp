#include <bits/stdc++.h>

using namespace std;

const int N = 5010;
int g[N][N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n, r;
    cin >> n >> r;
    r = min(r, 5001);
    while (n--) {
        int x, y, w;
        cin >> x >> y >> w;
        x++, y++;
        g[x][y] += w;
    }
    for (int i = 1; i <= 5001; i++) {
        for (int j = 1; j <= 5001; j++) {
            g[i][j] += g[i][j - 1] + g[i - 1][j] - g[i - 1][j - 1];
        }
    }
    int mx = 0;
    for (int i = min(r, 5001); i <= 5001; i++) {
        for (int j = min(r, 5001); j <= 5001; j++) {
            int t = g[i][j] - g[i - r][j] - g[i][j - r] + g[i - r][j - r];
            mx = max(t, mx);
        }
    }
    cout << mx << endl;


    return 0;
}