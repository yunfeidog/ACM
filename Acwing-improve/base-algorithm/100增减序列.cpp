#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int N = 100010;

int n;
int a[N], b[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) b[i] = a[i] - a[i - 1];
    LL p = 0, q = 0;
    for (int i = 2; i <= n; i++)
        if (b[i] > 0) p += b[i];
        else q -= b[i];
    cout << max(p, q) << endl;
    cout << abs(p - q) + 1 << endl;
    return 0;
}
