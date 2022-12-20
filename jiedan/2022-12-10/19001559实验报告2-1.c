#include "stdio.h"
#include "string.h"
char a[10][20];


int main() {
    //读取文件
    FILE *fp = fopen("H:\\C++\\VsCode_cpp\\jiedan\\2022-12-10\\city.txt", "r");
    if (fp == NULL) {
        printf("文件打开失败");
        return 0;
    }
    //读取文件内容
    int i = 0;
    while (fgets(a[i], 20, fp) != NULL) {
        i++;
    }
    //关闭文件
    fclose(fp);
    //输出文件内容
    for (int j = 0; j < i; j++) {
        printf("%s", a[j]);
    }
    //对所读取的城市按升序排序
    for (int j = 0; j < i - 1; j++) {
        for (int k = 0; k < i - 1 - j; k++) {
            if (strcmp(a[k], a[k + 1]) > 0) {
                char temp[20];
                strcpy(temp, a[k]);
                strcpy(a[k], a[k + 1]);
                strcpy(a[k + 1], temp);
            }
        }
    }
    printf("\n排序后的城市为：\n");
    //输出排序后的城市
    for (int j = 0; j < i; j++) {
        printf("%s", a[j]);
    }
    printf("请输入要查找的城市：");
    char b[20];
    scanf("%s", b);
    //查找城市
    int flag = 0;
    for (int j = 0; j < i; j++) {
        if (strcmp(a[j], b) == 0) {
            printf("找到了，是第%d个城市", j + 1);
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        printf("没有找到");
    }



    return 0;
}
