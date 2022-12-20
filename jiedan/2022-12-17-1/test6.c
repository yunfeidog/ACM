#include "stdio.h"

int a[1000];
int n;
//使用递归求数组a前n个元素的和
int sum(int n) {
    if (n == 1) {
        return a[0];
    } else {
        return a[n - 1] + sum(n - 1);
    }
}
//使用迭代求数组a前n个元素的和
int sum2(int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

int main() {
    printf("请输入数组的长度:");
    scanf("%d", &n);
    printf("请输入数组的元素:");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    return 0;
}
