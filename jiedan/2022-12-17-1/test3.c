#include "stdio.h"

//判断一个函数三角形形状
void judgeTriangle(int a, int b, int c) {
    if (a + b > c && a + c > b && b + c > a) {
        if (a == b && b == c) {
            printf("等边三角形");
        } else if (a == b || b == c || a == c) {
            printf("等腰三角形");
        } else {
            printf("普通三角形");
        }
    } else {
        printf("不是三角形");
    }
}

int main() {

    int a, b, c;
    printf("请输入三角形的三条边:");
    scanf("%d%d%d", &a, &b, &c);
    judgeTriangle(a, b, c);

    return 0;
}
