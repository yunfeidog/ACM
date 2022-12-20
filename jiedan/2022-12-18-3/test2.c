#include "stdio.h"


int main() {
    char s;
    scanf("%c", &s);
    if (s >= '0' && s <= '9') {
        printf("Number");
    } else if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z')) {
        printf("English letter");
    } else {
        printf("Unknown");
    }
    return 0;
}
