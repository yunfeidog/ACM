#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define sc scanf
#define pr printf

const int N = 2010;

int n, m;
int S, T;
double g[N][N];
double dist[N];
bool st[N];

void dijkstra()
{
	dist[S] = 1;
	for (int i = 1; i <= n; i++)
	{
		int u = i;
		for (int j = 1; j <= n; j++)
		{
			if (!st[j] &&dist[j] > dist[u])
				u = j;
		}
		st[u]=true;

		for(int j=1;j<=n;j++)
		{
			if(dist[j]<dist[u]*g[u][j])
				dist[j]=dist[u]*g[u][j];
		}
	}

}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		double z = (100.0 - c) / 100;
		g[a][b] = g[b][a] = max(g[a][b], z);
	}
	cin>>S>>T;
	dijkstra();
	printf("%.8lf", 100/dist[T]);
	return 0;
}
