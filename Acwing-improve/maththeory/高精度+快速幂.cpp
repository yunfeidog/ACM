#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
int p;
const int N=500;
vector<int> a(N),res(N);

vector<int> mul(vector<int> &a,vector<int> &b){
    vector<int> t(N*2);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            t[i+j]+=a[i]*b[j];
            t[i+j+1]+=t[i+j]/10;
            t[i+j]%=10;
        }
    return t;
}

void qmi(int p){
    res[0]=1,a[0]=2;
    while (p){
        if (p&1) res= mul(res,a);
        a= mul(a,a);
        p>>=1;
    }
    res[0]--;
}

int main() {
    cin>>p;
    cout<<int(p*log10(2))+1<<endl;
    qmi(p);
    for(int i=0,k=499;i<10;i++) {
        for (int j = 0; j < 50; j++, k--)
            cout << res[k];
        cout<<endl;
    }

    return 0;
}
