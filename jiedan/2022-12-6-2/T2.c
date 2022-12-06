#include "stdio.h"

double fact(int n) {
    if (n == 1 || n == 0) return 1;
    return n * fact(n - 1);
}

double power(double x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;
    return x * power(x,n - 1);
}

int main() {
    int x;
    scanf("%d",&x);
    double res=0;
    int t=-1;
    for(int i=0;i<20;i++){
        t*=-1;
        res=res+(power(x,2*i+1))/((2*i+1)* fact(i));
    }
    printf("%f",res);
    return 0;
}
