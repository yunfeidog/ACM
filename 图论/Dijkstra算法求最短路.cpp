#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 1e5 + 10;
typedef pair<int, int> PII;
typedef struct edge {
    int y, w;
} edge;

vector<edge> e[N];
int dist[N];
bool st[N];
int n, m, s;

void Dijkstra() {
    priority_queue<PII, vector<PII>, greater<>> q;
    q.push({0, s});
    for (int i = 1; i <= n; i++) dist[i] = 1e18;
    dist[s] = 0;
    while (q.size()) {
        auto [d, x] = q.top();
        q.pop();
        if (st[x]) continue;
        st[x] = true;
        for (auto [y, w]: e[x]) {
            if (dist[y] > dist[x] + w) {
                dist[y] = dist[x] + w;
                q.push({dist[y], y});
            }
        }
    }
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n >> m >> s;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        e[a].push_back({b, c});
    }
    Dijkstra();
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }


    return 0;
}