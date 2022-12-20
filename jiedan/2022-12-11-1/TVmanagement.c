#include "stdio.h"
#include "string.h"
#include "stdlib.h"

//建立单链表，链表的结点指出某一型号的电视机的价格与数量
typedef struct node {
    char name[20];
    int price;
    int num;
    struct node *next;
} Node;

//建立一个数组，数组的每个元素指出某一型号的电视机的价格与数量
Node *head;

//添加电视机型号
void add(char *name, int price, int num) {
    Node *p = (Node *) malloc(sizeof(Node));
    strcpy(p->name, name);
    p->price = price;
    p->num = num;
    p->next = head;
    head = p;
}

//删除电视机型号

void del(char *name) {
    Node *p = head;
    Node *q = NULL;
    while (p != NULL) {
        if (strcmp(p->name, name) == 0) {
            if (q == NULL) {
                head = p->next;
            } else {
                q->next = p->next;
            }
            free(p);
            return;
        }
        q = p;
        p = p->next;
    }
}


//查询结点
Node *find(char *name) {
    Node *p = head;
    while (p != NULL) {
        if (strcmp(p->name, name) == 0) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

//保存电视机型号
void save() {
    FILE *fp = fopen("tv.txt", "w");
    Node *p = head;
    while (p != NULL) {
        fprintf(fp, "%s %d %d\n", p->name, p->price, p->num);
        p = p->next;
    }
    fclose(fp);
}

//读取电视机型号

void load() {
    FILE *fp = fopen("tv.txt", "r");
    if (fp == NULL) {
        return;
    }
    char name[20];
    int price, num;
    while (fscanf(fp, "%s %d %d", name, &price, &num) != EOF) {
        add(name, price, num);
    }
    fclose(fp);
}

//打印电视机型号

void print() {
    Node *p = head;
    while (p != NULL) {
        printf("%s %d %d\n", p->name, p->price, p->num);
        p = p->next;
    }
}

//1。电视机查询
void searchTV() {
    char name[20];
    printf("请输入电视机型号：");
    scanf("%s", name);
    Node *p = find(name);
    if (p == NULL) {
        printf("没有该电视机型号\n");
    } else {
        printf("电视机型号：%s 价格：%d 数量：%d\n", p->name, p->price, p->num);
    }
}

//2。电视机入库
void addTV() {
    char name[20];
    int num;
    int price;
    printf("请输入电视机型号：");
    scanf("%s", name);
    printf("请输入电视机数量：");
    scanf("%d", &num);
    printf("请输入电视机价格：");
    scanf("%d", &price);
    Node *p = find(name);
    if (p == NULL) {
        add(name, price, num);
    } else {
        p->num += num;
    }
    printf("入库成功\n");
}

//3。电视机出库
void delTV() {
    char name[20];
    int num;
    printf("请输入电视机型号：");
    scanf("%s", name);
    printf("请输入电视机数量：");
    scanf("%d", &num);
    Node *p = find(name);
    if (p == NULL) {
        printf("没有该电视机型号\n");
    } else {
        if (p->num < num) {
            printf("电视机数量不足\n");
        } else {
            p->num -= num;
            printf("出库成功\n");
        }
    }
}

//4。输出电视机信息
void printTV() {
    print();
}

//5。保存电视机信息
void saveTV() {
    save();
}

//6.从文件中读取电视机信息
void loadTV() {
    load();
}



int main() {
    printf("欢迎使用电视机管理系统！\n");
    printf("1.电视机查询操作\n");
    printf("2.电视机入库操作\n");
    printf("3.电视机出库操作\n");
    printf("4.输出所有电视机\n");
    printf("5.保存到文件\n");
    printf("6.从文件读取\n");
    printf("7.退出\n");
    while (1){
        printf("请输入操作编号：");
        int n;
        scanf("%d", &n);
        switch (n) {
            case 1:
                searchTV();
                break;
            case 2:
                addTV();
                break;
            case 3:
                delTV();
                break;
            case 4:
                printTV();
                break;
            case 5:
                saveTV();
                break;
            case 6:
                loadTV();
                break;
            case 7:
                exit(0);
            default:
                printf("输入错误\n");
                break;
        }
    }
}
