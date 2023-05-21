#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mod = 1e9;
int n, m;//玉米田的行数、列数
int g[14];//各行的状态值
int cnt;//同一行的合法状态个数
int s[1 << 14];//一行的合法状态集
int f[14][1 << 14];//f[i,a]表示已经种植前i行，第i行第a各状态时的方案数

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n >> m;
    //预处理
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x;
            cin >> x;
            g[i] = (g[i] << 1) + x;//保存各行的状态值
        }
    }

    for (int i = 0; i < 1 << m; i++)//枚举一行所有状态
        if (!(i & i >> 1))//如果不存在相邻的1
            s[cnt++] = i;

    f[0][0] = 1;//什么都不种植也是一种方案；
    for (int i = 1; i <= n + 1; i++)//枚举行
        for (int a = 0; a < cnt; a++)//枚举第i行的合法状态
            for (int b = 0; b < cnt; b++) //枚举第i-1行合法状态
            {
                //a种植在肥沃的土地上；a,b同列不同时为1
                if ((s[a] & g[i]) == s[a] && !(s[a] & s[b]))
                    f[i][a] = (f[i][a] + f[i - 1][b]) % mod;
            }
    cout << f[n + 1][0];

    return 0;
}