#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define int long long
using namespace std;
unordered_map<int, int> mp;

typedef struct node {
    int x, y, id;

    bool operator<(const node &W) const {
        int xx = W.x, yy = W.y;
        if (mp[x] != mp[xx]) return mp[x] > mp[xx];
        return mp[y] > mp[yy];
    }
} node;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cin >> m;
    vector<node> d(m + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> d[i].x;
    }
    for (int i = 1; i <= m; ++i) {
        cin >> d[i].y;
        d[i].id = i;
    }
    for (int i = 1; i <= n; ++i) {
        mp[a[i]]++;
    }
    std::sort(d.begin() + 1, d.end());
    cout << d[1].id;


    return 0;
}