#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N=200010;
int n,m;
int p[N];
unordered_map<int ,int >S;

struct Query
{
    int x,y,e;
}query[N];

int get(int x)
{
    if (S.count(x)==0) S[x]=++n;
    return S[x];
}
int find(int x)
{
    if (p[x]!=x) p[x]= find(p[x]);
    return p[x];
}

int main() {
    int t;
    cin>>t;
    while (t--)
    {
        n=0;
        S.clear();
        cin>>m;
        for(int i=0;i<m;i++)
        {
            int x,y,e;
            cin>>x>>y>>e;
            query[i]={get(x), get(y),e};
        }

        for(int i=1;i<=n;i++) p[i]=i;

        //合并相等的条件
        for(int i=0;i<m;i++)
            if (query[i].e==1)
            {
                int pa= find(query[i].x),pb= find(query[i].y);
                p[pa]=pb;
            }
        //检查不相等条件
        bool has_conflict=false;
        for(int i=0;i<m;i++)
        {
            if (query[i].e==0)
            {
                int pa= find(query[i].x),pb= find(query[i].y);
                if (pa==pb)
                {
                    has_conflict=true;
                    break;
                }
            }
        }
        if (has_conflict) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}
