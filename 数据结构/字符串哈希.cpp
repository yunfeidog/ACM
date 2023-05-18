#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
const int P = 13331;
const int N = 1e5 + 10;
ull p[N], h[N];

ull get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    s = " " + s;
    p[0] = 1, h[0] = 0;
    for (int i = 1; i <= n; i++) {
        h[i] = h[i - 1] * P + s[i];
        p[i] = p[i - 1] * P;
    }
    while (m--) {
        int l1, l2, l3, l4;
        cin >> l1 >> l2 >> l3 >> l4;
        cout<<(get(l1,l2)==get(l3,l4)?"Yes":"No")<<endl;
    }
    return 0;
}