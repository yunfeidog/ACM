#include "stdio.h"

int main() {
    //使用for循环，计算1!+2!+3!+...+n!的值
    int n=10;
    int sum=0;
    int sum2=1;
    for (int i = 1; i <= n; i++) {
        sum2*=i;
        sum+=sum2;
    }
    printf("1!+2!+3!+...+%d!=%d",n,sum);

    return 0;
}
