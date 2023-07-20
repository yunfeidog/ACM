#include <bits/stdc++.h>

#define int long long
using namespace std;


signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<pair<string, int>> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    int res = 0;
    int cur = 0;
    auto check = [&](int x, int j) -> bool {
        for (int i = 1; i <= n; i++) {
            auto [op, num] = a[i];
            num = (num >> j & 1);
            if (op == "AND") x &= num;
            else if (op == "OR") x |= num;
            else x ^= num;
        }
        return x;
    };
    for (int i = 30; i >= 0; i--) {
        //看原始位上面这一位放0或者1 能不能使得结果的这一位为1
        if (check(0, i)) { //原始位放0没有限制
            res += (1 << i);
        } else if (cur + (1 << i) <= m) { //放1需要满足小于m
            if (check(1, i)) {
                res += (1 << i);
                cur += (1 << i);
            }
        }
    }
    cout << res << endl;

    return 0;
}