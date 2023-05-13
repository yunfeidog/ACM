#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 2e4 + 10;
int f[N], g[N], q[N];//q数组存下标


signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n, m, v, w, s;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::memcpy(g, f, sizeof f);
        cin >> v >> w >> s;
        for (int j = 0; j < v; j++) {
            int h = 0, t = -1;//h为头，t为尾
            for (int k = j; k <= m; k += v) {
                //q[h]不在窗口[k-s*v,k-v]中，队头出队
                if (h <= t && q[h] < k - s * v) h++;
                //使用队头最大值来更新f (k-q[h])/v是还可以放进物品的个数
                if (h <= t) f[k] = max(g[k], g[q[h]] + (k - q[h]) / v * w);
                //当前值比队尾更有价值，队尾出队
                while (h <= t && g[k] >= g[q[t]] + (k - q[t]) / v * w) t--;
                //下标入队，便于队头出队
                q[++t] = k;
            }
        }
    }
    cout<<f[m]<<endl;


    return 0;
}