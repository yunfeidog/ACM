#include <bits/stdc++.h>

#define int long long
using namespace std;

int n;
const int N = 60;
int a[N];
int up[N], down[N];
int ans = 0;

/**
 * @param u 当前第几个导弹
 * @param s 上
 * @param x 下
 */
void dfs(int u, int s, int x) {
    if (s + x >= ans) return;
    if (u >= n + 1) {
        ans = s + x;
        return;
    }
    //将当前数放到上升子序列中
    int k = 0;
    while (k < s && up[k] >= a[u]) k++; //大于等于当前数
    int t = up[k];
    up[k] = a[u];
    if (k < s) dfs(u + 1, s, x);
    else dfs(u + 1, s + 1, x);
    up[k] = t;//回溯

    //将当前数放到下降子序列中
    k = 0;
    while (k < x && down[k] <= a[u]) k++;//小于等于当前数
    t = down[k];
    down[k] = a[u];
    if (k < x) dfs(u + 1, s, x);
    else dfs(u + 1, s, x + 1);
    down[k] = t;
}

void solve() {
    for (int i = 1; i <= n; i++) cin >> a[i];
    ans = n;
    dfs(1, 0, 0);
    cout << ans << endl;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    while (cin >> n, n) {
        solve();
    }


    return 0;
}