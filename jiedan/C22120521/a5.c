#include <stdio.h>
int main() {
    double e=1, t=1;
    for (int i = 1; t >= 1e-6; ++i)
        e += t /= i;
    printf("%.4f\n", e);
    return 0;
}