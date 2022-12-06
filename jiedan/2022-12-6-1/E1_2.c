#include <stdio.h>
int main() {
    printf("请输入人民币金额：");
    double x;
    scanf("%lf",&x);
    printf("兑换后的美元金额为：%.2f",x/6.5478);
    return 0;
}
