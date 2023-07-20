#include <bits/stdc++.h>

#define int long long
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define IOS cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);
#define cxk 1
#define debug(s, x) if (cxk) cout << "#debug:(" << s << ")=" << x << endl;
using namespace std;

void solve() {
    string s;
    cin >> s;
    int res = 0;
    int n = s.size();
    s = " " + s;
    for (int i = 1; i <= n; i++) {
        int j = i + 1;
        while (j <= n && s[j] == s[i]) j++;
        res += (j - i - 1);
        i = j - 1;
    }
    cout << res << endl;

}

signed main() {
    IOS
#ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    freopen("../test.out", "w", stdout);
#endif
    int _ = 1;
    cin >> _;
    while (_--) solve();
    return 0;
}