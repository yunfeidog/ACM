#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

const int N=310,M=10010;
int n,m;
int p[N];
struct edge
{
    int a,b,w;

    bool operator <(const edge &W) const 
    {
        return w<W.w;
    }
}edges[M];

int find(int x)
{
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}


int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) p[i]=i;

    for(int i=0;i<m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        edges[i]={a,b,w};
    }
    sort(edges,edges+m);

    int res=0;
    for(int i=0;i<m;i++)
    {
        int a=find(edges[i].a),b=find(edges[i].b),w=edges[i].w;
        if(a!=b) 
        {
            p[a]=b;
            res=w;
        }
    }
    cout<<n-1<<" "<<res<<endl;
    return 0;
}
