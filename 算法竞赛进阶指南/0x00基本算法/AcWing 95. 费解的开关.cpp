#include <bits/stdc++.h>

#define int long long
using namespace std;

char g[10][10], tmp[10][10];
int n = 5;
int dx[] = {-1, 0, 1, 0, 0};
int dy[] = {0, 1, 0, -1, 0};

void turn(int a, int b) {
    for (int i = 0; i < 5; i++) {
        int x = a + dx[i], y = dy[i] + b;
        if (x < 1 || x > n || y < 1 || y > n) continue;
        if (g[x][y] == '1') g[x][y] = '0';
        else g[x][y] = '1';
    }

}

void copy() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] = tmp[i][j];
        }
    }
}

void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> tmp[i][j];
        }
    }
    int res = 10;

    //枚举第一行的操作，要么翻要么不翻，最多 2^5个，一旦第一行确定了，后面的都确定了
    for (int i = 0; i < (1 << n); i++) {
        int cnt = 0;
        copy();
        for (int j = 0; j < n; j++) {
            if (i >> j & 1) {
                turn(1, j + 1);
                cnt++;
            }
        }
        //从第2行开始翻，看当前行，翻下一行的，当前行不可以翻
        for (int j = 1; j <= n - 1; j++) {
            for (int k = 1; k <= n; k++) {
                if (g[j][k] == '0') {
                    turn(j + 1, k);
                    cnt++;
                }
            }
        }

        bool ok = true;
        for (int j = 1; j <= 5; j++) {
            if (g[n][j] == '0')ok = false;
        }
        if (ok) res = min(res, cnt);
    }
    if (res > 6) res = -1;
    cout << res << endl;

}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int _ = 1;
    cin >> _;
    while (_--) solve();
    return 0;
}