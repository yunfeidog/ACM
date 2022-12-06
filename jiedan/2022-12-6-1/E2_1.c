#include "stdio.h"

int main() {
    int x;
    scanf("请输入一个数：%d", &x);
    if (x & 1) printf("输入的数值是奇数");
    else printf("输入的数值是偶数");
    return 0;
}
