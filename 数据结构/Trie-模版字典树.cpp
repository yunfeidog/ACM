/**
 * https://www.luogu.com.cn/problem/P8306
 */
#include <bits/stdc++.h>

#define int long long
using namespace std;

//空间怎么看开多大？看数据范围 输入总字符串总长度不超过3e6
const int N = 3e6 + 10;
int son[N][65], cnt[N], idx;

int get(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 26;
    if (c >= '0' && c <= '9') return c - '0' + 26 + 26;

}

void insert(string s) {
    int x = 0;
    for (char c: s) {
        int y = get(c);
        if (!son[x][y]) son[x][y] = ++idx;
        x = son[x][y];
        cnt[x]++;
    }
}

int query(string s) {
    int x = 0;
    for (auto c: s) {
        int y = get(c);
        if (!son[x][y]) return 0;
        x = son[x][y];
    }
    return cnt[x];
}


void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    while (n--) { cin >> s, insert(s); }
    while (q--) { cin >> s, cout << query(s) << '\n'; }

    //清空字典树,不使用memset,使用for
    for (int i = 0; i <= idx; i++) {
        for (int j = 0; j < 63; j++) {
            son[i][j] = 0;
        }
    }
    for (int i = 0; i <= idx; i++) cnt[i] = 0;
    idx = 0;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}