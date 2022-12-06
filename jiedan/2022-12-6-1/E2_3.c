#include "stdio.h"

int main() {
    int sum=0;
    for(int i=1;i<=300;i++) sum+=i;
    printf("1-300和为：%d",sum);
    return 0;
}
