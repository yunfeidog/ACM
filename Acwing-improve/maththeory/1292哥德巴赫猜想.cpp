#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N=1000010;
int primes[N],cnt;
bool st[N];

void init(int n)
{
    for(int i=2;i<=n;i++)
    {
        if (!st[i]) primes[cnt++]=i;
        for(int j=0;i*primes[j]<=n;j++)
        {
            st[i*primes[j]]= true;
            if (i%primes[j]==0) break;
        }
    }
}

int main() {
    init(N-1);
    int n;
    while (cin>>n,n)
    {
        for(int i=1;;i++)
        {
            int a=primes[i];
            int b=n-a;
            if (!st[b])
            {
                printf("%d = %d + %d \n",n,a,b);
                break;
            }
        }
    }
    return 0;
}
