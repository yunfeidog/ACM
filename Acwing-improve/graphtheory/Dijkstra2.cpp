#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int,int> PII;

const int N=150010;

int h[N],e[N],ne[N],idx;//邻接表
int w[N];//权重
int dist[N];
bool st[N];
int n,m;

void add(int a,int b,int c)
{
	w[idx]=c,e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int Dijkstra()
{
	memset(dist,0x3f,sizeof dist);
	dist[1]=0;
	priority_queue<PII,vector<PII>,greater<PII>> heap;//定义一个小根堆

	heap.push({0,1});//pair排序时先根据first(距离)，再根据second。
	while(heap.size())
	{
		PII t=heap.top();heap.pop();//取出距离最近的点
		int u=t.second,distance=t.first;//当前点的信息
		if(st[u]) continue;//再出队，跳过
		st[u]=1;
		for(int i=h[u];~i;i=ne[i])
		{
			int j=e[i];
			if(dist[j]>distance+w[i])
			{
				dist[j]=distance+w[i];
				heap.push({dist[j],j});
			}

		}
	}

	if(dist[n]==0x3f3f3f3f) return -1;
	else return dist[n];
}

int main()
{
	memset(h,-1,sizeof h);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
	}
	cout<<Dijkstra();
	return 0;

}