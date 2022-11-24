#include <iostream>
using namespace std;

const int N = 34;
int a[N];    //把B进制数的每一位抠出来存入数组
int f[N][N]; // f[i][j]表示在i位置上，放置j个1的组合数
int K, B;
int x, y;
int res;

void init() //预处理出组合数
{
    for (int i = 0; i < N; i++)
        f[i][0] = 1;

    for (int i = 1; i < N; i++)
        for (int j = 1; j <= i; j++)
            f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
}

int dp(int n)
{
    if (!n)
        return 0; //特判，n==0就返回0
    int cnt = 0;
    while (n)
        a[++cnt] = n % B, n /= B; //把B进制数的每一位抠出存入数组
    int res = 0, last = 0;
    for (int i = cnt; i >= 1; i--)
    {
        int x = a[i]; //取出第i位数字
        if (x)        //第i位为0时直接跳过
        {
            res += f[i - 1][K - last]; //第i位放0
            if (x > 1)                 //第i位大于>1时
            {
                if (K - last - 1 >= 0)
                    res += f[i - 1][K - last - 1]; //第i位放1
                break;                             //第i位放大于1的数，不合要求，则break
            }
            else //第i位==1时，不能用组合数计算，继续枚举下一位
            {
                last++; //更新last
                if (last > K)
                    break; // 1的个数多于K，则break
            }
        }
        if (i == 1 && last == K)
            res++;
    }
    return res;
}

int main()
{
    int r;
    cin >> x >> y >> K >> B;
    init();
    cout<<dp(y)-dp(x-1)<<endl;
    return 0;
}