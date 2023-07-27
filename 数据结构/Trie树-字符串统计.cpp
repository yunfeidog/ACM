/**
 * https://www.acwing.com/problem/content/837/
 */
#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 1e5 + 10;
int son[N][26], cnt[N], idx;
// 下标0代表根节点和空节点，cnt用于计数，idx代表结点的索引

void insert(string s) {
    int x = 0;
    for (auto c: s) {
        int y = c - 'a';
        if (!son[x][y]) son[x][y] = ++idx;// 没有该子结点就创建一个
        x = son[x][y]; // 走到该子节点
    }
    ++cnt[x];// 标记该子节点存在的单词个数
}

int query(string s) {
    int x = 0;
    for (auto c: s) {
        int y = c - 'a';
        if (!son[x][y]) return 0;// 没有该子结点就返回查询不到
        x = son[x][y];
    }
    return cnt[x];
}


signed main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n;
    cin >> n;
    while (n--) {
        string op, s;
        cin >> op >> s;
        if (op == "I") insert(s);
        else cout << query(s) << endl;
    }


    return 0;
}