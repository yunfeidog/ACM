#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

const int N=150;
const double INF=1e20;

int n;
PII q[N];
char g[N][N];
double d[N][N],maxd[N];//maxd[i]表示和i所在连通分量的最长直径


double get_dist(PII a,PII b)
{
    double dx=a.x-b.x,dy=a.y-b.y;
    return sqrt(dx*dx+dy*dy);
}


int main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>q[i].x>>q[i].y;

    for(int i=0;i<n;i++) cin>>g[i];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(i!=j)
            {
                if(g[i][j]=='1') d[i][j]=get_dist(q[i],q[j]);
                else d[i][j]=INF;
            }


    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);

    double r1 = 0;
    for (int i = 0; i < n; i ++ )
    {
        for (int j = 0; j < n; j ++ )
            if (d[i][j] < INF / 2)
                maxd[i] = max(maxd[i], d[i][j]);
        r1 = max(r1, maxd[i]);
    }

    double r2 = INF;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            if (d[i][j] > INF / 2)
                r2 = min(r2, maxd[i] + maxd[j] + get_dist(q[i], q[j]));

    printf("%lf\n", max(r1, r2));
    return 0;
}
