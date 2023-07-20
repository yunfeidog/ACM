#include <bits/stdc++.h>

#define int long long
using namespace std;
int n;

//二进制枚举，每个数选或者不选
void solve1(int n) {
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (i >> j & 1) {
                cout << (j + 1) << " ";
            }
        }
        cout << endl;
    }
}

//dfs搜索
vector<int> res;

void dfs(int x) {
    if (x == n + 1) {
        for (const auto &item: res) {
            cout << item << " ";
        }
        cout << endl;
        return;
    }
    dfs(x + 1);
    res.push_back(x);
    dfs(x + 1);
    res.pop_back();
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n;
//    solve1(n);
    dfs(1);


    return 0;
}