#include <bits/stdc++.h>

#define int long long
using namespace std;
const int N = 20;
int f[N][N];

int edit(string a, string b) {
    int n = a.size(), m = b.size();
    a = " " + a, b = " " + b;
    for (int i = 1; i <= n; i++) f[i][0] = i;
    for (int i = 1; i <= m; i++) f[0][i] = i;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) f[i][j] = f[i - 1][j - 1];
            else f[i][j] = min(f[i - 1][j - 1], min(f[i][j - 1], f[i - 1][j])) + 1;

        }
    }
    return f[n][m];
}


signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<string> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (m--) {
        string s;
        int limit;
        cin >> s >> limit;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (edit(a[i], s) <= limit) res++;
        }
        cout << res << endl;
    }

    return 0;
}