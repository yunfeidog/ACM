#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int a[N];
int n, m;


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    if (m >= n - 1) {
        cout << "0";
        return 0;
    } else {
        sort(a, a + n);
        int i=0,j=n-1;
        while (m--){
            
        }
    }
}
