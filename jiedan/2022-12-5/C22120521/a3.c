#include <stdio.h>
#include <math.h>

int f(int x){
    if(x==1||x==0) return 1;
    return x*f(x-1);
}

int main (void)
{
    for(int i=1;i<=10;i++){
        printf("%d!=%d\n",i,f(i));
    }
    return 0;
}