#include "stdio.h"

int main() {
    //使用for循环计算e的值,指定精度为0.0001
    //公式为：e=1+1/1!+1/2!+1/3!+...
    double sum = 1;
    double sum2 = 1;
    for (int i = 1; i <= 100000; i++) {
        sum2 *= i;
        sum += 1.0 / sum2;
    }
    printf("e=%.4lf", sum);

    return 0;
}
