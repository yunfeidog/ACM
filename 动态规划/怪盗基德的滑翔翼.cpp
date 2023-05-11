#include <bits/stdc++.h>

#define int long long
using namespace std;



void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> f, g;
    f.push_back(a[1]);
    for(int i=2;i<=n;i++){
        if (a[i]>f.back()) f.push_back(a[i]);
        else *std::lower_bound(f.begin(), f.end(),a[i])=a[i];
    }
    std::reverse(a.begin()+1, a.end());
    g.push_back(a[1]);
    for(int i=2;i<=n;i++){
        if (a[i]>g.back()) g.push_back(a[i]);
        else *std::lower_bound(g.begin(), g.end(),a[i])=a[i];
    }
    cout<<max(f.size(),g.size())<<endl;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) solve();


    return 0;
}