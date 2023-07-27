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
    int res = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i] > a[i - 1]) {
            res += a[i] - a[i - 1];
        }
    }
    cout << res << endl;


    return 0;
}