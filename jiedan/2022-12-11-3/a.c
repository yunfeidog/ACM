#include "stdio.h"

//1.	若一个口袋中放有9个球，其中有3个红色球，4个白色球和2个蓝色球，从中任取6个球，
//编写程序求解一共有多少种不同的颜色搭配方案。

int main()
{
    int i,j,k;
    int count=0;
    for(i=0;i<=3;i++)
    {
        for(j=0;j<=4;j++)
        {
            for(k=0;k<=2;k++)
            {
                if(i+j+k==6)
                {
                    count++;
                }
            }
        }
    }
    printf("一共有%d种不同的颜色搭配方案",count);
    return 0;
}
