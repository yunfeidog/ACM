#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

const int N=1010,M=5010;
int n,m;
int wf[N];
int h[N],e[M],ne[M],w[M],idx;
double dist[N];
int q[N],cnt[N];
bool st[N];

void add(int a,int b,int c)
{
    w[idx]=c,e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

bool check(double mid)
{
    memset(st,0,sizeof st);
    memset(cnt,0,sizeof cnt);
    int hh=0,tt=0;
    for(int i=1;i<=n;i++)
    {
        q[tt++]=i;
        st[i]=true;
    }
    while(hh!=tt)
    {
        int t=q[hh++];
        if(hh==N) hh=0;
        st[t]=false;

        for(int i=h[t];~i;i=ne[i])
        {
            int j=e[i];
            if(dist[j]<dist[t]+wf[t]-mid*w[i])
            {
                dist[j]=dist[t]+wf[t]-mid*w[i];
                cnt[j]=cnt[t]+1;
                if(cnt[j]>=n) return true;
                
                if(!st[j])
                {
                    q[tt++]=j;
                    if(tt==N) tt=0;
                    st[j]=true;
                }
            }
        }
    }
    return false;
}   

int main()
{   
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++) cin>>wf[i];
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }

    double l=0,r=1010;
    while(r-l>1e-4)
    {
        double mid=(l+r)/2;
        if(check(mid)) l=mid;
        else r=mid;
    }
    printf("%.2lf",l);
    return 0;

}
