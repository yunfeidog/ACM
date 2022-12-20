#include "stdio.h"
#include "stdlib.h"

//记录1-10出现的次数
int count[10] = {0};



int main() {

    //随机生成100个1-10的随机数
    for (int i = 0; i < 100; i++) {
        int num = rand() % 10 + 1;
        count[num - 1]++;
    }
    //打印每个数出现的次数，占比
    for (int i = 0; i < 10; i++) {
        printf("%d出现的次数为%d,占比为%.2f%%\n", i + 1, count[i], count[i] / 100.0 * 100);
    }

    return 0;
}
