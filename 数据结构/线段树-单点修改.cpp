/**
* https://www.luogu.com.cn/problem/P3374
*/
#include <bits/stdc++.h>

#define int long long
using namespace std;
#define  lc p<<1
#define  rc p<<1|1

const int N = 5e5 + 10;
int w[N], n, q;
struct Tree {
    int l, r, sum;
} tr[N * 4];

void up(int p) {
    tr[p].sum = tr[lc].sum + tr[rc].sum;
}

void build(int p, int l, int r) {
    tr[p] = {l, r, w[l]};
    if (l == r) return;
    int mid = (tr[p].l + tr[p].r) >> 1;
    build(lc, l, mid), build(rc, mid + 1, r);
    up(p);
}

void update(int p, int x, int k) {
    if (tr[p].l == x && tr[p].r == x) {
        tr[p].sum += k;
        return;
    }
    int mid = (tr[p].l + tr[p].r) >> 1;
    if (x <= mid) update(lc, x, k);
    else update(rc, x, k);
    up(p);
}

int query(int p, int l, int r) {
    if (l <= tr[p].l & tr[p].r <= r) {
        return tr[p].sum;
    }
    int mid = (tr[p].l + tr[p].r) >> 1;
    int res = 0;
    if (l <= mid) res += query(lc, l, r);
    if (r >= mid + 1) res += query(rc, l, r);
    return res;
}

signed main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> w[i];
    build(1, 1, n);
    while (q--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) update(1, x, y);
        else cout << query(1, x, y) << endl;
    }
    return 0;
}