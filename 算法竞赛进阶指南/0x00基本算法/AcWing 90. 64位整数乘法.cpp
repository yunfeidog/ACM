#include <bits/stdc++.h>

#define int long long
using namespace std;

int mul(int a, int b, int p) {
    int res = 0;
    while (b) {
        if (b & 1) res = (res + a) % p;
        a = (a + a) % p;
        b >>= 1;
    }
    return res;
}

int mul2(int a, int b, int p) {
    __int128 aa = a, bb = b, pp = p;
    __int128 res = aa * bb % pp;
    return (int) res;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int a, b, p;
    cin >> a >> b >> p;
    cout << mul2(a, b, p);

    return 0;
}