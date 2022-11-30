#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N=10010,M=30010;
int n,m;
int h[N],e[M],ne[M],idx;
int dfn[N],low[N],timestamp;
int root;//每个连通块的根节点
int ans;//记录每个连通块去掉一个点形成的连通块数目的最大值


void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void tarjan(int u)
{
    dfn[u]=low[u]=++timestamp;
    int s=0;//如果当前点u是割点的话，去掉该点u得到的连通分量的个数
    for(int i=h[u];~i;i=ne[i])
    {
        int j=e[i];
        if (!dfn[j]){
            tarjan(j);
            low[u]= min(low[u],low[j]);
            if (dfn[u]<=low[j]) s++;// 说明u是可能是割点, u存在一棵子树(删除割点u)
        }else low[u]= min(low[u],dfn[j]);
    }
    if (u!=root) s++;//如果不是根节点最后还要加上父节点部分1
    ans= max(ans,s);
}

int main() {
    while (cin>>n>>m,n||m)
    {
        memset(dfn,0,sizeof dfn);
        memset(h,-1,sizeof h);
        idx=timestamp=0;
        while (m--)
        {
            int a,b;
            cin>>a>>b;
            add(a,b), add(b,a);
        }
        ans=0; //记录删除不同割点之后形成的连通块的最大值
        int cnt=0; // 记录连通块的数目
        for(root=0;root<n;root++) //每次将其中联通块遍历，用tarjan
            if (!dfn[root]){
                cnt++;
                tarjan(root);
            }
        cout<<cnt+ans-1<<endl;
    }
    return 0;
}
