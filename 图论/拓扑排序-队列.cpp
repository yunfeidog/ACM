#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 1e5 + 10;
int n, m;
vector<int> e[N], res;
vector<int> d(N);

bool topsort() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 0) q.push(i);
    }
    while (q.size()) {
        auto t = q.front();
        q.pop();
        res.push_back(t);
        for (auto y: e[t]) {
            if (--d[y] == 0) q.push(y);
        }
    }
    return res.size() == n;
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
        d[y]++;
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