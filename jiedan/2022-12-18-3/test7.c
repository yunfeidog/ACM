#include "stdio.h"
#include "string.h"

char s1[1010];
char s2[1010];

int main() {
    scanf("%s", s1);
    scanf("%s", s2);
    int k;
    scanf("%d", &k);
    //先将s1和s2按字典序排序
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    for (int i = 0; i < len1; i++) {
        for (int j = i + 1; j < len1; j++) {
            if (s1[i] > s1[j]) {
                char t = s1[i];
                s1[i] = s1[j];
                s1[j] = t;
            }
        }
    }
    for (int i = 0; i < len2; i++) {
        for (int j = i + 1; j < len2; j++) {
            if (s2[i] > s2[j]) {
                char t = s2[i];
                s2[i] = s2[j];
                s2[j] = t;
            }
        }
    }
    //将s1和s2的前k个字符拼接起来
    char s3[1010];
    int len3 = 0;
    for (int i = 0; i < k; i++) {
        s3[len3++] = s1[i];
    }
    for (int i = 0; i < k; i++) {
        s3[len3++] = s2[i];
    }
    //将s3按字典序排序
    for (int i = 0; i < len3; i++) {
        for (int j = i + 1; j < len3; j++) {
            if (s3[i] > s3[j]) {
                char t = s3[i];
                s3[i] = s3[j];
                s3[j] = t;
            }
        }
    }
    printf("%s", s3);


    return 0;
}
