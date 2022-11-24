#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

const int N=1e5+10;
int a[N];
int n,f;
double sum[N];

bool check(double avg)
{
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i]-avg;

    double minv=0;
    for(int i=0,j=f;j<=n;j++,i++)
    {
        minv=min(minv,sum[i]);
        if(sum[j]>=minv) return true;
    }
    return false;


}

int main()
{
    cin>>n>>f;
    for(int i=1;i<=n;i++) cin>>a[i];

    double l=0,r=2000;
    while(r-l>1e-5)
    {
        double mid=(l+r)/2;
        if(check(mid)) l=mid;
        else r=mid;
    }
    cout<<int(r*1000)<<endl;
    return 0;
}
