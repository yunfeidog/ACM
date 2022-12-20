#include "stdio.h"

int is_prime(int x) {
    if (x < 2) return 0;
    for (int i = 2; i <=x/i; i++)if (x % i == 0) return 0;
    return 1;
}

int main() {
    int a, b, c, d;
    //给你一个ip地址，w=(a+b+c)/d
    scanf("%d.%d.%d.%d", &a, &b, &c, &d);
    int w = (a * b + c) / d;
    if (is_prime(w))printf("Yes");
    else printf("No");
    return 0;
}
