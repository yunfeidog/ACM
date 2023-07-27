#include <bits/stdc++.h>

using namespace std;

/**
 * 字符串字典树
 */
struct Trie {
    int son[100010][26], cnt[100010], idx;

    void insert(string s) {
        int x = 0;
        for (int i = 0; i < s.size(); i++) {
            int y = s[i] - 'a';
            if (!son[x][y]) son[x][y] = ++idx;
            x = son[x][y];
        }
        cnt[x]++;
    }

    int find(string s) {
        int x = 0;
        for (int i = 0; i < s.size(); i++) {
            int y = s[i] - 'a';
            if (!son[x][y]) return 0;
            x = son[x][y];
        }
        return cnt[x];
    }
};


/**
* 01字典树
*/
struct Trie2 {
    int son[100010][2], cnt[100010], idx;

    void insert(int t) {
        int x = 0;
        for (int i = 30; i >= 0; i--) {
            int y = t >> i & 1;
            if (!son[x][y]) son[x][y] = ++idx;
            x = son[x][y];
        }
        cnt[x]++;
    }

    int find(int t) {
        int x = 0;
        for (int i = 30; i >= 0; i--) {
            int y = t >> i & 1;
            if (!son[x][y]) return 0;
            x = son[x][y];
        }
        return cnt[x];
    }
};