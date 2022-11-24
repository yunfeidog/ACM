#include <iostream>
#include <cstring>
using namespace std;

const int N = 10010, INF = 0x3f3f3f3f;
int n;
int h[N], e[N * 2], w[N * 2], ne[N * 2], idx; //邻接表
int d1[N], d2[N];                             //向下走的最长路径和次长路径
int p1[N], up[N];

void add(int a, int b, int c) //邻接表存边
{
    e[++idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx;
}

int dfs_d(int u, int father)
{
    d1[u] = 0;                             //记录从u点向下走的最大长度
    d2[u] = 0;                             //记录u点向下走的次大长度
    for (int i = h[u]; i != -1; i = ne[i]) // i是边的编号
    {
        int j = e[i]; // j是u的邻接点
        if (j == father)
            continue;               //避免向上查找
        int d = dfs_d(j, u) + w[i]; //从u经j点往下走的最大长度
        if (d >= d1[u])
            d2[u] = d1[u], d1[u] = d, p1[u] = j; // p1[u]记录从u点向下走的最长路径是从哪个点下去的
        else if (d > d2[u])
            d2[u] = d;
    }
    return d1[u]; //返回从u点往下走的最大长度
}

void dfs_u(int u, int father)
{
    for (int i = h[u]; i != -1; i = ne[i]) // i是边的编号
    {
        int j = e[i]; // j是u的邻接点
        if (j == father)
            continue; //避免向上查找
        if (p1[u] == j)
            up[j] = max(up[u], d2[u]) + w[i]; // up[j]记录从j点向上走的最大长度
        else
            up[j] = max(up[u], d1[u]) + w[i];
        dfs_u(j, u); //深搜u的子节点j
    }
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    dfs_d(1, -1); //第一次深搜
    dfs_u(1, -1); //第二次深搜
    int res = INF;
    for (int i = 1; i <= n; i++)
        res = min(res, max(up[i], d1[i]));
    cout << res << endl;
    return 0;
}