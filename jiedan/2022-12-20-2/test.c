#include "stdio.h"
#include "string.h"
#include "stdlib.h"

//学生信息
typedef struct student {
    char name[20];
    int id;
    char className[20];
    char major[20];
    int chinese;
    int math;
    int english;
} student;

//单链表存储
typedef struct node {
    student student;
    struct node *next;
} node;

node *head = NULL;

//保存到文件中
void saveToFile();

//添加学生
void add();

//修改学生信息
void update();

//查询学生信息
void queryById();

void queryByName();

//删除学生信息
void deleteById();

void deleteByName();

//汇总
void summary();

//排序
void sortBySumScore();

//打印学生信息
void printAllStudent();

//统计平均成绩和平均分
void countAverage();

void menu();


int main() {
    while (1)menu();
}

void menu() {
    printf("====================================\n");
    printf("欢迎使用学生管理系统\n");
    printf("1.添加学生信息\n");
    printf("2.修改学生信息\n");
    printf("3.按学号查询学生信息\n");
    printf("4.按姓名查询学生信息\n");
    printf("5.按学号删除学生信息\n");
    printf("6.按姓名删除学生信息\n");
    printf("7.汇总排序\n");
    printf("8.统计平均成绩和平均分\n");
    printf("9.打印所有学生信息\n");
    printf("10.退出并保存到文件\n");
    printf("====================================\n");
    printf("请输入您的选择：");

    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            add();
            break;
        case 2:
            update();
            break;
        case 3:
            queryById();
            break;
        case 4:
            queryByName();
            break;
        case 5:
            deleteById();
            break;
        case 6:
            deleteByName();
            break;
        case 7:
            summary();
            break;
        case 8:
            countAverage();
            break;
        case 9:
            printAllStudent();
            break;
        case 10:
            saveToFile();
            exit(0);
        default:
            printf("输入错误，请重新输入\n");
            menu();
            break;
    }

}

//保存到文件中
void saveToFile() {
    printf("请输入保存的文件名：");
    char fileName[20];
    scanf("%s", fileName);


    FILE *fp = fopen(fileName, "w+");
    node *p = head;
    while (p != NULL) {
        fprintf(fp, "%s %d %s %s %d %d %d\n", p->student.name, p->student.id, p->student.className, p->student.major,
                p->student.chinese, p->student.math, p->student.english);
        p = p->next;
    }
    fclose(fp);
    printf("保存成功\n");
}

//添加学生
void add() {
    node *p = (node *) malloc(sizeof(node));
    printf("请依次输入学生姓名，学号，班级，专业，语文成绩，数学成绩，英语成绩\n");
    scanf("%s %d %s %s %d %d %d", p->student.name, &p->student.id, p->student.className, p->student.major,
          &p->student.chinese, &p->student.math, &p->student.english);
    p->next = head;
    head = p;
    printf("添加成功\n");
}

//修改学生信息
void update() {
    printf("请输入要修改的学生学号\n");
    int id;
    scanf("%d", &id);
    node *p = head;
    while (p != NULL) {
        if (p->student.id == id) {
            printf("请依次输入学生姓名，学号，班级，专业，语文成绩，数学成绩，英语成绩\n");
            scanf("%s %d %s %s %d %d %d", p->student.name, &p->student.id, p->student.className, p->student.major,
                  &p->student.chinese, &p->student.math, &p->student.english);
            printf("修改成功\n");
            return;
        }
        p = p->next;
    }
    printf("没有找到该学生\n");
}

//按照学号查询学生信息
void queryById() {
    printf("请输入要查询的学生学号\n");
    int id;
    scanf("%d", &id);
    node *p = head;
    while (p != NULL) {
        if (p->student.id == id) {
            printf("学生姓名：%s\n", p->student.name);
            printf("学生学号：%d\n", p->student.id);
            printf("学生班级：%s\n", p->student.className);
            printf("学生专业：%s\n", p->student.major);
            printf("学生语文成绩：%d\n", p->student.chinese);
            printf("学生数学成绩：%d\n", p->student.math);
            printf("学生英语成绩：%d\n", p->student.english);
            return;
        }
        p = p->next;
    }
    printf("没有找到该学生\n");
}

//按照姓名查询学生信息
void queryByName() {
    printf("请输入要查询的学生姓名\n");
    char name[20];
    scanf("%s", name);
    node *p = head;
    while (p != NULL) {
        if (strcmp(p->student.name, name) == 0) {
            printf("学生姓名：%s\n", p->student.name);
            printf("学生学号：%d\n", p->student.id);
            printf("学生班级：%s\n", p->student.className);
            printf("学生专业：%s\n", p->student.major);
            printf("学生语文成绩：%d\n", p->student.chinese);
            printf("学生数学成绩：%d\n", p->student.math);
            printf("学生英语成绩：%d\n", p->student.english);
            return;
        }
        p = p->next;
    }
    printf("没有找到该学生\n");
}

//按照学号删除学生信息
void deleteById() {
    printf("请输入要删除的学生学号\n");
    int id;
    scanf("%d", &id);
    node *p = head;
    node *q = NULL;
    while (p != NULL) {
        if (p->student.id == id) {
            if (q == NULL) {
                head = p->next;
            } else {
                q->next = p->next;
            }
            free(p);
            printf("删除成功\n");
            return;
        }
        q = p;
        p = p->next;
    }
    printf("没有找到该学生\n");
}

//按照姓名删除学生信息
void deleteByName() {
    printf("请输入要删除的学生姓名\n");
    char name[20];
    scanf("%s", name);
    node *p = head;
    node *q = NULL;
    while (p != NULL) {
        if (strcmp(p->student.name, name) == 0) {
            if (q == NULL) {
                head = p->next;
            } else {
                q->next = p->next;
            }
            free(p);
            printf("删除成功\n");
            return;
        }
        q = p;
        p = p->next;
    }
    printf("没有找到该学生\n");
}

//按照总成绩排序
void sortBySumScore() {
    node *p = head;
    node *q = NULL;
    while (p != NULL) {
        q = p->next;
        while (q != NULL) {
            if (p->student.chinese + p->student.math + p->student.english <
                q->student.chinese + q->student.math + q->student.english) {
                student temp = p->student;
                p->student = q->student;
                q->student = temp;
            }
            q = q->next;
        }
        p = p->next;
    }
    printAllStudent();
}

//显示所有学生信息
void printAllStudent() {
    printf("姓名\t学号\t班级\t专业\t语文成绩\t数学成绩\t英语成绩\t总成绩\n");
    node *p = head;
    while (p != NULL) {
        printf("%s    ", p->student.name);
        printf("%d    ", p->student.id);
        printf("%s    ", p->student.className);
        printf("%s    ", p->student.major);
        printf("%d    ", p->student.chinese);
        printf("%d    ", p->student.math);
        printf("%d    ", p->student.english);
        printf("%d    \n", p->student.chinese + p->student.math + p->student.english);
        p = p->next;
    }
}

//汇总每个同学的总成绩，并按照总成绩排序，显示排序结果
void summary() {
    sortBySumScore();
}

//统计平均成绩和平均分
void countAverage() {
    double averageChinese = 0;
    double averageMath = 0;
    double averageEnglish = 0;
    double averageSum = 0;
    int count = 0;
    node *p = head;
    while (p != NULL) {
        averageChinese += p->student.chinese;
        averageMath += p->student.math;
        averageEnglish += p->student.english;
        averageSum += p->student.chinese + p->student.math + p->student.english;
        count++;
        p = p->next;
    }
    printf("平均语文成绩：%f\n", averageChinese / count);
    printf("平均数学成绩：%f\n", averageMath / count);
    printf("平均英语成绩：%f\n", averageEnglish / count);
    printf("平均总成绩：%f\n", averageSum / count);
    printf("总人数：%d\n", count);
}

