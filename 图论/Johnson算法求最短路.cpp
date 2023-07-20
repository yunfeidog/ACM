#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

const int INF = 1e9;
const int N = 3e3 + 10;
typedef pair<int, int> PII;
typedef long long ll;
typedef struct node {
    int y, w;
} node;
vector<node> e[N];
int n, m;

bool cnt[N];
ll h[N], d[N];

void spfa() {
    for (int i = 1; i <= n; i++) h[i] = 1e18;
    queue<int> q;
    vector<bool> st(n + 1);
    q.push(0);
    h[0] = 0;
    st[0] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        st[x] = false;
        for (auto [y, w]: e[x]) {
            if (h[y] > h[x] + w) {
                h[y] = h[x] + w;
                cnt[y] = cnt[x] + 1;
                if (cnt[y] >= n) {
                    cout << -1;
                    exit(0);
                }
                if (!st[y]) {
                    q.push(y);
                    st[y] = true;
                }
            }
        }
    }
}

void dijkstra(int s) {
    priority_queue<pair<long long, int>> q;
    vector<bool> st(n + 1);
    for (int i = 1; i <= n; i++) d[i] = INF;
    for (int i = 1; i <= n; i++) st[i] = false;
    q.emplace(0, s);
    d[s] = 0;
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (st[u]) continue;
        st[u] = true;
        for (auto [y, w]: e[u]) {
            if (d[y] > d[u] + w) {
                d[y] = d[u] + w;
                if (!st[y]) {
                    q.emplace(-d[y], y);
                }
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        e[a].push_back({b, c});
    }
    for (int i = 1; i <= n; i++) {
        e[0].push_back({i, 0});//加虚拟边
    }
    spfa();
    for (int x = 1; x <= n; x++) {
        for (auto &item: e[x]) {
            item.w += h[x] - h[item.y];//构造新的边权
        }
    }
    for (int i = 1; i <= n; i++) {
        dijkstra(i);

        ll res = 0;
        for (int j = 1; j <= n; j++) {
            if (d[j] == INF) res += (ll) j * INF;
            else res += (ll) j * (d[j] + h[j] - h[i]);
        }
        cout << res << endl;
    }
    return 0;
}