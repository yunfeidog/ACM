#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

const int N=510,M=5210;
int n,m1,m2;
int h[N],e[M],ne[M],w[M],idx;
int dist[N];
bool st[N];
int q[N],cnt[N];

void add(int a,int b,int c)
{
    w[idx]=c,e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

bool spfa()
{
    memset(dist,0,sizeof dist);
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
            if(dist[j]>dist[t]+w[i])
            {
                dist[j]=dist[t]+w[i];
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
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m1>>m2;
        memset(h,-1,sizeof h);
        idx=0;
        while(m1--)
        {
            int a,b,c;
            cin>>a>>b>>c;
            add(a,b,c),add(b,a,c);
        }
        while(m2--)
        {
            int a,b,c;
            cin>>a>>b>>c;
            add(a,b,-c);
        }
        if(spfa()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
