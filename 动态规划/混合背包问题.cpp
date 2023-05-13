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
    vector<int> f(m + 1);
    for (int i = 1; i <= n; i++) {
        int v, w, s;
        cin >> v >> w >> s;
        if (s == 0) {//完全背包问题
            for (int j = v; j <= m; j++)
                f[j] = max(f[j], f[j - v] + w);
        } else {//多重背包问题和01背包问题
            if (s == -1) s = 1;
            for (int j = 1; j <= s; j <<= 1) {
                for (int k = m; k >= j*v; k--) {
                    f[k]= max(f[k],f[k-j*v]+j*w);
                }
                s-=j;
            }
            if (s){
                for(int k=m;k>=s*v;k--){
                    f[k]= max(f[k],f[k-s*v]+s*w);
                }
            }
        }
    }
    cout<<f[m]<<endl;

    return 0;
}