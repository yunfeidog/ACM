#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

LL x,y,ans;
LL gcd(LL a,LL b){
    return b? gcd(b,a%b):a;
}

int main() {
    cin>>x>>y;
    LL t=x*y;
    for(LL i=0;i<=t/i;i++)
        if (t%i==0&& gcd(i,t/i)==x)
            ans+=2;
    if (x==y) ans--;
    cout<<ans;
    return 0;
}
