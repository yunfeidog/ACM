#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

const int N=200010;
int n,m;
int p[N];

struct edge
{
    int a,b,w;
    bool operator <(const edge &W) const 
    {
        return w<W.w;
    }
}edges[N];

int find(int x)
{
    if(p[x]!=x) return p[x]=find(p[x]);
    return p[x];
}


int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        edges[i]={a,b,w};
    }
    sort(edges,edges+m);
    for(int i=1;i<=n;i++) p[i]=i;//初始化并查集

    int res=0,cnt=0;
    for(int i=0;i<m;i++)
    {
        int a=edges[i].a,b=edges[i].b,w=edges[i].w;
        a=find(a),b=find(b);
        if(a!=b)
        {
            p[a]=b;
            res+=w;
            cnt++;
        }
    }
    if(cnt<n-1) cout<<"impossible";
    else cout<<res<<endl;
    return 0;
}
