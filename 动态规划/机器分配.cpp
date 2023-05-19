#include <bits/stdc++.h>

#define int long long
using namespace std;

int n, m;
int w[20][20];
int f[20][20];
int path[20];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> w[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i - 1][j];
            for (int k = 1; k <= j; k++) {
                f[i][j] = max(f[i][j], f[i - 1][j - k] + w[i][k]);
            }
        }
    }
    cout << f[n][m] << endl;
    int j = m;
    for (int i = n; i >= 1; i--) {
        for (int k = 0; k <= j; k++) {
            if (f[i][j] == f[i - 1][j - k] + w[i][k]) {
                path[i] = k;
                j-=k;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<i<<" "<<path[i]<<endl;
    }

    return 0;
}