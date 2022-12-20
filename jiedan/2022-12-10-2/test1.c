#include "stdio.h"

//解决约瑟夫问题
int main() {
    int n, m;
    printf("请输入总人数：");
    scanf("%d", &n);
    printf("请输入报数的大小：");
    scanf("%d", &m);
    int a[n];
    //初始化数组,将所有人的编号放入数组中，例如数组a[0]=1
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    int i = 0;
    int cnt = 0;
    int t=m;
    //    数组a[i]=0表示该人已经出局
    while (cnt < n - 1) {//一共要出去n-1个人
        if (a[i] != 0) {//如果该人没有出局
            m--;//报数
            if (m == 0) {//如果报到m
                a[i] = 0;//该人出局
                m = t;//重新报数
                cnt++;//出局人数加1
            }
        }
        i++;//指向下一个人
        if (i == n) {//如果指向最后一个人，从头开始
            i = 0;//指向第一个人
        }
    }
    //输出最后一个人的编号
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            printf("猴王是%d", a[i]);
        }
    }
    return 0;
}