#include "stdio.h"
#include "string.h"
#include "stdlib.h"

struct student {
    int id;
    char name[20];
    int sushe;
    int qq;
    int weixin;
    char phone[20];
} students[110];

int len = 0;

void add();

void delete();

void query();

void sortById();

void update();

int main() {
    printf("欢迎使用班级信息管理系统\n");
    while (1) {
        printf("1.添加学生信息\n");
        printf("2.删除学生信息\n");
        printf("3.查询学生信息\n");
        printf("4.按学号排序\n");
        printf("5.修改学生信息\n");
        printf("6.退出\n");
        printf("请输入你的选择:(1-6):");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                delete();
                break;
            case 3:
                query();
                break;
            case 4:
                sortById();
                break;
            case 5:
                update();
                break;
            case 6:
                printf("退出\n");
                return 0;
            default:
                printf("输入错误\n");
                break;
        }
    }
    return 0;
}

void add() {
    printf("添加学生信息\n");
    printf("请输入学生学号:");
    scanf("%d", &students[len].id);
    printf("请输入学生姓名:");
    scanf("%s", students[len].name);
    printf("请输入学生宿舍号:");
    scanf("%d", &students[len].sushe);
    printf("请输入学生QQ:");
    scanf("%d", &students[len].qq);
    printf("请输入学生微信:");
    scanf("%d", &students[len].weixin);
    printf("请输入学生电话:");
    scanf("%s", students[len].phone);
    len++;
    printf("添加成功\n");
}

void delete(){
    printf("删除学生信息\n");
    printf("请输入要删除的学生学号:");
    int id;
    scanf("%d", &id);
    int i;
    for (i = 0; i < len; i++) {
        if (students[i].id == id) {
            break;
        }
    }
    if (i == len) {
        printf("没有找到学号为%d的学生\n", id);
        return;
    }
    for (int j = i; j < len - 1; j++) {
        students[j] = students[j + 1];
    }
    len--;
    printf("删除成功\n");
}

void query(){
    printf("查询学生信息\n");
    printf("请输入要查询的学生学号:");
    int id;
    scanf("%d", &id);
    int i;
    for (i = 0; i < len; i++) {
        if (students[i].id == id) {
            break;
        }
    }
    if (i == len) {
        printf("没有找到学号为%d的学生\n", id);
        return;
    }
    printf("学号\t姓名\t宿舍号\tQQ\t微信\t电话\n");
    printf("%d\t%s\t%d\t%d\t%d\t%s\n", students[i].id, students[i].name, students[i].sushe, students[i].qq, students[i].weixin, students[i].phone);
}

void sortById(){
    printf("按学号排序\n");
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            if (students[j].id > students[j + 1].id) {
                struct student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("排序成功\n");

    // 打印排序后的结果
    printf("学号\t姓名\t宿舍号\tQQ\t微信\t电话\n");
    for (int i = 0; i < len; i++) {
        printf("%d\t%s\t%d\t%d\t%d\t%s\n", students[i].id, students[i].name, students[i].sushe, students[i].qq, students[i].weixin, students[i].phone);
    }
}

void update(){
    printf("修改学生信息\n");
    printf("请输入要修改的学生学号:");
    int id;
    scanf("%d", &id);
    int i;
    for (i = 0; i < len; i++) {
        if (students[i].id == id) {
            break;
        }
    }
    if (i == len) {
        printf("没有找到学号为%d的学生\n", id);
        return;
    }
    printf("请输入学生学号:");
    scanf("%d", &students[i].id);
    printf("请输入学生姓名:");
    scanf("%s", students[i].name);
    printf("请输入学生宿舍号:");
    scanf("%d", &students[i].sushe);
    printf("请输入学生QQ:");
    scanf("%d", &students[i].qq);
    printf("请输入学生微信:");
    scanf("%d", &students[i].weixin);
    printf("请输入学生电话:");
    scanf("%s", students[i].phone);
    printf("修改成功\n");
}