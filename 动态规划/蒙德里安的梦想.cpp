#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 12, M = 1 << 12;
int st[M];
int f[N][M];


signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n, m;
    while (cin >> n >> m && (n || m)) {

        for (int i = 0; i < 1 << n; i++) {
            int cnt = 0;
            st[i] = true;
            for (int j = 0; j < n; j++)
                if (i >> j & 1) {
                    if (cnt & 1) {
                        st[i] = false; // cnt 为当前已经存在多少个连续的0
                        break;
                    }
                } else cnt++;
            if (cnt & 1) st[i] = false; // 扫完后要判断一下最后一段有多少个连续的0
        }

        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for (int i = 1; i <= m; i++)//枚举列
            for (int j = 0; j < 1 << n; j++)//枚举第i列第状态
                for (int k = 0; k < 1 << n; k++)//枚举第i-1列的状态
                    //两列状态兼容：	不出现重叠1，不出现
                    if ((j & k) == 0 && (st[j | k]))
                        // j & k == 0 表示 i 列和 i - 1列同一行不同时捅出来
                        // st[j | k] == 1 表示 在 i 列状态 j， i - 1 列状态 k 的情况下是合法的.
                        f[i][j] += f[i - 1][k];
        cout << f[m][0] << endl;
    }


    return 0;
}