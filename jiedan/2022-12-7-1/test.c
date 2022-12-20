#include "stdio.h"
#include "student.h"

int main() {
    //读本目录中的studentList.txt文件
    FILE *fp = fopen("H:\\C++\\VsCode_cpp\\jiedan\\2022-12-7-1\\studentList.txt", "r");
    if (fp == NULL) {
        printf("failed");
        return 0;
    }
    //读取文件中的学生信息
    struct Student student;
    while (fscanf(fp, "%s,%s,%s,%d,%d", student.firstName, student.surName, student.gender, &student.id,
                  &student.age) != EOF) {
        printf("%s\n",student.firstName);
        printf("%s",student.surName);
    }

    fclose(fp);
    return 0;
}