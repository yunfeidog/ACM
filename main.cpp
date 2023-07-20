#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
typedef pair<int, int> PII;

void solve() {
    int n, m;
    cin >> n >> m;//number length
    vector<string> words(n + 1);
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        words[i] = s;
    }
    int q;
    cin >> q;
    map<int, map<int, int>> mp;
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (a > b)swap(a, b);
        if (mp[a][b] == 1)cout << "YES" << endl;
        else if (mp[a][b] == 2)cout << "NO" << endl;
        else {
            string s = words[a] + words[a];
            if (s.find(words[b]) != string::npos) {
                cout << "YES" << endl;
                mp[a][b] = 1;
            } else {
                cout << "NO" << endl;
                mp[a][b] = 2;
            }
        }
    }

}

signed main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}