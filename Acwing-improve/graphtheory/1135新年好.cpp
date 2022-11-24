#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
#define sc scanf
#define pr printf

const int N=50010,M=200010,INF=0x3f3f3f3f;
int n,m;
int h[N],e[M],ne[M],w[M],idx;
int source[6],dist[6][N];
bool st[N];

void add(int a,int b,int c)
{
    w[idx]=c,e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dijkstra(int start,int dist[])
{
    memset(dist, 0x3f, N * 4);
    dist[start]=0;
    memset(st,0,sizeof st);
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,start});
    while (heap.size())
    {
        PII t=heap.top();heap.pop();
        int u=t.second,distance=t.first;
        if(st[u]) continue;
        st[u]=true;
        for(int i=h[u];~i;i=ne[i])
        {
            int j=e[i];
            if(dist[j]>dist[u]+w[i])
            {
                dist[j]=dist[u]+w[i];
                heap.push({dist[j],j});
            }
        }
    }
}

int dfs(int u,int start,int distance)
{
    if(u>5) return distance;
    int res=INF;
    for(int i=1;i<=5;i++)
    {
        if(!st[i])
        {
            int Next=source[i];
            st[i]=true;
            res=min(res,dfs(u+1,i,distance+dist[start][Next]));
            st[i]=false;
        }
    }
    return res;
}


int main()
{
    cin>>n>>m;
    source[0]=1;
    for(int i=1;i<=5;i++) cin>>source[i];

    memset(h,-1,sizeof h);
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c),add(b,a,c);
    }
    for(int i=0;i<6;i++) dijkstra(source[i],dist[i]);
    memset(st,0,sizeof st);
    cout<<dfs(1,0,0);
    return 0;
}
