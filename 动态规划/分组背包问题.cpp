#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 110;
int v[N], w[N];
int f[N];
int n, m, s;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 1; j <= s; j++) cin >> v[j] >> w[j];
        for (int j = m; j >= 1; j--) {
            for(int k=0;k<=s;k++){
                if (j>=v[k]){
                    f[j]= max(f[j],f[j-v[k]]+w[k]);
                }
            }
        }
    }
    cout<<f[m];

    return 0;
}