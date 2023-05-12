#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 1e5 + 10;
int a[N];
int n = 1;

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    while (cin >> a[n])n++;
    n--;
    vector<int> f;
    f.push_back(a[n]);
    for (int i = n - 1; i >= 1; i--) {
        if (a[i] >= f.back()) f.push_back(a[i]);
        else {//找到第一个大于a[i]的数，换成a[i]
            *std::upper_bound(f.begin(), f.end(), a[i]) = a[i];
        }
    }
    cout << f.size() << endl;
    vector<int> g;
    g.push_back(a[1]);
    for (int i = 2; i <= n; i++) {
        if (a[i] > g.back())g.push_back(a[i]);
        else *std::lower_bound(g.begin(), g.end(), a[i]) = a[i];
    }
    cout << g.size() << endl;

    return 0;
}