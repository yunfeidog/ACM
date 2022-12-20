#include "stdio.h"
#include "string.h"
#include "stdlib.h"

typedef struct fridge {
    double v;
    double tmin;
    double tmax;
} fridge;

typedef struct food {
    char name[20];
    double v;
    double t;
    char type[20];
} food;

fridge fridge1;

//用链表来保存食物信息

typedef struct node {
    food food;
    struct node *next;
} node;

node *head = NULL;

//添加食物信息
void add();

//显示冰箱信息
void show();

//删除食物信息
void delete();

//查询食物信息
void query();

//修改食物信息
void update();

//保存食物信息
void save();

//读取食物信息
void read();

//显示菜单
void menu();

//初始化冰箱信息
void init();

int main() {
    init();
    while (1) menu();
}

void init() {
    fridge1.v = 50;
    fridge1.tmin = -20;
    fridge1.tmax = 10;
}

//显示菜单
void menu() {
    read();
    printf("1.添加食物信息\n");
    printf("2.显示冰箱信息\n");
    printf("3.取出食物\n");
    printf("4.查询食物信息\n");
    printf("5.修改食物信息\n");
    printf("6.保存食物信息\n");
    printf("0.退出\n");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            add();
            save();
            break;
        case 2:
            show();
            save();
            break;
        case 3:
            delete();
            save();
            break;
        case 4:
            query();
            save();
            break;
        case 5:
            update();
            save();
            break;
        case 6:
            save();
            printf("保存成功\n");
            break;
        case 0:
            save();
            exit(0);
        default:
            printf("输入错误，请重新输入\n");
            menu();
    }
}

//添加食物信息
void add() {
    node *p = (node *) malloc(sizeof(node));
    printf("请依次输入食物名称、体积、保存温度、类型：\n");
    scanf("%s %lf %lf %s", p->food.name, &p->food.v, &p->food.t, p->food.type);
    //如果低于最低温度或者高于最高温度，提示用户
    if (p->food.t < fridge1.tmin || p->food.t > fridge1.tmax) {
        printf("食物保存温度不在冰箱温度范围内，请重新输入！\n");
        return;
    }
    //如果体积超过冰箱剩余体积，提示用户
    if (p->food.v > fridge1.v) {
        printf("食物体积超过冰箱剩余体积，请重新输入！\n");
        return;
    }

    p->next = head;
    head = p;
    fridge1.v -= p->food.v;
    printf("添加成功！\n");
}

//显示冰箱信息
void show() {
    printf("冰箱剩余体积：%.2lf\n", fridge1.v);
    printf("冰箱温度范围：%.2lf~%.2lf\n", fridge1.tmin, fridge1.tmax);
    printf("食物信息如下：\n");
    printf("食物名称\t体积\t保存温度\t类型\n");
    node *p = head;
    while (p != NULL) {
        printf("%s\t%.2lf\t%.2lf\t%s\n", p->food.name, p->food.v, p->food.t, p->food.type);
        p = p->next;
    }
}

//删除食物信息
void delete() {
    char name[20];
    printf("请输入要取出的食物名称：\n");
    scanf("%s", name);
    node *p = head;
    node *q = NULL;
    while (p != NULL) {
        if (strcmp(p->food.name, name) == 0) {
            if (q == NULL) {
                head = p->next;
            } else {
                q->next = p->next;
            }
            fridge1.v += p->food.v;
            printf("取出成功！\n");
            return;
        }
        q = p;
        p = p->next;
    }
    printf("未找到该食物！\n");
}

//查询食物信息
void query() {
    char name[20];
    printf("请输入要查询的食物种类：\n");
    scanf("%s", name);
    node *p = head;
    while (p != NULL) {
        if (strcmp(p->food.type, name) == 0) {
            printf("%s\t%.2lf\t%.2lf\t%s\n", p->food.name, p->food.v, p->food.t, p->food.type);
            return;
        }
        p = p->next;
    }
    printf("未找到该食物！\n");
}

//修改食物信息
void update() {
    char name[20];
    printf("请输入要修改的食物名称：\n");
    scanf("%s", name);
    node *p = head;
    while (p != NULL) {
        if (strcmp(p->food.name, name) == 0) {
            printf("请依次输入食物名称、体积、保存温度、类型：\n");
            char name[20];
            double v;
            double t;
            char type[20];
            scanf("%s %lf %lf %s", name, &v, &t, type);
            //如果低于最低温度或者高于最高温度，提示用户
            if (t < fridge1.tmin || t > fridge1.tmax) {
                printf("食物保存温度不在冰箱温度范围内，请重新输入！\n");
                return;
            }
            //如果体积超过冰箱剩余体积，提示用户
            if (v > fridge1.v) {
                printf("食物体积超过冰箱剩余体积，请重新输入！\n");
                return;
            }
            strcpy(p->food.name, name);
            p->food.v = v;
            p->food.t = t;
            strcpy(p->food.type, type);
            printf("修改成功！\n");
            return;
        }
        p = p->next;
    }
    printf("未找到该食物！\n");
}

//保存到文件
void save() {
    FILE *fp = fopen("fridge.txt", "w");
    if (fp == NULL) {
        printf("文件打开失败！\n");
        return;
    }
    node *p = head;
    while (p != NULL) {
        fprintf(fp, "%s %lf %lf %s\n", p->food.name, p->food.v, p->food.t, p->food.type);
        p = p->next;
    }
    fclose(fp);
}

//读取文件
void read() {
    FILE *fp = fopen("fridge.txt", "r");
    if (fp == NULL) {
        printf("文件打开失败！\n");
        return;
    }
    node *p = head;
    while (p != NULL) {
        fscanf(fp, "%s %lf %lf %s", p->food.name, &p->food.v, &p->food.t, p->food.type);
        p = p->next;
    }
    fclose(fp);
}

