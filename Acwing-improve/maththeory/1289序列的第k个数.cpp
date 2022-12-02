#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int mod=200907;

int a,b,c,k;
LL qmi(int a,int k)
{
    LL res=1;
    while (k)
    {
        if (k&1) res=(LL)res*a%mod;
        a=(LL) a*a%mod;
        k>>=1;
    }
    return res;
}

int main() {
    int t;
    cin>>t;
    while (t--)
    {
        cin>>a>>b>>c>>k;
        if (a+c==2*b) cout<<(a+(b-a)*(LL)(k-1))%mod<<endl;

        else cout << (LL)a * qmi(b / a, k - 1) % mod << endl;
    }

    return 0;
}
