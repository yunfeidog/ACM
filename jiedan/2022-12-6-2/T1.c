#include "stdio.h"

double fact(int n){
    if(n==1||n==0) return 1;
    return n* fact(n-1);
}

int main() {
    int s,m,n;
    scanf("%d%d%d",&s,&m,&n);
    printf("%f\n", fact(s));
    if(m<n){
        printf("输入不合法\n");
    }
    printf("%f\n", fact(m)/ (fact(m-n)* fact(n)));
    return 0;
}
