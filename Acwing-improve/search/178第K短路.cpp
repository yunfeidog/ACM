#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<ctime>
#include<queue>

#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
#define sc scanf
#define pr printf

const int N=1010,M=200010;
int n,m,S,T,K;
int h[N],rh[N],e[M],w[M],ne[M],idx;
int dist[N],cnt[N];
bool st[N];//判断有没有出队

void add(int h[],int a,int b,int c)
{
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

void dijkstra()
{
    priority_queue<PII,vector<PII>,greater<PII>> heap;//优先队列
    heap.push({0,T});

    memset(dist,0x3f,sizeof dist);
    dist[T]=0;

    while(heap.size())
    {
        auto t=heap.top();heap.pop();
        int ver=t.y;
        if(st[ver]) continue;
        st[ver]=true;

        for(int i=rh[ver];~i;i=ne[i])
        {
            int j=e[i];
            if(dist[j]>dist[ver]+w[i])
            {
                dist[j]=dist[ver]+w[i];
                heap.push({dist[j],j});
            }
        }
    }
}


int astar()
{
    priority_queue<PIII, vector<PIII>, greater<PIII>> heap;
    // 谁的d[u]+f[u]更小 谁先出队列
    heap.push({dist[S], {0, S}});
    while(heap.size())
    {
        auto t = heap.top();
        heap.pop();
        int ver = t.y.y,distance = t.y.x;
        cnt[ver]++;
        //如果终点已经被访问过k次了 则此时的ver就是终点T 返回答案

        if(cnt[T]==K) return distance;

        for(int i=h[ver];i!=-1;i=ne[i])
        {
            int j = e[i];
            /* 
            如果走到一个中间点都cnt[j]>=K，则说明j已经出队k次了，且astar()并没有return distance,
            说明从j出发找不到第k短路(让终点出队k次)，
            即继续让j入队的话依然无解，
            那么就没必要让j继续入队了
            */
            if(cnt[j] < K)
            {
                // 按 真实值+估计值 = d[j]+f[j] = dist[S->t] + w[t->j] + dist[j->T] 堆排
                // 真实值 dist[S->t] = distance+w[i]
                heap.push({distance+w[i]+dist[j],{distance+w[i],j}});
            }
        }
    }
    // 终点没有被访问k次
    return -1;
}


int main()
{
    sc("%d%d",&n,&m);
    memset(h,-1,sizeof h);
    memset(rh,-1,sizeof rh);

    for(int i=0;i<m;i++)
    {
        int a,b,c;//起点，终点，边权
        sc("%d%d%d",&a,&b,&c);
        add(h,a,b,c);//正边
        add(rh,b,a,c);//反边
    }
    sc("%d%d%d",&S,&T,&K);
    if(S==T) K++;
    dijkstra();
    pr("%d\n",astar());
    return 0;
}
