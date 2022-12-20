#include "stdio.h"



int main() {
    //使用for循环计算1-1/2+1/3-...+1/n的值,指定精度为0.0001,n为输入的值
    double n;
    printf("请输入n的值：");
    scanf("%lf", &n);
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            sum -= 1.0 / i;
        } else {
            sum += 1.0 / i;
        }
    }
    printf("sum=%.4lf", sum);

    return 0;
}
