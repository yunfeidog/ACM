#include "stdio.h"

int main() {
    //设计程序求1-1/2+1/3-...-1/99+1/100的值
    int i;
    double sum = 0;
    for (i = 1; i <= 100; i++) {
        if (i % 2 == 0) {
            sum -= 1.0 / i;
        } else {
            sum += 1.0 / i;
        }
    }
    printf("sum=%lf\n", sum);

    return 0;
}
