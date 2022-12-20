#include "stdio.h"
#include "stdlib.h"

//学生链表
struct student
{
    int id;
    char name[20];
    int phone;
    struct student *next;
}s;

//学生链表头
struct student *head = NULL;


//添加学生到链表最后
void addStudent()
{
    struct student *p = (struct student *)malloc(sizeof(struct student));
    printf("请输入学生的学号:");
    scanf("%d", &p->id);
    printf("请输入学生的姓名:");
    scanf("%s", p->name);
    printf("请输入学生的电话:");
    scanf("%d", &p->phone);
    p->next = NULL;
    if (head == NULL)
    {
        head = p;
    }
    else
    {
        struct student *q = head;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
    }
}

//在指定位置插入一个学生
void insertStudent()
{
    int index;
    printf("请输入要插入的位置:");
    scanf("%d", &index);
    if (index < 1)
    {
        printf("插入位置不合法");
        return;
    }
    if (index == 1)
    {
        struct student *p = (struct student *)malloc(sizeof(struct student));
        printf("请输入学生的学号:");
        scanf("%d", &p->id);
        printf("请输入学生的姓名:");
        scanf("%s", p->name);
        printf("请输入学生的电话:");
        scanf("%d", &p->phone);
        p->next = head;
        head = p;
    }
    else
    {
        struct student *q = head;
        int i = 1;
        while (q != NULL && i < index - 1)
        {
            q = q->next;
            i++;
        }
        if (q == NULL)
        {
            printf("插入位置不合法");
            return;
        }
        struct student *p = (struct student *)malloc(sizeof(struct student));
        printf("请输入学生的学号:");
        scanf("%d", &p->id);
        printf("请输入学生的姓名:");
        scanf("%s", p->name);
        printf("请输入学生的电话:");
        scanf("%d", &p->phone);
        p->next = q->next;
        q->next = p;
    }
}

//修改指定学号学生信息
void updateStudent()
{
    int id;
    printf("请输入要修改的学生学号:");
    scanf("%d", &id);
    struct student *p = head;
    while (p != NULL)
    {
        if (p->id == id)
        {
            printf("请输入学生的学号:");
            scanf("%d", &p->id);
            printf("请输入学生的姓名:");
            scanf("%s", p->name);
            printf("请输入学生的电话:");
            scanf("%d", &p->phone);
            return;
        }
        p = p->next;
    }
    printf("没有找到学号为%d的学生", id);
}

//删除指定学号学生
void deleteStudent()
{
    int id;
    printf("请输入要删除的学生学号:");
    scanf("%d", &id);
    if (head == NULL)
    {
        printf("没有学生信息");
        return;
    }
    if (head->id == id)
    {
        struct student *p = head;
        head = head->next;
        free(p);
        return;
    }
    struct student *p = head;
    while (p->next != NULL)
    {
        if (p->next->id == id)
        {
            struct student *q = p->next;
            p->next = q->next;
            free(q);
            return;
        }
        p = p->next;
    }
    printf("没有找到学号为%d的学生", id);
}

//输出所有学生信息
void printStudent()
{
    //输出总人数
    int count = 0;
    struct student *p = head;
    while (p != NULL)
    {
        printf("学号:%d 姓名:%s 电话:%d", p->id, p->name, p->phone);
        p = p->next;
        count++;

    }
    printf("\n总人数为%d", count);
}

void menu(){
    printf("欢迎使用学生管理系统\n");
    printf("1.添加学生\n");
    printf("2.插入学生\n");
    printf("3.修改学生\n");
    printf("4.删除学生\n");
    printf("5.输出学生\n");
    printf("6.退出系统\n");


    int sel;
    printf("请输入选择:");
    scanf("%d", &sel);
    switch (sel) {
        case 1:
            addStudent();
            break;
        case 2:
            insertStudent();
            break;
        case 3:
            updateStudent();
            break;
        case 4:
            deleteStudent();
            break;
        case 5:
            printStudent();
            break;
        case 6:
            printf("退出系统\n");
            exit(0);
        default:
            break;
    }

}

int main() {
    while (1) menu();
    return 0;
}
