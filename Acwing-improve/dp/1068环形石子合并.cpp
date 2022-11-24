#include <iostream>
#include <cstring>
using namespace std;

const int N = 410, INF = 0x3f3f3f3f;
int n;
int a[N]; //原数组
int s[N]; //前缀和
int f[N][N];
int g[N][N];

int main()
{
    memset(f, INF, sizeof f);
    memset(g, -INF, sizeof g);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i + n] = a[i]; //复制一遍区间
    }
    for (int i = 1; i <= 2 * n; i++)
    {
        s[i] = s[i - 1] + a[i];
        g[i][i] = 0, f[i][i] = 0;
    }
    //状态计算
    for (int len = 2; len <= n; len++) //枚举区间长度
    {
        for (int l = 1; l + len - 1 <= 2 * n; l++) //枚举区间的起点
        {
            int r = l + len - 1;        //区间的终点
            for (int k = l;k < r; k++) //决策：分割点
            {
                f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);
                g[l][r]=max(g[l][r],g[l][k]+g[k+1][r]+s[r]-s[l-1]);
            }
        }
    }

    //目标输出
    int minv=INF,maxv=-INF;
    for(int i=1;i<=n;i++)
    {
        minv=min(minv,f[i][i+n-1]);
        maxv=max(maxv,g[i][i+n-1]);
    }
    cout<<minv<<endl<<maxv<<endl;
    return 0;
}