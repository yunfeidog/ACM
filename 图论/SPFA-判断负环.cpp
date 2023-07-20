#include <bits/stdc++.h>

#define int long long
using namespace std;
const int N = 2010;
typedef struct node {
    int y, w;
} node;

vector<node> e[N];
int n, m;

bool spfa() {
    vector<int> dist(n + 1), cnt(n + 1, 0);
    for (int i = 1; i <= n; i++) dist[i] = 1e18;
    vector<bool> st(n + 1);
    queue<int> q;
    q.push(1);
    st[1] = 1;
    dist[1] = 0;
    while (q.size()) {
        int x = q.front();
        q.pop();
        st[x] = 0;
        for (auto [y, w]: e[x]) {
            if (dist[y] > dist[x] + w) {
                dist[y] = dist[x] + w;
                cnt[y] = cnt[x] + 1;
                if (cnt[y] >= n) return true;
                if (!st[y]) {
                    q.push(y);
                    st[y] = 1;
                }
            }
        }
    }
    return false;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) e[i].clear();
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        e[a].push_back({b, c});
        if (c >= 0)e[b].push_back({a, c});
    }
    if (spfa()) {
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
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}