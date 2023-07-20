#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 2e3 + 10;

vector<int> e[N];
int f[N];

int dfs(int x) {
    if (f[x] != -1) return f[x];
    set<int> s;
    for (auto y: e[x]) {
        s.insert(dfs(y));
    }
    for (int i = 0;; i++) {
        if (!s.count(i)) return f[x] = i;
    }

}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
    }
    memset(f, -1, sizeof f);
    int res = 0;
    while (k--) {
        int x;
        cin >> x;
        res ^= dfs(x);
    }
    if (res) cout << "win"; else cout << "lose";


    return 0;
}