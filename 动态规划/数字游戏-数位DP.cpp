#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 12;
int a[N];
int f[N][N];

void init() {
    for (int i = 0; i <= 9; i++) f[1][i] = 1;
    for (int i = 2; i < N; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = j; k <= 9; k++) {
                f[i][j] += f[i - 1][k];
            }
        }
    }
}

int dp(int n) {
    if (!n) return 1;
    int cnt = 0;
    while (n) a[++cnt] = n % 10, n /= 10;

    int res = 0, last = 0;
    for (int i = cnt; i >= 1; i--) {
        int now = a[i];
        for (int j = last; j < now; j++) {
            res += f[i][j];
        }
        if (now < last) break;
        last = now;
        if (i == 1) res++;
    }
    return res;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    init();
    int l,r;
    while (cin>>l>>r){
        cout<<dp(r)- dp(l-1)<<endl;
    }


    return 0;
}