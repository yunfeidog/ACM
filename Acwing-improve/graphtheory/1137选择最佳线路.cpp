#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

const int N=1010,M=21010;
int n,m,T;
int h[N],e[M],ne[M],w[M],idx;
int dist[N],q[N];
bool st[N];

void add(int a,int b,int c)
{
    w[idx]=c,e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int spfa()
{
    memset(dist,0x3f,sizeof dist);
    dist[0]=0;
    int hh=0,tt=1;
    q[0]=0;
    while (hh!=tt)
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
                if(!st[i])
                {
                    q[++tt]=j;
                    if(tt==N)tt=0;
                    st[j]=true;
                }
            }
        }

    }
    if(dist[T]==0x3f3f3f3f) return -1;
    return dist[T];
    
}


int main()
{
    while(cin>>n>>m>>T)
    {
        memset(h,-1,sizeof h);
        while(m--)
        {
            int a,b,c;
            cin>>a>>b>>c;
            add(a,b,c);
        }
        int s;
        cin>>s;
        while(s--)
        {
            int ver;
            cin>>ver;
            add(0,ver,0);
        }
        cout<<spfa();
    }
    return 0;
}
