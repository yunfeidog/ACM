#include <bits/stdc++.h>

#define int long long
using namespace std;
typedef pair<int, int> PII;


signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<PII> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    std::sort(a.begin() + 1, a.end());
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) b[i] = a[i].second;
    vector<int> f;
    f.push_back(b[1]);
    for (int i = 2; i <= n; i++) {
        if (b[i] > f.back()) f.push_back(b[i]);
        else *std::lower_bound(f.begin(), f.end(), b[i]) = b[i];
    }
    cout<<f.size();
    return 0;
}