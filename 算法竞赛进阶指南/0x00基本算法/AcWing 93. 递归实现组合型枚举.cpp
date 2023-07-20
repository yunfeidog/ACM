#include <bits/stdc++.h>

#define int long long
using namespace std;
int n, m;


//dfs搜索
vector<int> res;

void dfs(int x) {
    if (res.size() > m || (res.size() + (n - x + 1)) < m)return;
    if (x == n + 1) {
        for (const auto &item: res) {
            cout << item << " ";
        }
        cout << endl;
        return;
    }
    res.push_back(x);
    dfs(x + 1);
    res.pop_back();
    dfs(x + 1);
}

void dfs(int u, int cnt) {
    if (cnt == m + 1) {
        for (const auto &item: res) {
            cout << item << " ";
        }
        cout << endl;
        return;
    }
    for (int i = u; i <= n; i++) {
        res.push_back(i);
        dfs(i + 1, cnt + 1);
        res.pop_back();
    }
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n >> m;
//    dfs(1);
    dfs(1, 1);

    return 0;
}