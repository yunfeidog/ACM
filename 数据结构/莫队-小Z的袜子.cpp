/**
 * https://www.luogu.com.cn/problem/P1494
 */
#include <bits/stdc++.h>

#define int long long
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define IOS cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);
#define cxk 1
#define debug(s, x) if (cxk) cout << "#debug:(" << s << ")=" << x << endl;
using namespace std;

int gcd(int a, int b) {//最大公约数
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {//最小公倍数
    return a * b / gcd(a, b);
}

const int N = 5e4 + 10;
int block, sum;

struct query {
    int l, r, id;

    bool operator<(const query &W) const {
        if (l / block != W.l / block) return l < W.l;
        if (l / block & 1) return r < W.r;
        return r > W.r;
    }
} a[N];

int c[N], ans1[N], ans2[N];
int cnt[N];


void add(int pos) {
    sum += cnt[c[pos]];
    cnt[c[pos]]++;
}

void del(int pos) {
    cnt[c[pos]]--;
    sum -= cnt[c[pos]];
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
        if (L == R) {
            ans1[id] = 0, ans2[id] = 1;
            continue;
        }
        while (l > L) add(--l);
        while (l < L) del(l++);
        while (r < R) add(++r);
        while (r > R) del(r--);
        ans1[id] = sum;
        ans2[id] = (r - l + 1) * (r - l) / 2;
    }
    for (int i = 0; i < q; i++) {
        if (ans1[i] != 0) {
            int t = gcd(ans1[i], ans2[i]);
            ans1[i] /= t, ans2[i] /= t;
        } else {
            ans2[i] = 1;
        }
        cout << ans1[i] << "/" << ans2[i] << endl;
    }
}

signed main() {
    IOS
    int _ = 1;
    while (_--) solve();
    return 0;
}