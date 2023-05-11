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
    vector<int> a(n + 1), b(n + 1), f;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[x] = i;
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        b[i] = a[x];
    }
    //求b的最长上升子序列
    f.push_back(b[1]);
    for (int i = 2; i <= n; i++) {
        if (b[i] > f.back()) f.push_back(b[i]);
        else *std::lower_bound(f.begin(), f.end(), b[i]) = b[i];

    }
    cout << f.size();
    return 0;
}