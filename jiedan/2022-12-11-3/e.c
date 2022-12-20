#define MAX_STU_NUM 10

#include "stdlib.h"
#include "stdio.h"

struct stuInf {
    char name[30];
    float score;
};
typedef struct stuInf STU;
STU stuIF[MAX_STU_NUM];
int n;
//对结构体按分数高低排序

void sortStu(STU *stuIF, int n) {
    int i, j;
    STU temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (stuIF[j].score < stuIF[j + 1].score) {
                temp = stuIF[j];
                stuIF[j] = stuIF[j + 1];
                stuIF[j + 1] = temp;
            }
        }
    }
}


int readfile(char *filename, STU stuIF[]);

int main() {
    char *filename = "H:\\C++\\VsCode_cpp\\jiedan\\2022-12-11-3\\学生信息.txt";
    readfile(filename, stuIF);
    sortStu(stuIF, 4);
    for (int i = 0; i < 3; i++) {
        printf("%s  %.2f\n", stuIF[i].name, stuIF[i].score);
    }




    return 0;
}

int readfile(char *filename, STU stuIF[]) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("文件打开失败");
        return 0;
    }
    int i = 0;
    while (fscanf(fp, "%d %s %f", &i,stuIF[i].name, &stuIF[i].score) != EOF) {
    }
    fclose(fp);
    return 0;
}