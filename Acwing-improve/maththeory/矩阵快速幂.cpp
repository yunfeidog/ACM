#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int mod=1e9+7;

struct matrix{
    LL c[101][101];
    matrix(){ memset(c,0,sizeof c);}
}A,res;
LL n,k;

matrix operator * (matrix &x,matrix &y){
    matrix t;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                t.c[i][j]=(t.c[i][j]+x.c[i][k]*y.c[k][j])%mod;
    return t;
}

void qmi(LL k)
{
    for(int i=1;i<=n;i++) res.c[i][i]=1;//单位矩阵
    while (k){
        if (k&1) res=res*A;
        A=A*A;
        k>>=1;
    }
}

int main() {
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>A.c[i][j];
    qmi(k);
    for(int i=1;i<=n;i++) {
        for (int j = 1; j <= n; j++)
            cout << res.c[i][j];
        cout<<endl;
    }
    return 0;
}
