#include <bits/stdc++.h>

#define int long long
using namespace std;
typedef pair<int, int> PII;
const int N = 1010;
char g[N][N];
bool st[N][N];
int n, m;

void bfs(int startx, int starty) {
    queue<PII> q;
    q.push({startx, starty});
    st[startx][starty] = true;
    while (q.size()) {
        auto t = q.front();
        q.pop();
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int x = t.first + i, y = t.second + j;
                if (x < 1 || x > n || y < 1 || y > m) continue;
                if (!st[x][y] && g[x][y] == 'W') {
                    q.push({x, y});
                    st[x][y] = true;
                }
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
            if (g[i][j] == 'W' && !st[i][j]) {
                bfs(i, j);
                res++;
            }
        }
    }
    cout<<res<<endl;

    return 0;
}