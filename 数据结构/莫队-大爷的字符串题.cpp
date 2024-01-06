/**
* https://www.luogu.com.cn/problem/P3709
*/
#include <bits/stdc++.h>

#define int long long
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define IOS cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);
#define cxk 1
#define debug(s, x) if (cxk) cout << "#debug:(" << s << ")=" << x << endl;
using namespace std;


const int N = 2e5 + 10;
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
int cnt[N];//i出现的次数
int cnt2[N];//出现次数为i的数有多少个


void add(int pos) {
    int x = c[pos];
    cnt2[cnt[x]]--;
    cnt[x]++;
    cnt2[cnt[x]]++;
    sum = max(sum, cnt[x]);
}

void del(int pos) {
    int x = c[pos];
    cnt2[cnt[x]]--;
    if (cnt2[cnt[x]] == 0 && cnt[x] == sum) sum--;
    cnt[x]--;
    cnt2[cnt[x]]++;
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

    int num = 1;
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        if (mp[c[i]] != 0) c[i] = mp[c[i]];
        else mp[c[i]] = num++, c[i] = mp[c[i]];
    }

    for (int i = 0, l = 1, r = 0; i < q; i++) {
        auto [L, R, id] = a[i];
        while (l > L) add(--l);
        while (l < L) del(l++);
        while (r < R) add(++r);
        while (r > R) del(r--);
        ans[id] = -sum;
    }
    for (int i = 0; i < q; ++i) {
        cout << ans[i] << endl;
    }
}


signed main() {
    IOS
    int _ = 1;
    while (_--) solve();
    return 0;
}