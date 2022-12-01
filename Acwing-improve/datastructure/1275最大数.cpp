#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N=2e5+10;

struct Node{
    int l,r;
    int v;//最大值
}tr[N*4];
int m,p;

void build(int u,int l,int r)
{
    tr[u]={l,r};
    if (l==r)return;
    int mid=l+r>>1;
    build(u<<1,l,mid), build(u<<1|1,mid+1,r);
}

//查询以u为根节点，区间[l,r]中的最大值
int query(int u,int l,int r){
    if (tr[u].l>=l&tr[u].r<=r) return tr[u].v;//区间包含在[l,r]之中
    int mid=tr[u].l+tr[u].r>>1;
    int v=0;
    if (l<=mid) v= query(u<<1,l,r);
    if  (r>mid) v=max(v, query(u<<1|1,l,r));
    return v;
}

//更新该结点的区间最大值
void modify(int u,int x,int v){
    if (tr[u].l==tr[u].r) tr[u].v=v;
    else{
        int mid=tr[u].l+tr[u].r>>1;
        if (x<=mid) modify(u<<1,x,v);
        else modify(u<<1|1,x,v);
        tr[u].v= max(tr[u<<1].v,tr[u<<1|1].v);
    }
}

int main() {
    int n=0,last=0;
    cin>>m>>p;
    build(1,1,m);
    while (m--){
        char op;
        cin>>op;
        if (op=='A')
        {
            int t;
            cin>>t;
            //在n+1处插入
            modify(1,n+1,((LL) t+last)%p);
            n++;
        }else{
            int L;
            cin>>L;
            last= query(1,n-L+1,n);//查询[n - L + 1, n]内的最大值，u = 1，即从根节点开始查询
            cout<<last<<endl;
        }
    }
    return 0;
}
