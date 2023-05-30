#include <bits/stdc++.h>

#define int long long
using namespace std;


signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int w, b;
    cin >> w >> b;
    vector<vector<double>> f(w + 1, vector<double>(b + 1));
    //fij表示袋子里有i只白鼠，j只黑鼠时A获胜的概率
    for (int i = 1; i <= b; i++) f[0][i] = 0;
    for (int i = 1; i <= w; i++) f[i][0] = 1;

    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= b; j++) {
            f[i][j] += 1.0 * i / (i + j);
            if (i >= 1 && j >= 2)
                f[i][j] += 1.0 * j / (i + j) * (j - 1) / (i + j - 1) * i / (i + j - 2) * f[i - 1][j - 2];
            if (j >= 3)
                f[i][j] += 1.0 * j / (i + j) * (j - 1) / (i + j - 1) * (j - 2) / (i + j - 2) * f[i][j - 3];
        }
    }
    printf("%.10f", f[w][b]);

    return 0;
}