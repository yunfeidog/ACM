#include <bits/stdc++.h>

#define int long long
using namespace std;
typedef pair<int, int> PII;

vector<PII> master(100);
vector<PII> servent[100];
int f[32010];
int n, m;


signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        int v, p, q;
        cin >> v >> p >> q;
        if (q == 0) master[i] = {v, v * p};
        else servent[q].push_back({v, v * p});
    }

    for (int i = 1; i <= n; i++) {
        if (master[i].first) { //是主件
            for (int j = m; j >= 0; j--) {
                vector<PII> cxk = servent[i]; //所有附件
                for (int k = 0; k < 1 << cxk.size(); k++) {
                    int v = master[i].first, w = master[i].second; //体积，价值
                    for (int u = 0; u < cxk.size(); u++) {
                        if (k >> u & 1) {
                            v += cxk[u].first;
                            w += cxk[u].second;
                        }
                    }
                    if (j >= v) {
                        f[j] = max(f[j], f[j - v] + w);
                    }
                }
            }
        }
    }
    cout<<f[m]<<endl;
    return 0;
}