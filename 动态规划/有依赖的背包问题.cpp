#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 110;
int n, m;
int v[N], w[N];
int h[N], e[N], ne[N], idx;
int f[N][N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u) {
    //f[u][i]表示以u为子树，体积不超过i的最大价值
    for (int i = v[u]; i <= m; i++) f[u][i] = w[u];
    for (int i = h[u]; ~i; i = ne[i]) {
        int to = e[i];
        dfs(to);
        for (int j = m; j >= v[u]; j--) {
            for (int k = 0; k <= j - v[u]; k++) {
                f[u][j] = max(f[u][j], f[u][j - k] + f[to][k]);
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
    memset(h, -1, sizeof h);
    int root;
    for (int i = 1; i <= n; i++) {
        int p;//每个节点的父节点
        cin >> v[i] >> w[i] >> p;
        if (p == -1) root = i;
        else add(p, i);
    }
    dfs(root);
    cout << f[root][m];
    return 0;
}