#include "stdio.h"

//3.	从键盘输入一个6位以内的非负整数，判断出这个数是几位数，并计算出全部位数数字的和。
int main()
{
    int num;
    int count=0;
    int sum=0;
    printf("请输入一个6位以内的非负整数：");
    scanf("%d",&num);
    while(num!=0)
    {
        sum+=num%10;
        num/=10;
        count++;
    }
    printf("这个数是%d位数，全部位数数字的和是%d",count,sum);
    return 0;
}
