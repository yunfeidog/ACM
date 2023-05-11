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
    vector<int> f(n+1);
    for(int i=1;i<=n;i++){
        f[i]=a[i];
        for(int j=1;j<i;j++){
            if (a[i]>a[j]) f[i]= max(f[i],f[j]+a[i]);
        }
    }
    auto t=*std::max_element(f.begin(), f.end());
    cout<<t<<endl;

    return 0;
}