#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

const int N=510,M=100010;
int n1,n2,m;
int h[N],e[M],ne[M],idx;
int match[N];
bool st[N];

void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int dfs(int x)
{
    for(int i=h[x];i;i=ne[i])
    {
        int j=e[i];
        if(!st[j])
        {
            st[j]=true;
            if(match[j]==0||dfs(match[j]))
            {
                match[j]=x;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    cin>>n1>>n2>>m;
    memset(h,-1,sizeof h);

    while(m--)
    {
        int a,b;
        cin>>a>>b;
        add(a,b);
    }
    int res=0;
    for(int i=1;i<=n1;i++)
    {
        memset(st,false,sizeof st);
        if(dfs(i)) res++;
    }
    cout<<res;
    return 0;
}
