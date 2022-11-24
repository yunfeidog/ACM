#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
#define sc scanf
#define pr printf

const int N=510;
int m,n;
bool g[N][N];
int dist[N];
int stop[N];
int q[N];

void bfs()
{
    int hh=0,tt=0;
    memset(dist,0x3f,sizeof dist);
    q[0]=1,dist[1]=0;
    while(hh<=tt)
    {
        int t=q[hh++];
        for(int i=1;i<=n;i++)
        {
            if(g[t][i]&&dist[i]>dist[t]+1)
            {
                dist[i]=dist[t]+1;
                q[++tt]=1;
            }
        }
    }
}

int main()
{
    cin>>m>>n;
    string line;
    getline(cin,line);
    while (m--)
    {
        getline(cin,line);
        stringstream ssin(line);
        int cnt=0,p;
        while(ssin>>p) stop[cnt++]=p;
        for(int j=0;j<cnt;j++)
            for(int k=j+1;k<cnt;k++)
                g[stop[j]][stop[k]]=true;
    }
    bfs();
    if(dist[n]==0x3f3f3f3f) cout<<"NO";
    else cout<<dist[N]<<endl;
    return 0;
}
