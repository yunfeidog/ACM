#include<bits/stdc++.h>
using namespace std;

const int N=510,M=10010;

struct Edge
{
	int a,b,w;
}e[M];//把每个边保存下来

int dist[N],backup[N];//备份数组防止串联
int n,m,k;

int bellman_ford()
{
	memset(dist,0x3f,sizeof dist);
	dist[1]=0;
	for(int i=0;i<k;i++)
	{
		memcpy(backup,dist,sizeof dist);
		for(int j=0;j<m;j++)
		{
			int a=e[j].a,b=e[j].b,w=e[j].w;
			dist[b]=min(dist[b],backup[a]+w); //使用backup:避免给a更新后立马更新b, 这样b一次性最短路径就多了两条边出来
		}
	}
	return dist[n];

}

typedef long long LL;

int main()
{
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		int a,b,w;
		cin>>a>>b>>w;
		e[i]={a,b,w};
	}
	int t=bellman_ford();
	if(dist[n]>0x3f3f3f3f/2) cout<<"impossible";
	else cout<<t;
	return 0;
}

