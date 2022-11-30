#include <bits/stdc++.h>

using namespace std;

const int N = 10010, M = 50010;
int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int id[N], scc_cnt, _size[N];
int dout[N];//记录每个连通分量的出度

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u) {
    dfn[u] = low[u] = ++timestamp;
    stk[++top] = u, in_stk[u] = true;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (!dfn[j]) {
            tarjan(j);
            low[u] = min(low[u], low[j]);
        } else if (in_stk[j]) {
            low[u]=min(low[u],dfn[j]);
        }
    }
    if (dfn[u]==low[u])
    {
        ++scc_cnt;
        int y;
        do {
            y=stk[top--];
            in_stk[y]=false;
            id[y]=scc_cnt;//y元素所属的连通块编号
            _size[scc_cnt]++;//该连通块内包含的点数
        } while (y!=u);
    }
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    for (int i = 1; i <= n; ++i) {
        if (!dfn[i])
            tarjan(i);
    }

    // 统计在新图中所有点的出度
    for(int i=1;i<=n;i++){
        for(int j=h[i];~j;j=ne[j]){
            int k=e[j];
            int a=id[i],b=id[k];//a表示i所在连通分量的编号,b表示k所在连通分量的编号
            if (a!=b){ //如果点i和点k不在同一个连通块
                dout[a]++; // 从a走到b，a的出度++
            }
        }
    }
    // zeros是统计在新图中，出度为0的点的个数
    // sum表示满足条件的点（最受欢迎的奶牛）的个数
    int zeros=0,sum=0;
    for(int i=1;i<=scc_cnt;i++){
        if (!dout[i]){
            zeros++;
            sum+= _size[i];
            if (zeros>1){
                sum=0;
                break;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
