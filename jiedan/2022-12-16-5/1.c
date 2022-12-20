#include "stdio.h"


int main() {
//计算1+4+7+10+…+n,当和超过500时，其n的值为多少？
    int n = 1;
    int sum = 0;
    while (sum < 500) {
        sum += n;
        n += 3;
    }
    printf("n=%d\n", n);
    return 0;
}
