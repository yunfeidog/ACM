#include <iostream>
using namespace std;

const int N = 210;
int n;
int a[N];    // a[i]表示第i颗珠子的头标记
int f[N][N]; // f[l,r]表示合并[l,r]得到的能量的最大值

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i + n] = a[i]; //复制一遍区间
    }

    //状态计算
    for (int len = 3; len <= n + 1; len++) //阶段
    {
        for (int l = 1; l + len - 1 <= 2 * n; l++) //枚举起点 l+len-1为区间终点
        {
            int r = l + len - 1;
            for (int k = l + 1; k < r; k++)
                f[l][r] = max(f[l][r], f[l][k] + f[k][r] + a[l] * a[k] * a[r]);
        }
    }
    //目标输入
    int res = 0;
    for (int i = 0; i <= n; i++)
        res = max(res, f[i][i + n]);
    cout << res << endl;
    return 0;
}