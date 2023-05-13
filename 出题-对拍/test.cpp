#include <bits/stdc++.h>

#define int long long
using namespace std;
int n, m;
const int N = 100;
char g[N][N];

void solve(string a, string b) {
    int x = stoi(a);
    int y = stoi(b);
    g[n - y + 1][x] = '#';
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n >> m;
    int q = m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            g[i][j] = '.';


    while (q--) {
        string s;
        cin >> s;
        int pos;
        if (s.find(';') != string::npos) {
            pos = s.find(';');
            solve(s.substr(0, pos), s.substr(pos + 1));
        } else if (s.find('/') != string::npos) {
            pos = s.find('/');
            solve(s.substr(0, pos), s.substr(pos + 1));
        } else {
            while (s.size() < 4)s = "0" + s;
            solve(s.substr(0, 2), s.substr(2));
        }
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << g[i][j];
        }
        cout << endl;
    }
    return 0;
}