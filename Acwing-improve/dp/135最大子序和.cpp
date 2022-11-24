#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 3e5 + 10;
int a[N];
int n, m;
int q[N];
int ans;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] += a[i - 1];

    int hh = 0, tt = 0;
    q[0] = 0, ans=a[1];
    for(int i=1;i<=n;i++)
    {
        if(hh<=tt && q[hh]<i-m) hh++;//q[h]不在窗口[i-m,i-1]内，队头出列
        ans=max(ans,a[i]-a[q[hh]]);//使用队头的最小值更新答案
        while(hh<=tt && a[i]<=a[q[tt]]) tt--;//当前值<=队尾值，让队尾出队，保证这个窗口是单调递增的
        q[++tt]=i;//把下标入队，便于队头出列
    }
    cout<<ans<<endl;
    return 0;
}
