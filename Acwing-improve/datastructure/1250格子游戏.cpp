#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N=40010;
int n,m;
int fa[N];

int find(int x)
{
    if (fa[x]!=x) fa[x]= find(fa[x]);
    return fa[x];
}

int get(int x,int y)
{
    return x*n+y;
}

int main() {
    cin>>n>>m;
    for(int i=0;i<n*n;i++) fa[i]=i;//初始化并查集

    char c;
    int x,y,a,b;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>c;
        x--,y--;
        a= get(x,y);
        if (c=='D') b= get(x+1,y);
        else b= get(x,y+1);
        if (find(a)== find(b))
        {
            cout<<i<<endl;
            return 0;
        }
        fa[find(a)]= find(b);
    }
    cout<<"draw"<<endl;
    return 0;
}
