#include "stdio.h"
#include "string.h"

struct people {
    char name[20];
    char id_card[20];
    int status;
} queue[10010];

int front = 0, rear = 0;

void push();

void pop();

void query();

void show();

void status();

int main() {
    printf("欢迎使用核酸检测队列管理系统\n");
    printf("1.入队功能\n");
    printf("2.出队检测\n");
    printf("3.查找功能\n");
    printf("4.打印队列\n");
    printf("5.队列状态\n");
    printf("6.退出\n");
    while (1) {
        printf("请输入你的选择:\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            push();
        } else if (choice == 2) {
            pop();
        } else if (choice == 3) {
            query();
        } else if (choice == 4) {
            show();
        } else if (choice == 5) {
            status();
        } else if (choice == 6) {
            printf("退出\n");
            break;
        } else {
            printf("输入错误，请重新输入\n");
        }

    }
    return 0;
}

void push() {
    printf("入队功能\n");
    if (rear - front > 10) {
        printf("队列已满，无法入队\n");
        return;
    }
    //一次入队n个人
    printf("请输入入队人数:\n");
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        printf("请输入第%d个人的姓名,身份证:\n", i + 1);
        scanf("%s %s", queue[rear].name, queue[rear].id_card);
        getchar();
        rear++;
    }
}

void pop() {
    printf("出队检测\n");
    if (front == rear) {
        printf("队列为空\n");
        return;
    }
    printf("请输入安排十人检测还是单人检测(1/10):\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("姓名:%s 身份证号:%s完成核酸检测\n", queue[front].name, queue[front].id_card);
        queue[front].status = 1;
        front++;
    } else if (choice == 10) {
        for (int i = 0; i < 10; ++i) {
            if (front == rear) {
                printf("队列为空\n");
                return;
            }
            printf("姓名:%s 身份证号:%s完成核酸检测\n", queue[front].name, queue[front].id_card);
            queue[front].status = 1;
            front++;
        }
    } else {
        printf("输入错误\n");
    }
}

void query() {
    printf("查找功能\n");
    printf("请输入身份证号:\n");
    char id_card[20];
    scanf("%s", id_card);
    //检查是否已经完成核酸
    for (int i = 0; i < front; i++) {
        if (strcmp(queue[i].id_card, id_card) == 0) {
            if (queue[i].status == 1) {
                printf("姓名：%s已完成核酸检测\n", queue[i].name);
                return;
            }
        }
    }
    for (int i = front; i < rear; ++i) {
        if (strcmp(queue[i].id_card, id_card) == 0) {
            printf("姓名:%s 身份证号:%s正在排队进行核酸检测\n", queue[i].name, queue[i].id_card);
            return;
        }
    }
    printf("此人没有来排队\n");
}

void show() {
    printf("打印队列\n");
    //按身份证进行排序输出
    //先将队伍复制一份
    struct people temp[20];
    for (int i = front; i < rear; i++) {
        temp[i] = queue[i];
    }
    //冒泡排序
    for (int i = front; i < rear; i++) {
        for (int j = front; j < rear - i - 1; j++) {
            if (strcmp(temp[j].id_card, temp[j + 1].id_card) > 0) {
                struct people t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }
    //输出队伍,加上序号
    for (int i = front; i < rear; i++) {
        printf("%d 姓名:%s 身份证号:%s\n", i - front + 1, temp[i].name, temp[i].id_card);
    }
}

void status() {
    printf("队列状态：\n");
    if (front == rear) {
        printf("队列为空\n");
    } else {
        //第一位是谁
        printf("队列中共有%d人正在排队\n", rear - front);
        printf("第一位是:%s\n", queue[front].name);
        //最后一位
        printf("最后一位是:%s\n", queue[rear - 1].name);
    }
}