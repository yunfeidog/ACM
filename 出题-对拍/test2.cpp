#include <bits/stdc++.h>

#define int long long
using namespace std;
typedef pair<int, int> PII;


signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("../test.out", "w", stdout);
#endif
    srand(time(0));
    //n为 3-90
    //m为 1-n^2
    int n = 3;
    int m = rand() % (n * n) + 1;
    cout << n << " " << m << endl;
    int cnt = 0;//已经放了多少个
    set<PII> s;//已经放的点的坐标

    while (1) {
        //随机生成三种情况
        int op = rand() % 3 + 1;
        int x = rand() % n + 1;
        int y = rand() % n + 1;
        if (op == 1) {
            //中间需要放置一个;
            if (s.count({x, y}))continue;
            s.insert({x, y});
            cnt++;
            cout << x << ";" << y << endl;
            if (cnt == m)break;
        } else if (op == 2) {
            //中间需要放置一个/
            if (s.count({x, y}))continue;
            s.insert({x, y});
            cnt++;
            cout << x << "/" << y << endl;
            if (cnt == m)break;
        } else {
            //中间什么都不要放
            if (s.count({x, y}))continue;
            s.insert({x, y});
            cnt++;
            cout << x;
            //如果y的长度为1,那就输出一个0再输出y
            if (y < 10)cout << "0";
            cout << y << endl;
            if (cnt == m)break;
        }
    }
    return 0;
}