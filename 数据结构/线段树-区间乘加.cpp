/**
* https://www.luogu.com.cn/problem/P3373
*/
#include <bits/stdc++.h>

#define int long long
using namespace std;

#define lc p<<1
#define rc p<<1|1
#define mid ((tr[p].l+tr[p].r)>>1)

const int N = 1e5 + 10;
int w[N], n, mod, q;
struct Tree {
    int l, r, sum, add, mul;
} tr[N * 4];

void cal(Tree &t, int m, int a) {
    t.sum = (t.sum * m + (t.r - t.l + 1) * a) % mod;
    t.mul = (t.mul * m) % mod;
    t.add = (t.add + a) % mod;
}

void up(int p) {
    tr[p].sum = (tr[lc].sum + tr[rc].sum) % mod;

}

void down(int p) {
    cal(tr[lc], tr[lc].mul, tr[lc].add);
    cal(tr[rc], tr[rc].mul, tr[rc].add);
    tr[p].add = 0;
    tr[p].mul = 1;
}

void build(int p, int l, int r) {
    tr[p] = {l, r, w[l], 0, 1};
    if (l == r) return;
    build(lc, l, mid), build(rc, mid + 1, r);
    up(p);
}

void update(int p, int l, int r, int mul, int add) {
    if (l <= tr[p].l && tr[p].r <= r) {
        cal(tr[p], mul, add);
        return;
    }
    if (l > tr[p].r || r < tr[p].l) return;
    down(p);
    update(lc, l, r, mul, add);
    update(rc, l, r, mul, add);
    up(p);
}

int query(int p, int l, int r) {
    if (l <= tr[p].l && tr[p].r <= r) {
        return tr[p].sum;
    }
    if (l > tr[p].r || tr[p].l > r) return 0;
    down(p);
    return query(lc, l, r) + query(rc, l, r);

}

signed main() {

    return 0;
}