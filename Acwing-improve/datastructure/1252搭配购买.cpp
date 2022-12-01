#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N=10010;
int n,m,vol;
int v[N],w[N];
int p[N];
int f[N];

int find(int x)
{
    if (p[x]!=x) p[x]= find(p[x]);
    return p[x];
}

int main() {
    cin>>n>>m>>vol;
    for(int i=1;i<=n;i++) p[i]=i;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
    while (m--)
    {
        int a,b;
        cin>>a>>b;
        int pa= find(a),pb= find(b);
        if (pa!=pb)//不在一个集合中,就合并价值和体积
        {
            v[pa]+=v[pb];
            w[pa]+=w[pb];
            p[pb]=pa;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if (p[i]==i)
            for(int j=vol;j>=v[i];j--)
            {
                f[j]= max(f[j],f[j-v[i]]+w[i]);
            }
    }
    cout<<f[vol]<<endl;
    return 0;
}
