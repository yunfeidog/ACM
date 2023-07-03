#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 1e5 + 10;
typedef pair<int, int> PII;
vector<PII> e[N];
int n, m;
vector<int> d(N), k(N);
vector<double> f(N);

void topsort() {
    queue<int> q;
    q.push(n);
    while (q.size()) {
        auto x = q.front();
        q.pop();
        for (auto [y, w]: e[x]) {
            f[y] += (f[x] + w) * 1 / k[y];
            if (--d[y] == 0)q.push(y);
        }
    }
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
        e[b].push_back({a, c});
        d[a]++, k[a]++;
    }
    topsort();
    std::printf("%.2f", f[1]);


    return 0;
}