#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 1e5 + 10;
int n, m;
vector<pair<int, int>> e[N];
vector<int> d(N);
vector<double> f(N);//从i走到u的期望

double dfs(int x) {
    if (f[x]) return f[x];
    for (auto [y, w]: e[x]) {
        f[y] = dfs(y);
        f[x] += (f[y] + w) * 1.0 / d[x];
    }
    return f[x];
}


signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        e[a].emplace_back(b, c);
        d[a]++;
    }
    dfs(1);
    std::printf("%.2f", f[1]);
    return 0;
}