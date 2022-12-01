#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N=200010;

int n;
int a[N];
int tr[N];//tr[i]表示树状数组i结点覆盖的范围和
int Greater[N],lower[N];//Lower[i]表示左边比第i个位置小的数的个数
int lowbit(int x){return x&-x;}

//将序列中第x个数加上k。
void add(int x,int c){
    for(int i=x;i<=n;i+= lowbit(i)){
        tr[i]+=c;
    }
}
//查询序列前x个数的和
int sum(int x){
    int res=0;
    for(int i=x;i;i-= lowbit(i)){
        res+=tr[i];
    }
    return res;
}

int main() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n;i++)
    {
        int y=a[i];
        Greater[i]= sum(n)- sum(y);
        lower[i]= sum(y-1);
        add(y,1);//将y加入树状数组，即数字y出现1次
    }
    memset(tr,0,sizeof tr);
    LL res1=0,res2=0;
    for(int i=n;i;i--){
        int y=a[i];
        res1+=Greater[i]*(LL)(sum(n)- sum(y));
        res2+=lower[i]*(LL)(sum(y-1));
        add(y,1);
    }
    cout<<res1<<" "<<res2<<endl;
    return 0;
}
