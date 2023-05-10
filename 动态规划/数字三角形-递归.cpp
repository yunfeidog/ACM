#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 1010;
int n;
int a[N][N];
int f[N][N]; //记录从下到上累加和

int dfs(int x, int y) {
    if (f[x][y] != -1) return f[x][y]; //记忆化，避免进一步递归
    if (x == n) f[x][y] = a[x][y];
    else f[x][y] = max(dfs(x + 1, y), dfs(x + 1, y + 1)) + a[x][y];
    return f[x][y];
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> a[i][j];
        }
    }
    memset(f,-1,sizeof f);
    dfs(1, 1);
    cout << f[1][1];
    return 0;
}