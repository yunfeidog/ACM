#include <bits/stdc++.h>

#define int long long
using namespace std;


signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> a, b;
    for (int i = 1; i <= n; i++) {
        int v, w, s;
        cin >> v >> w >> s;
        for (int j = 1; j <= s; j <<= 1) {
            a.push_back(j * v);
            b.push_back(j * w);
            s -= j;
        }
        if (s){
            a.push_back(s*v);
            b.push_back(s*w);
        }
    }
    //01背包
    vector<int> f(m+1);
    for(int i=0;i<a.size();i++){
        for(int j=m;j>=a[i];j--){
            f[j]= max(f[j],f[j-a[i]]+b[i]);
        }
    }
    cout<<f[m];

    return 0;
}