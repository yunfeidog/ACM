#include "stdio.h"
#include "stdlib.h"

struct people {
    char name[20];
    int id;
    int phone;
    char address[20];
    char sex[10];
} peoples[100];
int len = 0;

void addPeople();

void updatePeople();

void queryPeople();

void deletePeople();

//统计
void countPeople();

void saveToFile();

void menu();


int main() {
    while (1){
        menu();
    }
}

void menu(){
    printf("欢迎使用通讯录管理系统\n");
    printf("1.添加联系人\n");
    printf("2.修改联系人\n");
    printf("3.查询联系人\n");
    printf("4.删除联系人\n");
    printf("5.统计联系人\n");
    printf("6.保存到文件\n");
    printf("7.退出\n");
    printf("请输入你的选择：\n");

    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            addPeople();
            break;
        case 2:
            updatePeople();
            break;
        case 3:
            queryPeople();
            break;
        case 4:
            deletePeople();
            break;
        case 5:
            countPeople();
            break;
        case 6:
            saveToFile();
            break;
        case 7:
            printf("退出系统\n");
            exit(0);
        default:
            printf("输入错误，请重新输入\n");
            menu();
            break;
    }
}

//添加人员信息
void addPeople() {
    printf("请依次输入姓名，成员号，电话号码，地址，性别\n");
    scanf("%s%d%d%s%s", peoples[len].name, &peoples[len].id, &peoples[len].phone, peoples[len].address,
          peoples[len].sex);
    len++;
}

//修改人员信息
void updatePeople() {
    int id;
    printf("请输入要修改的人员的成员号\n");
    scanf("%d", &id);
    for (int i = 0; i < len; ++i) {
        if (peoples[i].id == id) {
            printf("请依次输入姓名，成员号，电话号码，地址，性别\n");
            scanf("%s%d%d%s%s", peoples[i].name, &peoples[i].id, &peoples[i].phone, peoples[i].address,
                  peoples[len].sex);
            printf("修改成功\n");
            return;
        }
    }
    printf("没有找到该成员\n");
}

//查询人员信息

void queryPeople() {
    int id;
    printf("请输入要查询的人员的成员号\n");
    scanf("%d", &id);
    for (int i = 0; i < len; ++i) {
        if (peoples[i].id == id) {
            printf("姓名：%s\n", peoples[i].name);
            printf("成员号：%d\n", peoples[i].id);
            printf("电话号码：%d\n", peoples[i].phone);
            printf("地址：%s\n", peoples[i].address);
            printf("性别：%s\n", peoples[i].sex);
            return;
        }
    }
    printf("没有找到该成员\n");
}

//删除人员信息
void deletePeople() {
    int id;
    printf("请输入要删除的人员的成员号\n");
    scanf("%d", &id);
    for (int i = 0; i < len; ++i) {
        if (peoples[i].id == id) {
            for (int j = i; j < len - 1; ++j) {
                peoples[j] = peoples[j + 1];
            }
            len--;
            printf("删除成功\n");
            return;
        }
    }
    printf("没有找到该成员\n");
}

//统计
void countPeople() {
    //输出所有人员的信息
    for (int i = 0; i < len; ++i) {
        printf("姓名：%s    ", peoples[i].name);
        printf("成员号：%d    ", peoples[i].id);
        printf("电话号码：%d    ", peoples[i].phone);
        printf("地址：%s    ", peoples[i].address);
        printf("性别：%s    ", peoples[i].sex);
        printf("\n");
    }
    printf("总人数为%d\n", len);
}


void saveToFile() {
    FILE *fp = fopen("people.txt", "w");
    for (int i = 0; i < len; ++i) {
        fprintf(fp, "%s %d %d %s %s\n", peoples[i].name, peoples[i].id, peoples[i].phone, peoples[i].address,peoples[i].sex);
    }
    fclose(fp);
}