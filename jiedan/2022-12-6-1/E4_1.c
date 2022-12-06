#include "stdio.h"

char xuehao[]="0104";

void jiami(){
    xuehao[0]+=1321;
}
void jiemi(){
    xuehao[0]-=1321;
}

int main() {
    printf("学号后四位：%s\n",xuehao);
    jiami();
    printf("加密后：%s\n",xuehao);
    jiemi();
    printf("解密后:%s\n",xuehao);
    return 0;
}
