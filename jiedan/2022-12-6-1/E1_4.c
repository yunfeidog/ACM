#include <stdio.h>
#include <math.h>

int main(void) {
    int a = 1, b = 2, c = 1;
    float x1, x2, delta;
    delta = b * b - 4 * a * c;
    x1 = (-b - sqrt(delta)) / (2 * a);
    x2 = (-b + sqrt(delta)) / (2 * a);
    printf("该方程有两解:x1 = %f,x2 = %f", x1, x2);
    return 0;
}