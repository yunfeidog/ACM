#include "stdio.h"



int main() {
    int a,b,c,d;
    //给你一个ip地址，w=(a+b+c)/d
    scanf("%d.%d.%d.%d",&a,&b,&c,&d);
    //判断w是不是素数
    int w=(a*b+c)/d;
    int flag=1;
    for(int i=2;i<w;i++){
        if(w%i==0){
            flag=0;
            break;
        }
    }
    if(flag==1){
        printf("Yes");
    }else{
        printf("No");
    }
    return 0;
}
