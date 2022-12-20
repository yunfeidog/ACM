#include "stdio.h"
#include "string.h"
#include "stdlib.h"

//需要用二维数组保存学生信息
//学生信息包括：学号、宿舍号，qq，微信，电话
int students[100][5];
int len = 0;

//添加学生信息,需要用指针
void add() {
    int *p = students[len];
    printf("请输入学生信息：学号、宿舍号，qq，微信，电话\n");
    scanf("%d %d %d %d %d", p, p + 1, p + 2, p + 3, p + 4);
    len++;
    printf("添加成功\n");
}
//用指针删除学生信息
void delete() {
    printf("请输入要删除的学生学号：");
    int id;
    scanf("%d", &id);
    int i;
    for (i = 0; i < len; i++) {
        if (students[i][0] == id) {
            break;
        }
    }
    if (i == len) {
        printf("没有找到学号为%d的学生\n", id);
        return;
    }
    for (int j = i; j < len - 1; j++) {
        students[j][0] = students[j + 1][0];
        students[j][1] = students[j + 1][1];
        students[j][2] = students[j + 1][2];
        students[j][3] = students[j + 1][3];
        students[j][4] = students[j + 1][4];
    }
    len--;
    printf("删除成功\n");
}
//用指针查询学生信息
void query() {
    printf("请输入要查询的学生学号：");
    int id;
    scanf("%d", &id);
    int i;
    for (i = 0; i < len; i++) {
        if (students[i][0] == id) {
            break;
        }
    }
    if (i == len) {
        printf("没有找到学号为%d的学生\n", id);
        return;
    }
    printf("学号：%d\n", students[i][0]);
    printf("宿舍号：%d\n", students[i][1]);
    printf("qq：%d\n", students[i][2]);
    printf("微信：%d\n", students[i][3]);
    printf("电话：%d\n", students[i][4]);
}

//用指针修改学生信息
void update() {
    printf("请输入要修改的学生学号：");
    int id;
    scanf("%d", &id);
    int i;
    for (i = 0; i < len; i++) {
        if (students[i][0] == id) {
            break;
        }
    }
    if (i == len) {
        printf("没有找到学号为%d的学生\n", id);
        return;
    }
    printf("请输入学生信息：学号、宿舍号，qq，微信，电话\n");
    scanf("%d %d %d %d %d", &students[i][0], &students[i][1], &students[i][2], &students[i][3], &students[i][4]);
    printf("修改成功\n");
}

//用指针显示所有学生信息
void show() {
    printf("学号\t宿舍号\tqq\t微信\t电话\n");
    for (int i = 0; i < len; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", students[i][0], students[i][1], students[i][2], students[i][3], students[i][4]);
    }
}

//用指针排序学生信息
void sort() {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            if (students[j][0] > students[j + 1][0]) {
                int temp = students[j][0];
                students[j][0] = students[j + 1][0];
                students[j + 1][0] = temp;
                temp = students[j][1];
                students[j][1] = students[j + 1][1];
                students[j + 1][1] = temp;
                temp = students[j][2];
                students[j][2] = students[j + 1][2];
                students[j + 1][2] = temp;
                temp = students[j][3];
                students[j][3] = students[j + 1][3];
                students[j + 1][3] = temp;
                temp = students[j][4];
                students[j][4] = students[j + 1][4];
                students[j + 1][4] = temp;
            }
        }
    }
    printf("排序成功\n");
    show();
}

//初始化五个学生信息
void init(){
    students[0][0]=1;
    students[0][1]=310;
    students[0][2]=123456;
    students[0][3]=123432;
    students[0][4]=123456789;
    students[1][5]=110;

    students[1][0]=2;
    students[1][1]=311;
    students[1][2]=123456;
    students[1][3]=123432;
    students[1][4]=123456789;
    students[1][5]=110;

    students[2][0]=3;
    students[2][1]=312;
    students[2][2]=123456;
    students[2][3]=123432;
    students[2][4]=123456789;
    students[2][5]=110;

    students[3][0]=4;
    students[3][1]=313;
    students[3][2]=123456;
    students[3][3]=123432;
    students[3][4]=123456789;
    students[3][5]=110;

    students[4][0]=5;
    students[4][1]=314;
    students[4][2]=123456;
    students[4][3]=123432;
    students[4][4]=123456789;
    students[4][5]=110;
    len=5;

}



int main() {
    init();
    printf("欢迎使用学生管理系统\n");
    while (1) {
        printf("1---添加学生信息\n");
        printf("2---删除学生信息\n");
        printf("3---查询学生信息\n");
        printf("4---按学号排序\n");
        printf("5---修改学生信息\n");
        printf("6---退出\n");
        printf("请输入你的选择：");
        int code;
        scanf("%d", &code);
        switch (code) {
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
                sort();
                break;
            case 5:
                update();
                break;
            case 6:
                printf("退出成功\n");
                break;
            default:
                printf("输入有误，请重新输入\n");
                break;

        }
    }



    return 0;
}
