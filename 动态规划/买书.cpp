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
    int v[5] = {0, 10, 20, 50, 100};
    vector<int> f(n + 1);
    f[0] = 1;
    //fi表示价格不超过i的选法的个数
    for (int i = 1; i <= 4; i++) {
        for (int j = v[i]; j <= n; j++) {
            f[j] += f[j - v[i]];
        }
    }
    cout << f[n] << endl;

    return 0;
}