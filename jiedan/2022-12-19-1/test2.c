#include "stdio.h"

int a[3][3];
int b[3][3];
int res[3][3];


int main() {
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&b[i][j]);
        }
    }
    //a+b;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            res[i][j]=a[i][j]+b[i][j];
        }
    }
    int maxn,minn;//a中最大元素和最小元素
    maxn=minn=a[0][0];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(a[i][j]>maxn)maxn=a[i][j];
            if(a[i][j]<minn)minn=a[i][j];
        }
    }
    //输出矩阵res
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            //末尾不输出空格
            if(j==2)printf("%d",res[i][j]);
            else printf("%d ",res[i][j]);
        }
        printf("\n");
    }
    printf("%d\n%d",maxn,minn);
    return 0;
}
