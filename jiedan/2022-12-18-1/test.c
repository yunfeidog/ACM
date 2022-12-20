#include "stdio.h"
#include "string.h"
char s[10010];

int main() {
//    如果待压缩串为"AAABBBBCBB"，则压缩的结果是(A,3)(B,4)(C,1)(B,2)。
    scanf("%s", s);
    int len = strlen(s);
    int count = 1;
    for (int i = 0; i < len; i++) {
        if (s[i] == s[i + 1]) count++;
        else {
            printf("(%c,%d)", s[i], count);
            count = 1;
        }
    }


    return 0;
}
