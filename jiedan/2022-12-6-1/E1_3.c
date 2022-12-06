#include "stdio.h"

int main() {
    int x;
    scanf("%d",&x);
    int ge=x%10,shi=x/10%10,bai=x/100;
    printf("各位数的立方之和为：",ge*ge*ge,shi*shi*shi,bai*bai*bai);
    return 0;
}
