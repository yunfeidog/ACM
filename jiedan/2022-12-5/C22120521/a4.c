#include <stdio.h>
#include <math.h>

int f(int x){
    if(x==1||x==0) return 1;
    return x*f(x-1);
}
int main (void)
{
    int sum=0;
    for(int i=1;i<=10;i++){
        sum+= f(i);
    }
    printf("sum=%d\n",sum);
    return 0;
}