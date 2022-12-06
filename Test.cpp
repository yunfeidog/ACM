#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#pragma GCC optimize(2)
#define x first
#define y second
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'

using namespace std;

typedef long long LL;

const int N = 4e5 + 10;

int h[N], e[N], ne[N], idx;
bool st[N];
int res = -0x3f3f3f3f;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u, int father)
{
    int res;
    if (st[u])
        res = 1;
    else
        res = 0;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == father)
            continue;
        res += dfs(j, u);
    }
    return res;
}

int main()
{
    IOS;
    int n;
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        st[x] = true;
    }
    for (int i = h[1]; ~i; i = ne[i])
    {
        int j = e[i];
        res = max(dfs(j, 1), res);
    }
    cout << res << endl;
    return 0;
}