#include <iostream>
#include <cstring>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<string, int> PSI;
const int N = 250;

const int INF=0x3f3f3f3f;


PSI a[N];
int g[N][N];
bool st[N];
int dist[N];

int n, k;

//prim算法求最小生成树
int prim()
{
    memset(dist,0x3f,sizeof dist);
    int res=0;
    for(int i=0;i<n;i++)
    {
        int t=-1;
        for(int j=1;j<=n;j++)
        {
            if(!st[j]&&(t==-1||dist[t]>dist[j])) t=j;//如果没有在树中，且到树的距离最短，则选择该点
        }
        if(i&&dist[t]==INF) return INF;//发现不连通，直接结束
        if(i) res+=dist[t];//res就是最小生成树的权重
        st[t]= true;
        for(int j=1;j<=n;j++) dist[j]=min(dist[j],g[t][j]);//更新生成树外的点到生成树的距离
    }
    return res;
}


int main() {
    //读取文件
    freopen("H:\\C++\\VsCode_cpp\\jiedan\\2022-12-9\\test42.in", "r", stdin);
    freopen("H:\\C++\\VsCode_cpp\\jiedan\\2022-12-9\\output.txt", "w", stdout);
    memset(g,0x3f,sizeof g);
    cin >> n >> k;//n个点，k条边
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;//下标
    }
    for (int i = 1; i <= k; i++) {
        string s1, s2;
        int x, y, w;
        cin >> s1 >> s2 >> w;
        for (int idx = 1; idx <= n; idx++) {

            if (a[idx].first == s1) {
                x = idx;//找到第一个点的下标
                break;
            }
        }
        for (int idx = 1; idx <= n; idx++) {
            if (a[idx].first == s2) {
                y = idx;//找到第二个点的下标
                break;
            }
        }
        //建立无向图，权重为w
        g[x][y] = w;
        g[y][x] = w;
    }
    //输出g
    cout << prim() << endl;
    return 0;
}
//5 7
//Alex Bertha Clara Daisy Emma
//Alex Bertha 5
//Alex Daisy 7
//Alex Emma 9
//Bertha Daisy 10
//Clara Bertha 11
//Clara Emma 3
//Emma Daisy 6