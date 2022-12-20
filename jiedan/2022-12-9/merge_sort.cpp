#include <iostream>

#define endl '\n'

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6 + 10;
PII a[N], tmp[N];

// 归并排序,,第一个关键词相同时，不改变出现的先后顺序
void merge_sort(int l, int r) {
    if (l >= r) return;//递归边界
    int mid = l + r >> 1;//中间位置
    merge_sort(l, mid), merge_sort(mid + 1, r);//递归左右两边排好序
    int i = l, j = mid + 1, k = 0;//i,j分别指向左右两边的起始位置，k指向临时数组的起始位置
    while (i <= mid && j <= r) {
        if (a[i].first <= a[j].first) tmp[k++] = a[i++];//左边的数小于右边的数，将左边的数放入临时数组
        else tmp[k++] = a[j++];//反之，将右边的数放入临时数组
    }
    while (i <= mid) tmp[k ++] = a[i ++];//将左边剩余的数放入临时数组
    while (j <= r) tmp[k ++] = a[j ++];//将右边剩余的数放入临时数组
    for (int i = l, j = 0; i <= r; i ++, j ++) a[i] = tmp[j];//将临时数组的数放回原数组
}

int main() {

    int t;
    //读取文件
    freopen("H:\\C++\\VsCode_cpp\\jiedan\\2022-12-9\\t10.in.txt", "r", stdin);
    freopen("H:\\C++\\VsCode_cpp\\jiedan\\2022-12-9\\output.txt", "w", stdout);
    while (cin >> t) {
        for (int i = 1; i <= t; i++)cin >> a[i].first >> a[i].second;
        merge_sort(1, t);
        for (int i = 1; i <= t; i++)cout << a[i].first << " " << a[i].second << endl;
    }
    //关闭文件
    fclose(stdin);
    fclose(stdout);
    return 0;
}
