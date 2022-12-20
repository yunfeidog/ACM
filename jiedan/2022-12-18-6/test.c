#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct worker {
    int id;
    char name[20];
    char sex[10];
    int age;
    char education[10];
    double price;
    char address[20];
    char phone[20];
} workers[100];

int len = 0;

void menu();

void add();

void sortById();

void sortByAge();

void sortByPrice();

void queryById();

void queryByEducation();

void deleteById();

void updateById();

void show();

int main() {
    while (1) menu();
    return 0;
}

void menu() {
    printf("欢迎使用职工管理系统\n");
    printf("1.添加职工信息\n");
    printf("2.按编号排序\n");
    printf("3.按年龄排序\n");
    printf("4.按工资排序\n");
    printf("5.按编号查询\n");
    printf("6.按学历查询\n");
    printf("7.按编号删除\n");
    printf("8.按编号修改\n");
    printf("9.显示所有职工信息\n");
    printf("0.退出\n");
    printf("请输入你的选择：");

    int n;
    scanf("%d", &n);
    switch (n) {
        case 1:
            add();
            break;
        case 2:
            sortById();
            break;
        case 3:
            sortByAge();
            break;
        case 4:
            sortByPrice();
            break;
        case 5:
            queryById();
            break;
        case 6:
            queryByEducation();
            break;
        case 7:
            deleteById();
            break;
        case 8:
            updateById();
            break;
        case 9:
            show();
            break;
        case 0:
            exit(0);
        default:
            printf("输入错误，请重新输入\n");
            menu();
    }
}

void add(){
    printf("请依次输入职工编号、姓名、性别、年龄、学历、工资、住址、电话号码\n");
    scanf("%d%s%s%d%s%lf%s%s", &workers[len].id, workers[len].name, workers[len].sex, &workers[len].age, workers[len].education, &workers[len].price, workers[len].address, workers[len].phone);
    len++;
    printf("添加成功\n");
}

void sortById(){
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (workers[i].id > workers[j].id) {
                struct worker temp = workers[i];
                workers[i] = workers[j];
                workers[j] = temp;
            }
        }
    }
    printf("排序成功\n");
    show();
}

void sortByAge(){
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (workers[i].age > workers[j].age) {
                struct worker temp = workers[i];
                workers[i] = workers[j];
                workers[j] = temp;
            }
        }
    }
    printf("排序成功\n");
    show();
}

void sortByPrice(){
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (workers[i].price > workers[j].price) {
                struct worker temp = workers[i];
                workers[i] = workers[j];
                workers[j] = temp;
            }
        }
    }
    printf("排序成功\n");
    show();
}

void queryById(){
    printf("请输入要查询的职工编号\n");
    int id;
    scanf("%d", &id);
    for (int i = 0; i < len; i++) {
        if (workers[i].id == id) {
            printf("编号\t姓名\t性别\t年龄\t学历\t工资\t住址\t电话号码\n");
            printf("%d\t%s\t%s\t%d\t%s\t%.2lf\t%s\t%s\n", workers[i].id, workers[i].name, workers[i].sex, workers[i].age, workers[i].education, workers[i].price, workers[i].address, workers[i].phone);
            return;
        }
    }
    printf("未找到该职工\n");
}

void queryByEducation(){
    printf("请输入要查询的学历\n");
    char education[10];
    scanf("%s", education);
    printf("编号\t姓名\t性别\t年龄\t学历\t工资\t住址\t电话号码\n");
    for (int i = 0; i < len; i++) {
        if (strcmp(workers[i].education, education) == 0) {
            printf("%d\t%s\t%s\t%d\t%s\t%.2lf\t%s\t%s\n", workers[i].id, workers[i].name, workers[i].sex, workers[i].age, workers[i].education, workers[i].price, workers[i].address, workers[i].phone);
        }
    }
}

void deleteById(){
    printf("请输入要删除的职工编号\n");
    int id;
    scanf("%d", &id);
    for (int i = 0; i < len; i++) {
        if (workers[i].id == id) {
            for (int j = i; j < len - 1; j++) {
                workers[j] = workers[j + 1];
            }
            len--;
            printf("删除成功\n");
            return;
        }
    }
    printf("未找到该职工\n");
}

void updateById(){
    printf("请输入要修改的职工编号\n");
    int id;
    scanf("%d", &id);
    for (int i = 0; i < len; i++) {
        if (workers[i].id == id) {
            printf("请依次输入职工编号、姓名、性别、年龄、学历、工资、住址、电话号码\n");
            scanf("%d%s%s%d%s%lf%s%s", &workers[i].id, workers[i].name, workers[i].sex, &workers[i].age, workers[i].education, &workers[i].price, workers[i].address, workers[i].phone);
            printf("修改成功\n");
            return;
        }
    }
    printf("未找到该职工\n");
}



void show(){
    printf("所有职工信息如下：\n");
    printf("编号\t姓名\t性别\t年龄\t学历\t工资\t住址\t电话号码\n");
    for (int i = 0; i < len; i++) {
        printf("%d\t%s\t%s\t%d\t%s\t%.2lf\t%s\t%s\n", workers[i].id, workers[i].name, workers[i].sex, workers[i].age, workers[i].education, workers[i].price, workers[i].address, workers[i].phone);
    }
}