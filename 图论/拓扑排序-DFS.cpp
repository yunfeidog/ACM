#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 1e5 + 10;
vector<int> e[N], res, c(N);
int n, m;

int dfs(int x) {
    c[x] = -1;
    for (auto y: e[x]) {
        if (c[y] == -1) return 0;//有环
        else if (c[y] == 0) {
            int t = dfs(y);
            if (t == 0) return 0;
        }
    }
    c[x] = 1;
    res.push_back(x);
    return 1;
}

bool topsort() {
    for (int i = 1; i <= n; i++) {
        if (c[i] == 0) {
            int t = dfs(i);
            if (t == 0) return 0;
        }
    }
    std::reverse(res.begin(), res.end());
    return 1;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
    }
    if (topsort()) {
        for (const auto &item: res) {
            cout << item << " ";
        }
    } else {
        cout << -1 << endl;
    }


    return 0;
}