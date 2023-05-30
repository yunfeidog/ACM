#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 1010;
double f[N][N];

double dfs(int i, int j) {
    if (f[i][j]) return f[i][j];
    if (i == 0) return f[i][j] = 0;
    if (j == 0) return f[i][j] = 1.0;
    f[i][j] += 1.0 * i / (i + j);//先白
    if (i >= 1 && j >= 2)
        f[i][j] += 1.0 * j / (i + j) * (j - 1) / (i + j - 1) * i / (i + j - 2) * dfs(i - 1, j - 2);
    if (j >= 3)
        f[i][j] += 1.0 * j / (i + j) * (j - 1) / (i + j - 1) * (j - 2) / (i + j - 2) * dfs(i, j - 3);
    return f[i][j];
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int w, b;
    cin >> w >> b;
    double t = dfs(w, b);
    std::printf("%.10f", t);


    return 0;
}