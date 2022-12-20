#include "stdio.h"


int isprime(int x){
    int i;
    for(i=2;i<x;i++){
        if(x%i==0){
            return 0;
        }
    }
    return 1;
}
int a[7];
int idx=0;

int main()
{
    while (idx!=7){
        printf("请输入第%d个质数数：",idx+1);
        int x;
        scanf("%d",&x);
        if(isprime(x)){
            a[idx]=x;
            idx++;
        }
        else{
            printf("输入的不是质数，请重新输入\n");
        }
    }
    //保存到文件中
    FILE *fp;
    fp=fopen("H:\\C++\\VsCode_cpp\\jiedan\\2022-12-11-3\\7prime.txt","w");
    for(int i=0;i<7;i++){
        fprintf(fp,"%d\n",a[i]);
    }
    fclose(fp);


    return 0;
}


