/**
 * https://www.luogu.com.cn/problem/P2863
 */
#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 1e4 + 10;
vector<int> e[N];
int dfn[N], low[N], total, cnt;
stack<int> stk;
bool instk[N];
vector<int> scc[N];

void tarjan(int x) {
    dfn[x] = low[x] = ++total;
    stk.push(x), instk[x] = true;
    for (auto y: e[x]) {
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        } else if (instk[y]) {
            low[x] = min(low[x], dfn[y]);
        }
    }
    if (dfn[x] == low[x]) {
        int y;
        cnt++;
        do {
            y = stk.top();
            stk.pop();
            instk[y] = false;
            scc[cnt].push_back(y);
        } while (y != x);
    }
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    int res = 0;
    for (int i = 1; i <= cnt; i++) {
        if (scc[i].size() > 1)
            res++;
    }
    cout << res << endl;

    return 0;
}