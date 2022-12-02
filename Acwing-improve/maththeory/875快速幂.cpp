#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
LL n,a,b,p;

int qmi(LL a,int b,int p){
    int res=1;
    while (b){
        if (b&1) res=res*a%p;
        a=a*a%p;
        b>>=1;
    }
    return res;
}

int main() {
    cin>>n;
    while (n--)
    {
        cin>>a>>b>>p;
        cout<<qmi(a,b,p)<<endl;
    }
    return 0;
}
