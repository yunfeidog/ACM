#include "stdio.h"

int main() {
    double x;
    scanf("请输入金额%lf", &x);
    double res = 0;
    if (x <= 5000) res = 0;
    else if (x > 5000 && x <= 36000) res = (x - 5000) * 0.03;
    else if (x > 36000 && x <= 144000) res = (x - 5000) * 0.1 - 2520;
    else res = (x - 50000) * 0.2 - 16920;
    printf("朱芮萱应缴纳的税款为:%.2f", res);
    return 0;
}
