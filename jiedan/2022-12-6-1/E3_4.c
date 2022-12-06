#include<stdio.h>

int isss(int number) {
    int i;
    for (i = 2; i * i <= number; i++)if (number % i == 0)return 0;
    return 1;
}

void main() {
    int i, j, k;
    printf("请输入一个偶数:");
    scanf("%d", &i);
    for (j = 2; j < i; j++) {
        if (!isss(j))continue;
        for (k = (i - j); k > j; k--) {
            if (!isss(k))continue;
            if (j + k == i)printf("\n [%d] = [%d] + [%d] ", i, j, k);
        }
    }
}
