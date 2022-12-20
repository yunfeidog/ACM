#include "stdio.h"

//设n是一任意自然数。若将n的各位数字反向排列所得自然数n1与n相等，则称n为一回文数。例如，若n=1234321，则称n为一回文数；但若n=1234567，则n不是回文数。

int main() {
    int n;
    scanf("%d", &n);
    int n1 = 0;
    int n2 = n;
    while (n2 > 0) {
        n1 = n1 * 10 + n2 % 10;
        n2 /= 10;
    }
    if (n1 == n) {
        printf("是回文数");
    } else {
        printf("不是回文数");
    }
    return 0;
}
