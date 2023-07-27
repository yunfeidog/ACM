#include <bits/stdc++.h>

using namespace std;

typedef struct edge {
    int to, w;
} edge;

const int N = 1e5 + 10;
int son[N * 31][2], cnt[N], idx;
int sum[N];// 存到根节点到异或值
vector<edge> e[N];
int n;

void dfs(int x, int fa) {
    for (auto [y, w]: e[x]) {
        if (y == fa) continue;
        sum[y] = sum[x] ^ w;
        dfs(y, x);
    }
}

void insert(int t) {
    int x = 0;
    for (int i = 30; i >= 0; i--) {
        int y = t >> i & 1;
        if (!son[x][y]) son[x][y] = ++idx;
        x = son[x][y];
    }
}

int query(int t) {
    int x = 0, res = 0;
    for (int i = 30; i >= 0; i--) {
        int y = t >> i & 1;
        if (son[x][!y]) {
            res += 1 << i;
            x = son[x][!y];
        } else {
            x = son[x][y];
        }
    }
    return res;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        e[x].push_back({y, w});
        e[y].push_back({x, w});
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) insert(sum[i]);
    int res = 0;
    for (int i = 1; i <= n; i++) res = max(res, query(sum[i]));
    cout << res << endl;

    return 0;
}