#include "stdio.h"

int main() {

//    找出1000以内的所有完数
//    完数：一个数恰好等于它的因子之和，这个数就称为“完数”。

    for(int i=1;i<=1000;i++){
        int sum=0;
        for(int j=1;j<i;j++){
            if(i%j==0)sum+=j;
        }
        if(sum==i)printf("%d\n",i);
    }

    return 0;
}
