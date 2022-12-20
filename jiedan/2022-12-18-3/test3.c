#include "stdio.h"

#define N 1050
int n,tmp,res;
int a[N];


int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &tmp);
        a[tmp]++;
    }
    for (int i = 0; i < N; i++) {
        if(a[i]==2) res++;
    }
    printf("%d", res);
    return 0;
}
