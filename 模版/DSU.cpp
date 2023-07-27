#include <bits/stdc++.h>

using namespace std;

/**
 * 并查集
 */
struct DSU {
    int p[100010];

    DSU(int n) {
        init(n);
    }

    void init(int n) {
        for (int i = 0; i < n; i++) p[i] = i;
    }

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    void merge(int x, int y) {
        p[find(x)] = find(y);
    }
};

/**
* 带权并查集
*/
struct DSU2 {
    int p[100010], d[100010];

    DSU2(int n) {
        init(n);
    }

    void init(int n) {
        for (int i = 0; i < n; i++) p[i] = i, d[i] = 0;
    }

    int find(int x) {
        if (p[x] != x) {
            int u = find(p[x]);
            d[x] += d[p[x]];
            p[x] = u;
        }
        return p[x];
    }

    void merge(int x, int y, int w) {
        int px = find(x), py = find(y);
        p[px] = py;
        d[px] = d[y] + w - d[x];
    }
};