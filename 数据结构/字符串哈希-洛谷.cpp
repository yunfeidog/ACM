#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

const int P = 13331, N = 1010;

ull f(string s) {
    s = " " + s;
    ull res = 0;
    for (int i = 1; i <= s.size() - 1; i++) {
        res = res * P + s[i];
    }
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<ull> a;
    while (n--) {
        string s;
        cin >> s;
        a.push_back(f(s));
    }
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
    cout << a.size() << endl;


    return 0;
}