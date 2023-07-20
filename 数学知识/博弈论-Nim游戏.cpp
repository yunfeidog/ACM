#include <bits/stdc++.h>

#define int long long
using namespace std;


signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n;
        int res = 0;
        while (n--) {
            cin >> x;
            res ^= x;
        }
        cout << (res ? "Yes" : "No") << endl;
    }
    return 0;
}