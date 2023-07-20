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
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        res ^= a[i];
    }
    if (!res) {
        cout << "lose";
    } else {
        for (int i = 1; i <= n; i++) {
            if ((a[i] ^ res) < a[i]) {
                cout << (a[i] - (a[i] ^ res)) << " " << i << endl;
                a[i] = a[i] ^ res;
                break;
            }
        }
        for (int i = 1; i <= n; ++i) {
            cout << a[i] << " \n"[i == n];
        }
    }


    return 0;
}