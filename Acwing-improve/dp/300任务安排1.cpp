#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
typedef long long LL;

const int N=5010;
int t[N],c[N],n,s,f[N];
int main()
{
    memset(f,0x3f,sizeof f);
    f[0]=0;
    cin>>n>>s;
    for(int i=1;i<=n;i++) cin>>t[i]>>c[i];
    for(int i=1;i<=n;i++) t[i]+=t[i-1],c[i]+=c[i-1];

    for(int i=1;i<=n;i++)
        for(int j=0;j<i;j++)
            f[i]=min(f[i],f[j]+t[i]*(c[i]-c[j])+s*(c[n]-c[j]));
    cout<<f[n];
    return 0;
}
