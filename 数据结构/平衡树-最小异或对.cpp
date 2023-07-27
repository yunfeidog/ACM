/**
 * https://ac.nowcoder.com/acm/contest/53485/F
 */
#include <bits/stdc++.h>

#define int long long
using namespace std;

multiset<int> s, res;
int n, x;
string op;

void add() {
    auto it = s.lower_bound(x);
    if (it != s.end()) res.insert(x ^ *it);
    if (it != s.begin()) res.insert(x ^ *prev(it));
    if (it != s.end() && it != s.begin()) res.erase(res.lower_bound(*it ^ *prev(it)));
    s.insert(x);
}

void del() {
    s.erase(s.find(x));
    auto it = s.lower_bound(x);
    if (it != s.end()) res.erase(res.find(x ^ *it));
    if (it != s.begin()) res.erase(res.find(x ^ *prev(it)));
    if (it != s.end() && it != s.begin()) res.insert(*it ^ *prev(it));
}

int que() {
    return *res.begin();
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n;
    while (n--) {
        cin >> op;
        if (op == "ADD") {
            cin >> x;
            add();
        } else if (op == "DEL") {
            cin >> x;
            del();
        } else cout << que() << endl;
    }

    return 0;
}