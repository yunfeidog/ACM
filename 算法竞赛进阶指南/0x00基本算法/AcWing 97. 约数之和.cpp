#include <bits/stdc++.h>

#define int long long
using namespace std;
int a, b;
map<int, int> factor;

const int mod = 9901;

int qmi(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res % mod;
}

int sum(int p, int n) {
    if (n == 0) return 1;
    if (n & 1) {
        int x = sum(p, (n - 1) / 2) % mod;
        int y = (1 + qmi(p, (n + 1) / 2)) % mod;
        return x * y % mod;
    } else {
        int x = sum(p, n / 2 - 1) % mod;
        int y = (1 + qmi(p, n / 2)) % mod;
        int z = qmi(p, n) % mod;
        return (x * y + z) % mod;
    }
}


signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> a >> b;
    //分解质因数
    for (int i = 2; i <= a / i; i++) {
        if (a % i == 0) {
            int s = 0;
            while (a % i == 0) {
                a /= i;
                s++;
            }
            factor[i] = s;
        }
    }
    if (a > 1) factor[a]++;
    int res = 1;
    for (auto [x, y]: factor) {
        res = res * sum(x, b * y) % mod;
    }
    if (a == 0) res = 0;
    cout << res % mod << endl;


    return 0;
}