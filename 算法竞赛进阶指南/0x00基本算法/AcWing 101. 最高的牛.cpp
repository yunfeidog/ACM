#include <bits/stdc++.h>

#define int long long
using namespace std;


signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n, p, h, m;
    cin >> n >> p >> h >> m;
    vector<int> a(n + 2);
    map<pair<int, int>, bool> st;
    while (m--) {
        int x, y;
        cin >> x >> y;
        if (st[{x, y}]) continue;
        if (x > y) swap(x, y);
        a[x + 1]--, a[y]++;
        st[{x, y}] = true;
    }
    for (int i = 1; i <= n; i++) a[i] += a[i - 1];
    int t = h - a[p];
    for (int i = 1; i <= n; i++) {
        a[i] += t;
    }
    for (int i = 1; i <= n; i++) cout << a[i] << "\n";
    return 0;
}