#include "stdio.h"

int main() {
    //使用for循环，计算n!的值
    int n=10;
    int sum=1;
    for (int i = 1; i <= n; i++) {
        sum*=i;
    }
    printf("%d!=%d",n,sum);

    return 0;
}
