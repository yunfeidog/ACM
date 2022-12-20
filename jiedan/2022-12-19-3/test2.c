#include "stdio.h"

float add(float a, float b) {
    return a + b;
}

float sub(float a, float b) {
    return a - b;
}

float mul(float a, float b) {
    return a * b;
}

float div(float a, float b) {
    return a / b;
}

int main() {
    float a, b;
    char c;
    scanf("%f %c %f", &a, &c, &b);
    switch (c) {
        case '+':
            printf("%.2f", add(a, b));
            break;
        case '-':
            printf("%.2f", sub(a, b));
            break;
        case '*':
            printf("%.2f", mul(a, b));
            break;
        case '/':
            printf("%.2f", div(a, b));
            break;
        default:
            printf("error");
    }

    return 0;
}
