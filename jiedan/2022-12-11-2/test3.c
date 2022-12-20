#include "stdio.h"
#include "windows.h"

struct judger{
    char name[100];
};

struct judger judgers[110];
int len=0;

int main() {

    //读取文件FILE *fp = fopen("player.txt", "r");
    FILE  *fp= fopen("H:\\C++\\VsCode_cpp\\jiedan\\2022-12-11-2\\test.txt","r");
    if (fp == NULL) {
        printf("文件打开失败");
        return 0;
    }
    //读取文件内容
    fscanf(fp, "%d", &len);
    printf("len = %d\n", len);
    char name[200];
    fscanf(fp, "%s", name);
    printf("name = %s", name);
//    for (int i = 0; i < len; i++) {
//        fscanf(fp, "%s", judgers[i].name);
//    }
//    fclose(fp);
//    //打印数组内容
//    for (int i = 0; i < len; i++) {
//        printf("%s ", judgers[i].name);
//    }


    return 0;
}
