#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 10010;
int n, ans;
typedef struct edge {
    int v, w;
} edge;

vector<edge> e[N];

int dfs(int u, int fa) {
    int d1 = 0, d2 = 0;//最长和次长
    for (auto j: e[u]) {
        auto [v, w] = j;
        if (v == fa) continue;
        int d = dfs(v, u) + w;
        if (d >= d1) d2 = d1, d1 = d;
        else if (d > d2) d2 = d;
    }
    ans= max(ans,d1+d2);
    return d1;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        e[a].push_back({b, c});
        e[b].push_back({a, c});
    }

    dfs(1, 0);
    cout << ans << endl;


    return 0;
}