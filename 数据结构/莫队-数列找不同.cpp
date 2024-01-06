/**
* https://www.luogu.com.cn/problem/P3901
*/
#include <bits/stdc++.h>

#define int long long
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
#define IOS cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);
#define cxk 1
#define debug(s, x) if (cxk) cout << "#debug:(" << s << ")=" << x << endl;
using namespace std;


const int N = 1e5 + 10;
int block, sum;

struct query {
    int l, r, id;

    bool operator<(const query &W) const {
        if (l / block != W.l / block) return l < W.l;
        if (l / block & 1) return r < W.r;
        return r > W.r;
        //莫队优化 偶数块 r从大到小， 奇数块 r从小到大
    }
} a[N];

int c[N], ans[N];
int cnt[N];

void add(int pos) {
    if (!cnt[c[pos]])sum++;
    cnt[c[pos]]++;
}

void del(int pos) {
    cnt[c[pos]]--;
    if (!cnt[c[pos]]) sum--;
}

void solve() {
    int n, q;
    cin >> n >> q;
    block = sqrt(n);
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 0, l, r; i < q; i++) {
        cin >> l >> r;
        a[i] = {l, r, i};
    }
    sort(a, a + q);
    for (int i = 0, l = 1, r = 0; i < q; i++) {
        auto [L, R, id] = a[i];
        while (l > L) add(--l);
        while (l < L) del(l++);
        while (r < R) add(++r);
        while (r > R) del(r--);
        ans[id] = sum == (r - l + 1);
    }
    for (int i = 0; i < q; i++)
        if (ans[i]) yes else no
}


signed main() {
    IOS
    int _ = 1;
    while (_--) solve();
    return 0;
}