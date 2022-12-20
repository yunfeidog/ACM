#include "stdio.h"

int main() {
//    给出一个字符，请你判断是数字、字母，还是其他。
    char c;
    scanf("%c", &c);
    if (c >= '0' && c <= '9') {
        printf("Number");
    } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        printf("English letter");
    } else {
        printf("Unknown");
    }

    return 0;
}
