#include <iostream>
#include <cstring>
using namespace std;

const int N = 10010, M = N * 2;
int n, ans;                       // ans表示最长路径的长度
bool st[N];                       //标记是否被搜过
int h[N], e[M], w[M], ne[M], idx; //邻接表

void add(int a, int b, int c) //邻接表存边
{
    e[++idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx;
}

int dfs(int u)
{
    st[u] = 1;                             //标记u这个点已经被搜过了
    int d1=0;                                // d1记录从u点往下走的最大长度
    int d2=0;                                // d2记录从u点往下走的次大长度
    for (int i = h[u]; i != -1; i = ne[i]) // i是边的编号
    {
        int j = e[i]; // j是u的邻接点
        if (st[j])
            continue;
        int d = dfs(j) + w[i]; //从u经过j点往下走的最大长度
        if (d > d1)
            d2 = d1, d1 = d; //更新d2和d1
        else if (d > d2)
            d2 = d; //更新d2
    }
    ans = max(ans, d1 + d2); //更新答案
    return d1;               //返回从u往下走的最大长度
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
    dfs(1);
    cout << ans << endl;
    return 0;
}