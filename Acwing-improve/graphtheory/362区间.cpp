#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

const int N=50010,M=150010;
int n;
int h[N],e[M],ne[M],w[M],idx;
int dist[N];
int q[N];
bool st[N];

void add(int a,int b,int c)
{
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

void spfa()
{
    int hh=0,tt=1;
    memset(dist,-0x3f,sizeof dist);
    dist[0]=0,q[0]=0,st[0]=true;
    while(hh!=tt)
    {
        int t=q[hh++];
        if(hh==N) hh=0;
        st[t]=false;

        for(int i=h[t];~i;i=ne[i])
        {
            int j=e[i];
            if(dist[j]<dist[t]+w[i])
            {
                dist[j]=dist[t]+w[i];
                if(!st[j])
                {
                    q[tt++]=j;
                    if(tt==N) tt=0;
                    st[j]=true;
                }
            }
        }
    }
}


int main()
{
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=1;i<=50001;i++)
    {
        add(i-1,i,0);
        add(i,i-1,-1);
    }

    while(n--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        a++,b++;
        add(a-1,b,c);
    }
    spfa();
    cout<<dist[50001];
    return 0;
}
