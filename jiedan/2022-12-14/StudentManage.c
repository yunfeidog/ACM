#include "stdio.h"
#include "stdlib.h"
#include "string.h"2

struct student {
    int id;
    char name[20];
    int age;
    char sex[10];
    char className[20];
} students[100];

int len;

void add();

void query();

void statistics();

void update();

void sortByAge();

void delete();


int main() {
    printf("欢迎使用学生管理系统\n");
    while (1){
        printf("1.添加学生信息\n");
        printf("2.读取学生信息并查询学生信息\n");
        printf("3.按性别统计人数\n");
        printf("4.按学号修改年龄\n");
        printf("5.按年龄升序排序\n");
        printf("6.删除学生信息\n");
        printf("7.退出\n");
        printf("请输入你的选择:(1-7):");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                query();
                break;
            case 3:
                statistics();
                break;
            case 4:
                update();
                break;
            case 5:
                sortByAge();
                break;
            case 6:
                delete();
                break;
            case 7:
                printf("退出");
                break;
            default:
                printf("输入错误");
                break;
        }
    }



    return 0;
}


//添加学生信息

void add() {
    printf("请输入学生的学号:");
    scanf("%d", &students[len].id);
    printf("请输入学生的姓名:");
    scanf("%s", students[len].name);
    printf("请输入学生的年龄:");
    scanf("%d", &students[len].age);
    printf("请输入学生的性别:");
    scanf("%s", students[len].sex);
    printf("请输入学生的班级:");
    scanf("%s", students[len].className);
    len++;
    //检查id是否重复
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (students[i].id == students[j].id) {
                printf("学号重复，取消添加\n");
                len--;
                break;
            }
        }
    }
    printf("添加成功\n");
}

//读取学生信息并查询学生信息

void query() {
    //打印所有学生
    for (int i = 0; i < len; i++) {
        printf("%d    %s    %d    %s    %s\n", students[i].id, students[i].name, students[i].age, students[i].sex,
               students[i].className);
    }
    //查询学生
    printf("请输入要查询的学生的学号");
    int id;
    int flag=0;
    scanf("%d", &id);
    for (int i = 0; i < len; ++i) {
        if (students[i].id == id) {
            printf("%d    %s    %d    %s    %s\n", students[i].id, students[i].name, students[i].age, students[i].sex,
                   students[i].className);
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("没有该学生\n");
    }

}

//按性别统计人数

void statistics(){
    int nan=0;
    int nv=0;
    for (int i = 0; i < len; ++i) {
        if (strcmp(students[i].sex, "男") == 0) {
            nan++;
        } else {
            nv++;
        }
    }
    printf("男生人数为%d\t",nan);
    printf("女生人数为%d\n",nv);
}

//按学号修改年龄
void update(){
    printf("请输入要修改的学生的学号:\n");
    int id;
    scanf("%d", &id);
    int flag=0;
    for (int i = 0; i < len; ++i) {
        if (students[i].id == id) {
            printf("请输入修改后的年龄:\n");
            scanf("%d", &students[i].age);
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("没有该学生\n");
    }
}

//按年龄升序排序
void sortByAge(){
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (students[i].age > students[j].age) {
                struct student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    for (int i = 0; i < len; i++) {
        printf("%d    %s    %d    %s    %s\n", students[i].id, students[i].name, students[i].age, students[i].sex,students[i].className);
    }
}

//删除学生信息
void delete(){
    printf("请输入要删除的学生的学号:\n");
    int id;
    scanf("%d", &id);
    int flag=0;
    for (int i = 0; i < len; ++i) {
        if (students[i].id == id) {
            for (int j = i; j < len; ++j) {
                students[j] = students[j + 1];
            }
            len--;
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("没有该学生\n");
    }
}