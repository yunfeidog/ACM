#include "stdio.h"

int is_prime(int x){
    if(x<2)return 0;
    for(int i=2;i<=x/i;i++){
        if(x%i==0)return 0;
    }
    return 1;
}

int main() {
    int m,n;
    int sum;
    scanf("%d %d",&m,&n);
    if(m>n){
        int temp=m;
        m=n;
        n=temp;
    }
    for(int i=m;i<=n;i++){
        if(is_prime(i)){
            sum+=i;
        }
    }
    printf("%d",sum);

    return 0;
}
