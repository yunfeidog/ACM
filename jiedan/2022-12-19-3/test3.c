#include "stdio.h"

int a[]={13,3,0,21,17,6,0,77,0,14};

void func(int *a,int n){
    int i=0,j=n-1;
    while (i<j){
        while (i<j&&a[i]!=0)i++;
        while (i<j&&a[j]==0)j--;
        if(i<j){
            int t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    //降序排序
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]<a[j]){
                int t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }

}

int main() {
    for(int i=0;i<10;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    func(a,10);
    for(int i=0;i<10;i++){
        printf("%d ",a[i]);
    }

    return 0;
}
