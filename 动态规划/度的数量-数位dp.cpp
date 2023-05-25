#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 34;
int a[N];     //把B进制数的每一位抠出存入数组
int f[N][N];  //f[i][j]表示在i个位置上，放置j个1的组合数
int k, b;

void init() {
    for (int i = 0; i < N; i++) f[i][0] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
        }
    }
}

int dp(int n) {
    if (!n) return 0;
    int cnt = 0;
    while (n) a[++cnt] = n % b, n /= b;

    int res = 0, last = 0;   //last表示第i位之前放置1的个数
    for (int i = cnt; i >= 1; i--) {//从高位到低位枚举
        int now = a[i]; //当前的数字
        if (now >= 1) { //第i位==0时，直接跳过，继续枚举下一位
            res += f[i - 1][k - last]; //这一位放0
            if (now == 1) {  //第i位==1时，不能用组合数计算，继续枚举下一位
                last++;
                if (last > k) break;
            } else {
                if (k - last - 1 >= 0) res += f[i - 1][k - last - 1];
                break; //第i位放大于1的数，不合要求，则break
            }
        }
        if (i == 1 && last == k) res++;//特判，走到末位的情况
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
    cin >> l >> r >> k >> b;
    cout << dp(r) - dp(l - 1) << endl;
    return 0;
}