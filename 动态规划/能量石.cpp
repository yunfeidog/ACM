#include <bits/stdc++.h>

#define int long long
using namespace std;

typedef struct node {
    int s, e, l;
    bool operator<(const node cxk) const {
        return s * cxk.l < cxk.s * l;
    }
} node;

int solve() {
    int n;
    cin >> n;
    vector<node> a(n + 1);
    int m = 0;
    for (int i = 1; i <= n; i++) {
        int s, e, l;
        cin >> s >> e >> l;
        a[i] = {s, e, l};
        m += s;
    }
    std::sort(a.begin() + 1, a.end());
    vector<int> f(m + 1, -0x3f3f3f3f);
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        int s = a[i].s, e = a[i].e, l = a[i].l;
        for (int j = m; j >= s; j--) {
            f[j] = max(f[j], f[j - s] + e - (j - s) * l);
        }
    }
    int res=0;
    for(int i=0;i<=m;i++) res= max(res,f[i]);
    return res;

}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        std::printf("Case #%d: %d\n",i, solve());
    }


    return 0;
}