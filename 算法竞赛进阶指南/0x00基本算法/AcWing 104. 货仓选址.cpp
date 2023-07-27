#include <bits/stdc++.h>

#define int long long
using namespace std;


signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    std::sort(a.begin() + 1, a.end());
    int t;
    if (n & 1) {
        t = a[(n + 1) / 2];
    } else {
        t = (a[n / 2] + a[n / 2 + 1]) / 2;
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res += abs(a[i] - t);
    }
    cout << res << endl;

    return 0;
}