#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char shenfen[10];//身份
    char name[10];//姓名
    int id;//编号
    int telephone;//电话
    char id_card[18];//身份证
    int status;//0表示出校
    char time[10];// 例如 2022/01/01
} students[10000];

int len = 0;

char shenfen[10];
char name[10];
int id;
int telephone;
char id_card[18];
int status;
char time[10];

int cmp1(const void *s1, const void *s2) {
    struct student a = *(struct student *) s1;
    struct student b = *(struct student *) s2;

    return strcmp(a.time, b.time) < 0;
}


int cmp2(const void *s1, const void *s2) {
    struct student a = *(struct student *) s1;
    struct student b = *(struct student *) s2;

    return strcmp(a.time, b.time) > 0;
}


void luru();
//学生 张三 7220221 13188885752 110341199702027521 0 2022/10/06
//学生 李四 7220222 13188885733 110341199702027771 0 2022/10/05
//

void save();

void showAll(struct student students[]);

void query();

void add();

void delete();

void update();

void count();

void sort();

void showone(struct student s);

int main() {
    printf("***************欢迎使用校园出入管理系统***************\n");
    printf("---------------------------------------------------\n");
    printf("---------------1.录入出入校园人员信息----------------\n");
    printf("---------------2.保存出入校园人员信息----------------\n");
    printf("---------------3.浏览出入校园人员信息----------------\n");
    printf("---------------4.查询出入校园人员信息----------------\n");
    printf("---------------5.增加出入校园人员信息----------------\n");
    printf("---------------6.删除出入校园人员信息----------------\n");
    printf("---------------7.修改出入校园人员信息----------------\n");
    printf("---------------8.统计出入校园人员信息----------------\n");
    printf("---------------9.对出入校园人员信息进行排序-----------\n");
    printf("---------------10.退出-----------------------------\n");
    printf("**************************************************\n");

    while (1) {
        printf("请选择(1-10)：");
        int op;
        scanf("%d", &op);
        switch (op) {
            case 1:
                luru();
                break;
            case 2:
                save();
                break;
            case 3:
                showAll(students);
                break;
            case 4:
                query();
                break;
            case 5:
                add();
                break;
            case 6:
                delete();
                break;
            case 7:
                update();
                break;
            case 8:
                count();
                break;
            case 9:
                sort();
                break;
            case 10:
                printf("退出系统\n");
                return 0;
        }
    }
}


//1.录入
void luru() {
    printf("请输入录入人员个数：");
    int n;
    scanf("%d", &n);
    printf("请依次输入身份、姓名、编号、联系方式、身份证号、出/入校、出/入校时间\n");
    while (n--) {
        scanf("%s %s %d %d %s %d %s", students[len].shenfen, students[len].name, &students[len].id,
              &students[len].telephone, students[len].id_card, &students[len].status, students[len].time);
        len++;
    }
    printf("录入数据成功\n");
}

//2.保存
void save() {
    FILE *fp = fopen("information.txt", "w");
    for (int i = 0; i < len; ++i) {
        fprintf(fp, "%s  %s  %d  %d  %s  %d  %s",
                students[i].shenfen,
                students[i].name,
                students[i].id,
                students[i].telephone,
                students[i].id_card,
                students[i].status,
                students[i].time);
        fprintf(fp, "\n");
    }
    fclose(fp);

    printf("保存数据成功!\n");
}

//3.浏览出入信息
void showAll(struct student students[]) {
    printf("身份  姓名    编号    联系方式    身份证号         出/入校    出/入校时间  \n");
    for (int i = 0; i < len; ++i) {
        printf("%s  ", students[i].shenfen);
        printf("%s  ", students[i].name);
        printf("%d  ", students[i].id);
        printf("%d  ", students[i].telephone);
        printf("%s  ", students[i].id_card);
        printf("%d  ", students[i].status);
        printf("%s  \n", students[i].time);
    }
}

void showone(struct student s) {
    printf("%s  ", s.shenfen);
    printf("%s  ", s.name);
    printf("%d  ", s.id);
    printf("%d  ", s.telephone);
    printf("%s  ", s.id_card);
    printf("%d  ", s.status);
    printf("%s  \n", s.time);
}

//4.查询出入
void query() {
    printf("1.按人员身份查询\n");
    printf("2.按姓名查询\n");
    printf("3.按出/入校查询\n");
    printf("4.退出\n");
    printf("请选择(1-4):");
    int op;
    scanf("%d", &op);
    switch (op) {
        case 1:
            printf("请输入查询身份：");
            scanf("%s", shenfen);
            for (int i = 0; i < len; i++) {
                if (strcmp(students[i].shenfen, shenfen) == 0) {
                    showone(students[i]);
                }
            }
            break;
        case 2:
            printf("请输入查询姓名：");
            scanf("%s", name);
            for (int i = 0; i < len; i++) {
                if (strcmp(students[i].name, name) == 0) {
                    showone(students[i]);
                    break;
                }
            }
            break;
        case 3:
            printf("请输入查询出/入校：");
            scanf("%d", &status);
            for (int i = 0; i < len; i++) {
                if (students[i].status == status) {
                    showone(students[i]);
                }
            }
            break;
        case 4:
            printf("退出查询\n");
            break;
    }
}

//5.增加人员
void add() {
    printf("请依次输入身份、姓名、编号、联系方式、身份证号、出/入校、出/入校时间\n");
    scanf("%s %s %d %d %s %d %s", students[len].shenfen, students[len].name, &students[len].id,
          &students[len].telephone, students[len].id_card, &students[len].status, students[len].time);
    len++;
    printf("添加成功\n");
    save();
}

//6.删除
void delete() {
    printf("输入姓名、身份证号、出/入校、出/入校时间：\n");
    scanf("%s %s %d %s", name, id_card, &status, time);
//    printf("%s",name);
    for (int i = 0; i < len; ++i) {
//        printf("%s\n",students[i].name);
        if (strcmp(students[i].name, name) == 0) {
            showone(students[i]);
            printf("是否删除该数据y/n?:");
            getchar();
            char op;
            scanf("%c", &op);
            if (op == 'y' || op == 'Y') {
                for (int j = i + 1; j < len; j++) {
                    students[j - 1] = students[j];
                }
                len--;
                printf("删除成功！");
            } else {
                printf("取消删除！");
            }
            break;
        }
    }
    save();
}

//7.修改信息
void update() {
    printf("输入姓名、身份证号、出/入校、出/入校时间：\n");
    scanf("%s %s %d %s", name, id_card, &status, time);
    int cur = 0;
    for (int i = 0; i < len; i++) {
        if (strcmp(students[i].name, name) == 0) {
            cur = i;
            break;
        }
    }
    showone(students[cur]);
    printf("是否修改该数据y/n?:");
    getchar();
    char op;
    scanf("%c", &op);
    if (op == 'y' || op == 'Y') {
        printf("修改哪项数据(0-6):");
        int n;
        scanf("%d", &n);
        printf("输入修改信息：");
        if (n == 1) {
            scanf("%s", students[cur].shenfen);
        } else if (n == 2) {
            scanf("%s", students[cur].name);
        } else if (n == 3) {
            scanf("%d", &students[cur].id);
        } else if (n == 4) {
            scanf("%d", &students[cur].telephone);
        } else if (n == 5) {
            scanf("%s", students[cur].id_card);
        } else if (n == 6) {
            scanf("%d", &students[cur].status);
        } else {
            scanf("%s", students[cur].time);
        }
        printf("修改成功！");
    } else {
        printf("取消修改！");
    }
    save();
}

//8.统计出入信息
void count() {
    printf("A.统计当天出校人员总数\n");
    printf("B.统计当天入校人员总数\n");
    printf("C.统计所有时间段出校人员总数\n");
    printf("D.统计所有时间段入校人员总数\n");
    printf("E.退出\n");
    printf("请选择(A-E):");
    getchar();
    char op;
    scanf("%c", &op);
    if (op == 'A') {
        int cnt = 0;
        int cnt1 = 0;//学生
        int cnt2 = 0;//教职工
        int cnt3 = 0;//其他
        char time1[10];
        printf("请输入当天日期：");
        scanf("%s", time1);
        for (int i = 0; i < len; ++i) {
            if (strcmp(students[i].time, time1) == 0 && students[i].status == 0) {
                cnt++;
                if (strcmp(students[i].shenfen, "学生") == 0) cnt1++;
                else if (strcmp(students[i].shenfen, "教职工") == 0) cnt2++;
                else cnt3++;
            }
        }
        printf("当天出校总人数为：%d人,学生%d人,教职工%d人,其他%d人\n", cnt, cnt1, cnt2, cnt3);
        for (int i = 0; i < len; ++i) {
            if (strcmp(students[i].time, time1) == 0 && students[i].status == 0) {
                showone(students[i]);
            }
        }
    } else if (op == 'B') {
        int cnt = 0;
        int cnt1 = 0;//学生
        int cnt2 = 0;//教职工
        int cnt3 = 0;//其他
        char time1[10];
        printf("请输入当天日期：");
        scanf("%s", time1);
        for (int i = 0; i < len; ++i) {
            if (strcmp(students[i].time, time1) == 0 && students[i].status == 1) {
                cnt++;
                if (strcmp(students[i].shenfen, "学生") == 0) cnt1++;
                else if (strcmp(students[i].shenfen, "教职工") == 0) cnt2++;
                else cnt3++;
            }
        }
        printf("当天入校总人数为：%d人,学生%d人,教职工%d人,其他%d人\n", cnt, cnt1, cnt2, cnt3);
        for (int i = 0; i < len; ++i) {
            if (strcmp(students[i].time, time1) == 0 && students[i].status == 1) {
                showone(students[i]);
            }
        }
    } else if (op == 'C') {
        int cnt = 0;
        int cnt1 = 0;//学生
        int cnt2 = 0;//教职工
        int cnt3 = 0;//其他
        for (int i = 0; i < len; ++i) {
            if (students[i].status == 1) {
                cnt++;
                if (strcmp(students[i].shenfen, "学生") == 0) cnt1++;
                else if (strcmp(students[i].shenfen, "教职工") == 0) cnt2++;
                else cnt3++;
            }
        }
        printf("当天入校总人数为：%d人,学生%d人,教职工%d人,其他%d人\n", cnt, cnt1, cnt2, cnt3);
        for (int i = 0; i < len; ++i) {
            if (students[i].status == 1) {
                showone(students[i]);
            }
        }
    } else if (op == 'D') {
        int cnt = 0;
        int cnt1 = 0;//学生
        int cnt2 = 0;//教职工
        int cnt3 = 0;//其他
        for (int i = 0; i < len; ++i) {
            if (students[i].status == 0) {
                cnt++;
                if (strcmp(students[i].shenfen, "学生") == 0) cnt1++;
                else if (strcmp(students[i].shenfen, "教职工") == 0) cnt2++;
                else cnt3++;
            }
        }
        printf("当天出校总人数为：%d人,学生%d人,教职工%d人,其他%d人\n", cnt, cnt1, cnt2, cnt3);
        for (int i = 0; i < len; ++i) {
            if (students[i].status == 0) {
                showone(students[i]);
            }
        }
    } else if (op == 'E') {
        printf("退出\n");
    }
}

//9.排序
void sort() {
    printf("A.对出校人员按出校时间进行降序排序\n");
    printf("B.对入校人员按入校时间进行升序排序\n");
    printf("请选择(A-B):");
    getchar();
    char op;
    scanf("%c", &op);
    if (op == 'A') {
        qsort(students, len, sizeof students[0], cmp1);
        for (int i = 0; i < len; ++i) {
            if (students[i].status == 1) continue;
            showone(students[i]);
        }
    } else if (op == 'C') {
        printf("退出");
        return;
    } else {
        qsort(students, len, sizeof students[0], cmp2);
        for (int i = 0; i < len; ++i) {
            if (students[i].status == 0) continue;
            showone(students[i]);
        }
    }
}
