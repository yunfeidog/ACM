#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 110;
int f[N][N];


signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n, m, w;//个数，体积，容量
    cin >> n >> m >> w;
    for (int i = 1; i <= n; i++) {
        int a, b, c;//体积，重量，价值
        cin >> a >> b >> c;
        for(int j=m;j>=a;j--){
            for(int k=w;k>=b;k--){
                f[j][k]= max(f[j][k],f[j-a][k-b]+c);
            }
        }
    }
    cout<<f[m][w];


    return 0;
}