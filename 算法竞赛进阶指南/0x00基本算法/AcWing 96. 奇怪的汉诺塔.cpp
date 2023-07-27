#include <bits/stdc++.h>

#define int long long
using namespace std;


signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n = 12;
    vector<int> f(n + 1), g(n + 1);

    f[1] = 1;
    //三诺塔：
    //先把上面n-1个移动到b，再把最下面的一个移动到c，再把b上面的n-1个移动到c
    for (int i = 2; i <= n; ++i) {
        f[i] = 1 + 2 * f[i - 1];
    }
    for (int i = 2; i <= n; i++) g[i] = 1e18;
    //四诺塔
    //先把上面的j个用四诺塔模式移动到b,再把下面的i-j个用三诺塔模式移动到d，
    //再把那j个用四诺塔模式移动到d
    //为什么这里是四诺塔而不是三诺塔？ 因为先把大的放下面了，移动小的时候，相当于这个可以随便用
    g[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            g[i] = min(g[i], g[j] * 2 + f[i - j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << g[i] << endl;
    }


    return 0;
}