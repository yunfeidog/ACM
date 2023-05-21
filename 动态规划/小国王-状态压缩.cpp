#include <bits/stdc++.h>

#define int long long
using namespace std;

int n, k;//棋盘行数，国王总数
int cnt = 0;//同一行的合法状态个数
int s[1 << 12];//同一行的合法状态集
int num[1 << 12];//每个合法状态包含的国王数
int f[12][144][1 << 12];//f[i,j,a]表示前i行放了j个国王，第i行第a个状态时的方案数

signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n >> k;

    //预处理
    for (int i = 0; i < (1 << n); i++)//枚举一行的所有状态
        if (!(i & i >> 1))//如果不存在相邻的1
        {
            s[cnt++] = i;//保存一行的合法状态
            for (int j = 0; j < n; j++)
                num[i] += (i >> j & 1);//统计每个合法状态包含的国王数(看里面有几个1)
        }

    f[0][0][0] = 1;//不放国王也是一种方案

    for (int i = 1; i <= n + 1; i++)//枚举行
        for (int j = 0; j <= k; j++)//枚举国王数
            for (int a = 0; a < cnt; a++)//枚举第i行的合法状态
                for (int b = 0; b < cnt; b++)//枚举第i-1行的合法状态
                {
                    int c = num[s[a]];//第i行第a个状态的国王数
                    //可以继续放国王，不存在同列的1，不存在斜对角的1
                    if ((j >= c) && !(s[b] & s[a]) && !(s[b] & s[a] << 1) && !(s[b] & (s[a] >> 1)))
                        f[i][j][a] += f[i - 1][j - c][b];//从第i-1行向第i行转移
                }
    cout << f[n + 1][k][0];

    return 0;
}