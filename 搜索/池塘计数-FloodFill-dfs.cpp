#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 1010;
char g[N][N];
bool st[N][N];
int n, m;


void dfs(int a, int b) {
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int x = a + i, y = b + j;
            if (x < 1 || x > n || y < 1 || y > m) continue;
            if (g[x][y]=='W'){
                g[x][y]='.';
                dfs(x,y);
            }
        }
    }
}


signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == 'W') {
                dfs(i, j);
                res++;
            }
        }
    }
    cout<<res<<endl;

    return 0;
}