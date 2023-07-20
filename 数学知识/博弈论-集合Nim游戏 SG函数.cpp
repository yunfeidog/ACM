#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 110,M=10010;
int a[N];
int n, k, h[M];
int f[M];

int dfs(int x) {
    if (f[x] != -1) return f[x];
    set<int> s;
    for (int i = 1; i <= k; i++) {
        if (x - a[i] >= 0) s.insert(dfs(x - a[i]));
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
    cin >> k;
    for (int i = 1; i <= k; i++) cin >> a[i];
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    memset(f, -1, sizeof f);
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res ^= dfs(h[i]);
    }
    if (res) cout << "Yes";
    else cout << "No";


    return 0;
}