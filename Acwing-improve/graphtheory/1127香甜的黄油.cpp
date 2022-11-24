#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;

typedef long long LL;

const int N=810,M=3000,INF=0x3f3f3f3f;

int n,m,c;
int h[N],e[M],ne[M],w[M],idx;
int id[N];
int dist[N];
bool st[N];
int res[N];

void add(int a,int b,int c)
{
	w[idx]=c,e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dijkstra(int start)
{
	memset(dist,0x3f,sizeof dist);
	memset(st,0,sizeof st);

	priority_queue<PII,vector<PII>,greater<PII>> heap;
	dist[start]=0;
	heap.push({0,start});

	while(heap.size())
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

	for(int i=1;i<=n;i++)
	{
		if(dist[i]==INF) res[i]=INF;
		else res[i]+=dist[i];
	}

}


int main()
{
	cin>>c>>n>>m;
	memset(h,-1,sizeof h);
	for(int i=0;i<c;i++)
	{
		cin>>id[i];
	}	
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c),add(b,a,c);
	}
	for(int i=0;i<n;i++) dijkstra(id[i]);

	int ans=INF;
	for(int i=1;i<=n;i++)
	{
		ans=min(ans,res[i]);
	}
	cout<<ans<<endl;
	return 0;
}

