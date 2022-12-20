#include "stdio.h"
#include "stdlib.h"

int a[1010];

int main() {
    int n,l,r;
    scanf("%d%d%d", &n,&l,&r);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    //将l到r范围的数按绝对值从小到大排序，绝对值相同的，负数在前
    for(int i=l-1;i<r;i++){
        for(int j=i+1;j<r;j++){
            if(abs(a[i])>abs(a[j])){
                int t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
            if(abs(a[i])==abs(a[j])&&a[i]>a[j]){
                int t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    return 0;
}
