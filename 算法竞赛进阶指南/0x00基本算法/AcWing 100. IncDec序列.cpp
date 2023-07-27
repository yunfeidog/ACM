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
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) b[i] = a[i] - a[i - 1];
    int x = 0, y = 0;
    for (int i = 2; i <= n; i++) {
        if (b[i] > 0) x += b[i];
        if (b[i] < 0) y += b[i];
    }
    cout << min(x, -y) + abs(x + y) << endl;
    cout << abs(x +y) + 1 << endl;

    return 0;
}