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
    vector<int> f;
    for (int i = 1; i <= n; i++) cin >> a[i];
    f.push_back(a[1]);
    for (int i = 2; i <= n; i++) {
        if (a[i] >= f.back()) f.push_back(a[i]);
        else *std::lower_bound(f.begin(), f.end(), a[i]) = a[i];
    }
    cout << f.size();
    return 0;
}