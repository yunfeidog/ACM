#include <bits/stdc++.h>

using namespace std;

double e = 1e-6;

int main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n, f;
    cin >> n >> f;
    vector<double> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    double l = 1, r = 2000;
    auto check = [&](double res) -> bool {
        vector<double> s(n + 1);
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i] - res;
        double mi = 1e9;
        for (int i = f; i <= n; i++) {
            mi = min(mi, s[i - f]);
            if (s[i] - mi > 0) return true;
        }
        return false;
    };
    while (l + e < r) {
        double mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << int(r * 1000) << endl;

    return 0;
}