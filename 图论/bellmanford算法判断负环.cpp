#include <bits/stdc++.h>

#define int long long
using namespace std;
const int N = 2e3 + 10;
int n, m;

typedef struct node {
    int y, w;
} node;
vector<node> e[N];
int dist[N];


bool bellmanford() {
    for (int i = 1; i <= n; i++) dist[i] = 1e18;
    dist[1] = 0;
    bool flag;
    for (int i = 1; i <= n; i++) {
        flag = false;
        for (int j = 1; j <= n; j++) {
            if (dist[j] == 1e18) continue;
            for (auto [y, w]: e[j]) {
                if (dist[y] > dist[j] + w) {
                    dist[y] = dist[j] + w;
                    flag = true;
                }
            }
        }
        if (!flag) break;
    }
    return flag;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) e[i].clear();
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        e[a].push_back({b, c});
        if (c >= 0) e[b].push_back({a, c});
    }
    if (bellmanford()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }


}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int _;
    cin >> _;
    while (_--) solve();


    return 0;
}