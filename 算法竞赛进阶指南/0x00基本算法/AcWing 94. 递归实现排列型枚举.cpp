#include <bits/stdc++.h>

#define int long long
using namespace std;

vector<int> res;
vector<bool> st(20);
int n;

void dfs(int u) {
    if (u == n + 1) {
        for (const auto &item: res) {
            cout << item << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (st[i]) continue;
        st[i] = true;
        res.push_back(i);
        dfs(u + 1);
        res.pop_back();
        st[i] = false;
    }
}

void solve2() {
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = i + 1;
    //next_permutation(数组头地址，数组尾地址);若下一个排列存在，则返回真，如果不存在则返回假
    //如果只有一个数，那就没有下一个全排列，因此需要一个do
    do {
        for (const auto &item: a) cout << item << " ";
        cout << endl;
    } while (std::next_permutation(a.begin(), a.end()));
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n;
//    dfs(1);
    solve2();


    return 0;
}