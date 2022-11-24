#include<iostream>
#include<cstring>
using namespace std;

const int N=310;
int n;//石子堆数
int a[N];//记录每堆石子的质量
int s[N];//记录前缀和
int f[N][N];//f[l][r]表示把从l到r合并成一堆的最小代价

int main()
{
    memset(f,0x3f,sizeof f);
    cin>>n;
    //预处理
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];//前缀和
        f[i][i]=0;//合并每一堆石子的代价为0
    }

    for(int len=2;len<=n;len++)//枚举区间长度
    {
        for(int l=1;l+len-1<=n;l++)//枚举区间起点
        {
            int r=l+len-1;//区间终点
            for(int k=l;k<r;k++)//枚举分割点
            {
                f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);
            }
        }
    }
    cout<<f[1][n]<<endl;
    return 0;

}