#include "stdio.h"

int main() {
    //使用for循环计算pi的值,指定精度为0.0001
    //公式为：pi/4=1-1/3+1/5-1/7+1/9-1/11+...
    double sum = 0;
    for (int i = 1; i <= 100000; i += 2) {
        if (i % 4 == 1) {
            sum += 1.0 / i;
        } else {
            sum -= 1.0 / i;
        }
    }
    printf("pi=%.4lf", sum * 4);

    return 0;
}
