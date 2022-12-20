#include "stdio.h"
void time(int *,int *);
int main() {
    int min,hour;
    printf("Enter two numbers:");
    scanf("%d%d",&min,&hour);
    time(&min,&hour);


    return 0;
}

void time(int *min,int *hour){
    int sec;
    sec=((*hour)*60+(*min))*60;
    printf("The total number of seconds is %d",sec);
    return;
}
