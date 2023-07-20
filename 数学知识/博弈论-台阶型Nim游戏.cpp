#include <bits/stdc++.h>

#define int long long
using namespace std;


signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n, res = 0, x;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (i & 1) res ^= x;
    }
    cout << (res ? "Yes" : "No") << endl;


    return 0;
}