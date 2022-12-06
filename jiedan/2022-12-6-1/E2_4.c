#include "stdio.h"

int main() {
    double x=13.0756;
    int cnt=0;
    while (x<15){
        x=x*1.01;
        cnt++;
    }
    printf("一共需要%d年",cnt);

    return 0;
}
