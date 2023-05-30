#include <iostream>
#include <vector>
#include <cstdio>
#define int long long
using namespace std;


signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n, s;
    cin >> n >> s;
    vector<vector<double> > f(n + 2, vector<double>(s + 2));
    f[n][s] = 0;
    for (int i = n; i >= 0; i--) {
        for (int j = s; j >= 0; j--) {
            if (i == n && j == s) continue;
            double p1 = 1.0 * i / n * j / s;
            double p2 = 1.0 * i / n * (s - j) / s;
            double p3 = 1.0 * (n - i) / n * j / s;
            double p4 = 1.0 * (n - i) / n * (s - j) / s;
            f[i][j] = (f[i][j + 1] * p2 + f[i + 1][j] * p3 + f[i + 1][j + 1] * p4 + 1) / (1 - p1);
        }
    }
    printf("%10f",f[0][0]);


    return 0;
}