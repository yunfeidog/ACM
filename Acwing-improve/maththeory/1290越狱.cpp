#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int mod=1e5+3;
LL n,m;

LL qmi(int a,LL k){
    LL res=1;
    while (k){
        if (k&1) res=(LL)res*a%mod;
        a=(LL)a*a%mod;
        k>>=1;
    }
    return res;
}

int main() {
    cin>>m>>n;
    cout<<((qmi(m,n)-(LL)m*(qmi(m-1,n-1)))%mod+mod)%mod<<endl;

    return 0;
}
