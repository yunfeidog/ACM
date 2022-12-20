#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//核酸检测排队系统

struct people{
    char name[20];
    char id[20];
    int flag;//是否检测，0表示未检测，1表示已检测
}peoples[100];
int front = 0;
int rear = 0;

void addPeople();//添加人员

void popPeople();//出队检测

void queryPeople();//查询人员

void sortByID();//按身份证号排序

void show();//显示队列

void menu();//菜单

int main() {
    while (1)menu();

    return 0;
}

void menu(){
    printf("欢迎使用核酸检测排队系统\n");
    printf("1.添加人员\n");
    printf("2.出队检测\n");
    printf("3.查询人员\n");
    printf("4.按身份证号排序\n");
    printf("5.显示队列\n");
    printf("6.退出\n");
    printf("请输入你的选择：\n");
    int choice;
    scanf("%d",&choice);
    switch (choice){
        case 1:
            addPeople();
            break;
        case 2:
            popPeople();
            break;
        case 3:
            queryPeople();
            break;
        case 4:
            sortByID();
            break;
        case 5:
            show();
            break;
        case 6:
            printf("退出系统\n");
            exit(0);
    }
}

void addPeople(){
    printf("请输入姓名：\n");
    scanf("%s",peoples[rear].name);
    printf("请输入身份证号：\n");
    scanf("%s",peoples[rear].id);
    peoples[rear].flag = 0;
    rear++;
    printf("添加成功\n");
}

void popPeople(){
    if(front == rear){
        printf("队列为空\n");
        return;
    }
    printf("请输入单人检测还是10人混检，1表示单人检测，2表示10人混检\n");
    int choice;
    scanf("%d",&choice);
    if(choice == 1){
        printf("姓名：%s，身份证号：%s，进行核酸检测\n",peoples[front].name,peoples[front].id);
        peoples[front].flag = 1;
        front++;
    }else if(choice == 2){
        int count = 0;
        for (int i = front; i < rear; ++i) {
            if(peoples[i].flag == 0){
                count++;
            }
        }
        if(count >= 10){
            for (int i = front; i < front+10; ++i) {
                printf("姓名：%s，身份证号：%s，检测结果：",peoples[i].name,peoples[i].id);
                if(peoples[i].flag == 0){
                    printf("未检测\n");
                }else{
                    printf("已检测\n");
                }
                peoples[i].flag = 1;
            }
            front += 10;
        }else{
            printf("未检测人数不足10人，无法进行10人混检\n");
        }
    }else{
        printf("输入错误\n");

    }
}

void queryPeople(){
    printf("请输入要查询的人员的身份证号：\n");
    char id[20];
    scanf("%s",id);
    for (int i = 0; i < rear; ++i) {
        if(strcmp(peoples[i].id,id) == 0){
            printf("姓名：%s，身份证号：%s，检测结果：",peoples[i].name,peoples[i].id);
            if(peoples[i].flag == 0){
                printf("未检测\n");
            }else{
                printf("已检测\n");
            }
            return;
        }
    }
    printf("未找到该人员\n");
}

void sortByID(){
    //只排序正在排队的人员
    for (int i = front; i < rear; ++i) {
        for (int j = i+1; j < rear; ++j) {
            if(strcmp(peoples[i].id,peoples[j].id) > 0){
                struct people temp = peoples[i];
                peoples[i] = peoples[j];
                peoples[j] = temp;
            }
        }
    }
    //输出
    for (int k = front; k < rear; ++k) {
        printf("姓名：%s，身份证号：%s正在排队\n",peoples[k].name,peoples[k].id);
    }
}

void show(){
    printf("当前排队人数：%d\n",rear-front);
    printf("队伍信息：\n");
    for (int i = front; i < rear; ++i) {
        printf("姓名：%s，身份证号：%s\n",peoples[i].name,peoples[i].id);
    }
}