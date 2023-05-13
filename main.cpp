#include <bits/stdc++.h>

#define int long long
using namespace std;


signed main() {
#ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    freopen("../test.out", "w", stdout);
#endif
    int L0, L1, L2, T, l0, l1, l2;
    cin >> L0 >> L1 >> L2 >> T >> l0 >> l1 >> l2;
    printf("Diff = %d, %d, %d\n", L0 - l0, L1 - l1, L2 - l2);
    int res = abs(L0 - l0) + abs(L1 - l1) + abs(L2 - l2);
    cout << (res <= T ? "Yes" : "No") << endl;
    return 0;
}