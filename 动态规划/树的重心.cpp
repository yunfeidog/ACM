#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 1e5 + 10;
vector<int> e[N];
int n;
int sz[N];
int ans = 1e9;

void dfs(int u, int fa) {
    sz[u] = 1;
    int mx = 0;
    for (auto j: e[u]) {
        if (j == fa) continue;
        dfs(j, u);
        sz[u] += sz[j];
        mx = max(mx, sz[j]);
    }
    mx = max(mx, n - sz[u]);
    ans = min(ans, mx);
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}