#include "stdio.h"

int main() {
    int x;
    scanf("请输入公里：%d",&x);
    double sum=0;
    if(x<=3) sum=10;
    else if(x>3&&x<10) {
        sum=10+2*x;
    } else{
        sum=30+(x-10*3)*3;
    }
    printf("车费是：%d",sum);
    return 0;
}
