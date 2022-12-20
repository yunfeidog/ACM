#include "stdio.h"
#include "stdlib.h"

//4.	求[500，600]范围一个随机数的所有因数。
int main()
{
    int num;
    int i;
    num=rand()%100+500;
    printf("随机数是：%d\n",num);
    printf("所有因数是：");
    for(i=1;i<=num;i++)
    {
        if(num%i==0)
        {
            printf("%d ",i);
        }
    }
    return 0;
}

