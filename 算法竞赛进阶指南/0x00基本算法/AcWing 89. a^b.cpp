#include <bits/stdc++.h>

#define int long long
using namespace std;

int qmi(int x, int k, int p) {
    int res = 1;
    while (k) {
        if (k & 1) res = res * x % p;
        x = x * x % p;
        k >>= 1;
    }
    return res % p;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int a, b, p;
    cin >> a >> b >> p;
    cout << qmi(a, b, p) << endl;
    return 0;
}