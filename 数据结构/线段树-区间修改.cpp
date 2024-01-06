/**
* https://www.luogu.com.cn/problem/P3372
*/
#include <bits/stdc++.h>

#define int long long
using namespace std;

#define  lc p<<1
#define  rc p<<1|1
#define  mid ((tr[p].l+tr[p].r)>>1)

const int N = 1e5 + 10;
int n, q, w[N];

struct Tree {
    int l, r, sum, add;
} tr[N * 4];

void up(int p) {
    tr[p].sum = tr[lc].sum + tr[rc].sum;
}

void down(int p) {
    if (tr[p].add) {
        tr[lc].sum += tr[p].add * (tr[lc].r - tr[lc].l + 1);
        tr[rc].sum += tr[p].add * (tr[rc].r - tr[rc].l + 1);
        tr[lc].add += tr[p].add;
        tr[rc].add += tr[p].add;
        tr[p].add = 0;
    }
}

void build(int p, int l, int r) {
    tr[p] = {l, r, w[l], 0};
    if (l == r) return;
    build(lc, l, mid), build(rc, mid + 1, r);
    up(p);
}

void update(int p, int l, int r, int k) {
    if (l <= tr[p].l && tr[p].r <= r) {
        tr[p].sum += (tr[p].r - tr[p].l + 1) * k;
        tr[p].add += k;
        return;
    }
    down(p);
    if (l <= mid) update(lc, l, r, k);
    if (r >= mid + 1) update(rc, l, r, k);
    up(p);
}

int query(int p, int l, int r) {
    if (l <= tr[p].l && tr[p].r <= r) {
        return tr[p].sum;
    }
    down(p);
    int res = 0;
    if (l <= mid) res += query(lc, l, r);
    if (r >= mid + 1) res += query(rc, l, r);
    up(p);
    return res;
}

signed main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> w[i];
    build(1, 1, n);
    while (q--) {
        int op, x, y, z;
        cin >> op;
        if (op == 1) {
            cin >> x >> y >> z;
            update(1, x, y, z);
        } else {
            cin >> x >> y;
            cout << query(1, x, y) << endl;
        }

    }
    return 0;
}
