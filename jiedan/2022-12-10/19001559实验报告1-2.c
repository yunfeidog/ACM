#include "stdio.h"
#include "stdlib.h"

//编写加减乘除4个自定义函数add，sub，mul，div，
int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int diva(int a, int b) {
    return a / b;
}


int main() {
    printf("计算练习，电脑随机生成5道题目\n");
    printf("十以内的加减乘除（四舍五入保留两位小数），请答题：\n");
    char op;
    do {
        //随机生成5道题目
        int cnt = 0;
        for (int i = 0; i < 5; i++) {
            //随机生成两个数
            int a = rand() % 10;
            int b = rand() % 10;
            //随机生成一个运算符
            int c = rand() % 4;
            //根据运算符调用不同的函数
            switch (c) {
                case 0:
                    printf("%d+%d=", a, b);
                    scanf("%d", &c);
                    if (c == add(a, b))
                        cnt++;

                    break;
                case 1:
                    printf("%d-%d=", a, b);
                    scanf("%d", &c);
                    if (c == sub(a, b)) cnt++;
                    break;
                case 2:
                    printf("%d*%d=", a, b);
                    scanf("%d", &c);
                    if (c == mul(a, b)) cnt++;
                    break;
                case 3:
                    printf("%d/%d=", a, b);
                    scanf("%d", &c);
                    if (c == diva(a, b)) cnt++;
                    break;
            }
        }
        getchar();
        printf("正确率为：%.2f%%", 100.0 * cnt / 5);
        printf("是否继续,如果是输入Y,不是输入N\n");
        scanf("%c", &op);
    } while (op == 'y');
    return 0;
}
