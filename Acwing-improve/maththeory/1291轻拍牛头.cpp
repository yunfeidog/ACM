#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N=1e6+10,M=1e5+10;
int cnt[N],a[M],res[N];
int n;

int main() {
    cin>>n;
    for (int i = 0; i < n; ++i){
        cin>>a[i];
        cnt[a[i]]++;
    }
    for(int i=1;i<N;i++){
        if (!cnt[i]) continue;
        for(int j=i;j<N;j+=i){
            res[j]+=cnt[i];
        }
    }
    for(int i=0;i<n;i++){
        cout<<res[a[i]]-1<<endl;
    }


    return 0;
}
