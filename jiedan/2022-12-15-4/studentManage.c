#include "stdio.h"
#include "string.h"

struct student {
    char name[20];
    int id;
    char sex[10];
    char birthday[20];
    char major[20];
    char className[20];
    char address[20];
} students[100];

int len=0;

void add();

void show();

void query();

void delete();

int main() {
    printf("欢迎使用学生信息管理系统\n");
    while (1) {
        printf("1.添加学生信息\n");
        printf("2.显示学生信息\n");
        printf("3.查询学生信息\n");
        printf("4.删除学生信息\n");
        printf("5.退出\n");
        printf("请输入你的选择:(1-5):");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                show();
                break;
            case 3:
                query();
                break;
            case 4:
                delete();
                break;
            case 5:
                printf("退出\n");
                return 0;
            default:
                printf("输入错误\n");
                break;
        }
    }
    return 0;
}

//添加学生信息
void add() {
    printf("请依次输入学生姓名、学号、性别、出生日期、专业、班级、家庭住址\n");
    scanf("%s %d %s %s %s %s %s", students[len].name, &students[len].id, students[len].sex, students[len].birthday, students[len].major, students[len].className, students[len].address);
    len++;
    printf("添加成功\n");
}

//显示学生信息
void show() {
    printf("学生姓名\t学号\t性别\t出生日期\t专业\t班级\t家庭住址\n");
    for (int i = 0; i < len; ++i) {
        printf("%s\t%d\t%s\t%s\t%s\t%s\t%s\n", students[i].name, students[i].id, students[i].sex, students[i].birthday, students[i].major, students[i].className, students[i].address);
    }
}

//查询学生信息
void query() {
    printf("请输入要查询的学生姓名:");
    char name[20];
    scanf("%s", name);
    for (int i = 0; i < len; ++i) {
        if (strcmp(students[i].name, name) == 0) {
            printf("学生姓名\t学号\t性别\t出生日期\t专业\t班级\t家庭住址\n");
            printf("%s\t%d\t%s\t%s\t%s\t%s\t%s\n", students[i].name, students[i].id,students[i].sex, students[i].birthday, students[i].major, students[i].className, students[i].address);
            return;
        }
    }
    printf("没有找到该学生\n");
}

//删除学生信息
void delete() {
    printf("请输入要删除的学生姓名:");
    char name[20];
    scanf("%s", name);
    for (int i = 0; i < len; ++i) {
        if (strcmp(students[i].name, name) == 0) {
            for (int j = i; j < len - 1; ++j) {
                students[j] = students[j + 1];
            }
            len--;
            printf("删除成功\n");
            return;
        }
    }
    printf("没有找到该学生\n");
}

