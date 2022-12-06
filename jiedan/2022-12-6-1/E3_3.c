#include "stdio.h"

int f(int d) {
    int sum = 0;
    for (int i = 1; i <= d; i++) {
        if (i %2==1) sum += i;
    }
    return sum;
}

int main() {
    int d ;
    scanf("%d",&d);
    int sum= f(d);
    printf("½á¹ûÎª£º%d",sum);
    return 0;
}
