#include <iostream>
#include<cstring>
using namespace std;

const int N = 510;

int g[N][N]; //为稠密阵所以用邻接矩阵存储
bool st[N];//用于记录该点的最短距离是否已经确定
int dist[N]; //用于记录每一个点距离第一个点的距离
int n, m;

int Dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0; //第一个点到自身的距离为0
	for (int i = 0; i < n; ++i)
	{
		int u = i; //当前访问的点
		for (int j = 1; j <= n; j++) if (!st[j] && dist[j] < dist[u]) u = j; //寻找距离最小的点
		st[u] = true;
		//依次更新每个点所到相邻的点路径值
		for (int j = 1; j <= n; j++) dist[j] = min(dist[j], dist[u] + g[u][j]);
	}
	if (dist[n] == 0x3f3f3f3f) return -1; //不存在
	return dist[n];
}

int main()
{
	cin >> n >> m;
	memset(g, 0x3f, sizeof g);
	while (m--)
	{
		int x, y, z;
		cin >> x >> y >> z;
		g[x][y] = min(g[x][y], z); //如果发生重边的情况则保留最短的一条边
	}
	cout << Dijkstra() << endl;
	return 0;
}