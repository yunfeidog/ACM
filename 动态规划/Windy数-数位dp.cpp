#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 12;
int a[N];     //把整数的每一位数字抠出来，存入数组
int f[N][10]; //f[i][j]表示一共有i位，且最高位数字为j的Windy数的个数

void init() {
    for (int i = 0; i <= 9; i++) f[1][i] = 1;
    for (int i = 2; i < N; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                if (abs(j - k) >= 2) f[i][j] += f[i - 1][k];
            }
        }
    }
}

int dp(int n) {
    if (!n) return 0;
    int cnt = 0;
    while (n) a[++cnt] = n % 10, n /= 10;
    int res = 0, last = -2;
    for (int i = cnt; i >= 1; i--) { //答案为cnt位的
        int now = a[i];
        for (int j = (i == cnt); j < now; j++) {//最高位从1开始
            if (abs(j - last) >= 2) {
                res += f[i][j];
            }
        }
        if (abs(now - last) < 2) break;
        last = now;
        if (i == 1) res++;
    }
    for (int i = 1; i < cnt; i++) { //答案小于cnt位的
        for (int j = 1; j <= 9; j++) {
            res += f[i][j];
        }
    }
    return res;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    init();
    int l, r;
    cin >> l >> r;
    cout << dp(r) - dp(l - 1);
    return 0;
}