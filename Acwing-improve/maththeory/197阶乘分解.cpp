#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6 + 10;
int primes[N], cnt;
bool st[N];

void init(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] * i <= n; j++) {
            st[i * primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int main() {
    int n;
    cin >> n;
    init(n);
    for (int i = 0; i < cnt; i++) {
        int p = primes[i];
        int s = 0;
        for(int j=n;j;j/=p) s+=j/p;
        cout<<p<<" "<<s;
    }
    return 0;
}
