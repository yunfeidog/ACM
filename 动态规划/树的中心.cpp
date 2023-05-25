#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 100010;
typedef struct edge {
    int v, w;
} edge;
vector<edge> e[N];
int res = 1e9;
int d1[N], d2[N], p[N], up[N];
//p[u]记录从u点向下走点最长路径是从哪个点下去的
int n, a, b, c;

void dfs1(int x, int fa) {
    for (auto item: e[x]) {
        int y = item.v, w = item.w;
        if (y == fa) continue;
        dfs1(y, x);
        if (d1[y] + w > d1[x]) {
            d2[x] = d1[x], d1[x] = d1[y] + w, p[x] = y;
        } else if (d1[y] + w > d2[x]) d2[x] = d1[y] + w;
    }
}

void dfs2(int x, int fa) {
    for (auto item: e[x]) {
        int y = item.v, w = item.w;
        if (y == fa) continue;
        if (p[x] == y) up[y] = max(up[x], d2[x]) + w;
        else up[y] = max(up[x], d1[x]) + w;
        dfs2(y, x);
    }
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        cin >> a >> b >> c;
        e[a].push_back({b, c});
        e[b].push_back({a, c});
    }
    dfs1(1, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; i++) {
        res = min(res,max(up[i], d1[i]));
    }
    cout << res << endl;


    return 0;
}