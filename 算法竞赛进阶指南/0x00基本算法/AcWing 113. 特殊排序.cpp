#include <bits/stdc++.h>

using namespace std;

bool compare(int a, int b) {
    return false;
}
//上次为了防止编辑器报错
// Forward declaration of compare API.
// bool compare(int a, int b);
// return bool means whether a is less than b.

class Solution {
public:
    vector<int> specialSort(int N) {
        vector<int> res;
        res.push_back(1);
        for (int i = 2; i <= N; i++) {
            int l = 0, r = res.size();
            while (l < r) { //>i的最小位置
                int mid = (l + r) >> 1;
                if (compare(i, res[mid])) r = mid;
                else l = mid + 1;
            }
            res.insert(res.begin() + l, i);
        }
        return res;

    }
};