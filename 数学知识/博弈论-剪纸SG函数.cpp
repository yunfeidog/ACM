#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 210;
int n, m;
int f[N][N];

int dfs(int a, int b) {
    if (f[a][b] != -1) return f[a][b];
    set<int> s;
    for (int i = 2; i <= a - 2; i++) {
        s.insert(dfs(i, b) ^ dfs(a - i, b));
    }

    for (int i = 2; i <= b - 2; i++) {
        s.insert(dfs(a, i) ^ dfs(a, b - i));
    }
    for (int i = 0;; i++) {
        if (!s.count(i)) return f[a][b] = f[b][a] = i;
    }

}


signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    memset(f, -1, sizeof f);
    while (cin >> n >> m) cout << (dfs(n, m) ? "WIN" : "LOSE") << endl;

    return 0;
}