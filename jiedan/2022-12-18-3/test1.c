#include "stdio.h"

int main() {
    double a,b,c,d,e,f;
    scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f);
    double res=(a*b+c)*(1+d)*(1+e)*0.478*(1-f);
    printf("%.2lf",res);

    return 0;
}
