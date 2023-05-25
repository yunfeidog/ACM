#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 5e4 + 10;

vector<int> e[N];
int res = 0;
int d1[N], d2[N];
bool st[N];
int n;
int sum[N];

void dfs(int x, int fa) {
    for (auto y: e[x]) {
        if (y == fa) continue;
        dfs(y, x);
        if (d1[y] + 1 > d1[x]) d2[x] = d1[x], d1[x] = d1[y] + 1;
        else if (d1[y] + 1 > d2[x]) d2[x] = d1[y] + 1;
    }
    res = max(res, d1[x] + d2[x]);
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n;
    //统计每个数的约数之和
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= n / i; j++) {
            sum[i * j] += i;
        }
    }
    //建图
    for (int i = 2; i <= n; i++) {
        if (sum[i] < i) {
            e[sum[i]].push_back(i);
            st[i] = true;
        }
    }
    for (int i = 1; i <= n; i++)
        if (!st[i]) dfs(i, i);
    cout << res << endl;
    return 0;
}