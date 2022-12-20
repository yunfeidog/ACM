#include "stdio.h"

struct player{
    int id;
    char name[100];
    int sex;
    int score[10];
};

struct player players[110];
int len=0;

int main() {

    //读取文件FILE *fp = fopen("player.txt", "r");
    FILE  *fp= fopen("H:\\C++\\VsCode_cpp\\jiedan\\2022-12-11-2\\Player_Info.txt","r");
    if (fp == NULL) {
        printf("文件打开失败");
        return 0;
    }
    //读取文件内容
    fscanf(fp, "%d", &len);
    printf("len = %d\n", len);
    for (int i = 0; i < len; i++) {
        fscanf(fp, "%d %s %d", &players[i].id, players[i].name, &players[i].sex);
        for (int j = 0; j < 10; j++) {
            fscanf(fp, "%d", &players[i].score[j]);
        }
    }
    fclose(fp);
    //打印数组内容
    for (int i = 0; i < len; i++) {
        printf("%d %s %d ", players[i].id, players[i].name, players[i].sex);
        for (int j = 0; j < 10; j++) {
            printf("%d ", players[i].score[j]);
        }
        printf("\n");
    }

    return 0;
}
