/**
 * https://www.acwing.com/problem/content/145/
 */
#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 1e5 + 10;
int son[N * 32][2], idx;

void insert(int t) {
    int x = 0;
    for (int i = 30; i >= 0; i--) {
        int y = t >> i & 1;
        if (!son[x][y]) son[x][y] = ++idx;
        x = son[x][y];
    }
}

int query(int t) {
    int x = 0, res = 0;
    for (int i = 30; i >= 0; i--) {
        int y = t >> i & 1;
        if (son[x][!y]) {//另一个存在
            res = res * 2 + !y;
            x = son[x][!y];
        } else {
            res = res * 2 + y;
            x = son[x][y];
        }
    }
    return res;
}


signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)cin >> a[i];
    for (int i = 0; i < n; ++i) insert(a[i]);
    int mx = 0;
    for (int i = 0; i < n; ++i) mx = max(mx, a[i] ^ query(a[i]));
    cout << mx << endl;


    return 0;
}