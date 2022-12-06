#include "stdio.h"

int cmp(int x, int y) {
    return x > y ? x : y;
}

int main() {
    int xuehao = 1012921;
    int x = xuehao % 10;
    int y = xuehao % 10 % 10;
    printf("%d", cmp(x,y));
    return 0;
}
