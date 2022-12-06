#include "stdio.h"

double f(int R,int G,int B){
    return R*0.3+G*0.59+B*0.11;
}
int main() {
    printf("%d\n",(int)f(102,10,234));
    printf("%d\n",(int)f(255,255,255));
    printf("%d\n",(int)f(134,232,167));
    printf("%d\n",(int)f(0,25,34));

    return 0;
}
