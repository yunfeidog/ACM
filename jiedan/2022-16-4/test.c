#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "conio.h"

#define N 1100

typedef struct worker
{
    char name[20];
    int bianhao;
    char sex[10];
    int nianling;
    char xueli[10];
    char zhicheng[10];
    char gongzhong[10];
} worker;



void input()       /*信息录入函数*/
{
    FILE *fp;        /*定义文件*/
    worker xs;
    if ((fp = fopen("worker.txt", "ab")) == NULL)
    {
        printf("can't open file!\n");
        exit(0);
    }  /*打开文件，如果不能打开，就关闭所有文件*/
    printf("\n录入格式 姓名 编号　性别　年龄 学历 职称 工种。当输入姓名为end结束录入\n");
    while (1)
    {
        scanf("%s", xs.name);
        if (strcmp(xs.name, "end") == 0) break;    /*如果输入的是end,则停止输入*/
        scanf("%d%s%d%s%s%s", &xs.bianhao, xs.sex, &xs.nianling, xs.xueli, xs.zhicheng, xs.gongzhong);
        fwrite(&xs, sizeof(worker), 1, fp); /*将信息写入文件*/
    }
    fclose(fp);   /*关闭文件*/
}


void print()     /*职工信息浏览函数*/
{
    FILE *fp;
    worker s;     /*定义结构体变量*/
    system("cls");     /*清屏*/
    if ((fp = fopen("worker.txt", "rb")) == NULL)
    {
        printf("can't open file!\n");
        exit(0);
    }
    printf("\n%10s %5s %2s %2s %5s %5s %5s\n", "姓名", "编号", "性别", "年龄", "学历", "职称", "工种");
    while (!feof(fp))
    {
        fread(&s, sizeof(worker), 1, fp);/*从文件中读取职工信息*/
        if (feof(fp)) break;/*判断是否文件尾*/
        printf("%10s %5d %5s %5d %5s %5s %5s\n", s.name, s.bianhao, s.sex, s.nianling, s.xueli, s.zhicheng,
               s.gongzhong);

    }
    fclose(fp); /*关闭文件*/
    getch();   /*停止运行，便于观察结果*/
}

void seekxueli()     /*学历查找函数*/
{
    worker xs[N];/*定义一个结构体一维数组*/
    FILE *fp;
    char xueli[10];
    int i, k;
    system("cls");
    printf("\n请输入要查找的学历: ");
    scanf("%s", xueli);
    i = 0;
    if ((fp = fopen("worker.txt", "r")) == NULL) /*为输入打开一个已存在的文本文件*/
    {
        printf("can't open file!\n");
        exit(0);
    }
    while (!feof(fp))
    {
        fread(&xs[i], sizeof(worker), 1, fp); /*从文件中读取职工信息*/
        if (feof(fp)) break;/*判断是否文件尾*/
        if (strcmp(xs[i].xueli, xueli) == 0)/*如果数组中有和输入相同的学历，则找到它在数组中的位置,并输出*/
        {
            k = i;
            printf("\n%10s %5s %2s %2s %5s %5s %5s\n", "姓名", "编号", "性别", "年龄", "学历", "职称", "工种");
            printf("%10s %5d %5s %5d %5s %5s %5s\n", xs[k].name, xs[k].bianhao, xs[k].sex, xs[k].nianling, xs[k].xueli,
                   xs[k].zhicheng, xs[k].gongzhong);
        }
    }
    getch();
}

void seekname()   /*姓名查找函数*/
{
    worker xs[N];   /*定义一个结构体一维数组*/
    FILE *fp;
    char name[10];
    int i, k;
    system("cls");
    printf("\n请输入要查找的职工姓名: ");
    scanf("%s", name);
    i = 0;
    if ((fp = fopen("worker.txt", "r")) == NULL)   /*为输入打开一个已存在的文本文件*/
    {
        printf("can't open file!\n");
        exit(0);
    }
    while (!feof(fp))
    {
        fread(&xs[i], sizeof(worker), 1, fp);   /*从文件中读取职工信息*/
        if (feof(fp)) break;/*判断是否文件尾*/
        if (strcmp(xs[i].name, name) == 0) k = i;/*如果数组中有和输入相同的名字，则找到它在数组中的位置*/
    }
    printf("\n%10s %5s %2s %2s %5s %5s %5s\n", "姓名", "编号", "性别", "年龄", "学历", "职称", "工种");
    printf("%10s %5d %5s %5d %5s %5s %5s\n", xs[k].name, xs[k].bianhao, xs[k].sex, xs[k].nianling, xs[k].xueli,
           xs[k].zhicheng, xs[k].gongzhong);
    getch();  /*停止运行，便于观察结果*/
}

void dele()     /*删除函数*/
{
    worker xs[N];  /*定义一个结构体一维数组*/
    FILE *fp;      /*定义文件*/
    char name[10];
    int i, j, k = 0;
    system("cls");
    printf("\n请输入要删除的职工姓名: ");
    scanf("%s", name);
    i = 0;
    if ((fp = fopen("worker.txt", "a+")) == NULL)   /*为读写打开一个文本文件*/
    {
        printf("can't open file!\n");
        exit(0);
    }
    while (!feof(fp))
    {
        fread(&xs[i], sizeof(worker), 1, fp);    /*从文件中读取职工信息*/
        if (feof(fp)) break;
        if (strcmp(xs[i].name, name) == 0) k = i;   /*如果数组中有和输入相同的名字，则准备执行删除*/
        i++;
    }
    fclose(fp);   /*关闭文件*/
//以下是删除后职工信息
    j = i;
    if (k >= 0)
    {
        if ((fp = fopen("worker.txt", "w+")) == NULL)   /*为读写建立一个新的文本文件*/
        {
            printf("can't open file!\n");
            exit(0);
        }
        for (i = 0; i < j; i++)
        {
            if (i == k) continue;   /*执行删除功能*/
            fwrite(&xs[i], sizeof(worker), 1, fp);
        }
        fclose(fp);   /*关闭文件*/
    } else printf("删除失败!!!\n");
    print();   /*嵌套调用职工信息浏览函数*/
}


void paixu()  /*排序函数*/
{
    worker xs[N];/*定义一个结构体一维数组*/
    worker x;
    FILE *fp;
    int i, k, j;
    system("cls");
    i = 0;
    if ((fp = fopen("worker.txt", "a+")) == NULL)  /*为读写打开一个文本文件*/
    {
        printf("can't open file!\n");
        exit(0);
    }
    while (!feof(fp))
    {
        fread(&xs[i], sizeof(worker), 1, fp);/*从文件中读取职工信息*/
        if (feof(fp)) break;
        i++;
    }
    fclose(fp);
    k = i;
    for (i = 0; i <= k - 1; i++)
        for (j = 0; j < k - i - 1; j++)
        {
            if (xs[j].nianling > xs[j + 1].nianling)
            {
                x = xs[j];
                xs[j] = xs[j + 1];
                xs[j + 1] = x;
            }   /*冒泡法排序*/
        }
    printf("\n%10s %5s %2s %2s %5s %5s %5s\n", "姓名", "编号", "性别", "年龄", "学历", "职称", "工种");
    for (i = 0; i <= k - 1; i++)
        printf("%10s %5d %5s %5d %5s %5s %5s\n", xs[i].name, xs[i].bianhao, xs[i].sex, xs[i].nianling, xs[i].xueli,
               xs[i].zhicheng, xs[i].gongzhong);

    getch();  /*停止运行，便于观察结果*/
}


int main()
{
    printf("欢迎进入职工管理系统\n");
    printf("============================\n");
    printf("1.职工信息浏览\n");
    printf("2.职工信息删除\n");
    printf("3.职工信息录入\n");
    printf("4.姓名查询\n");
    printf("5.学历查询\n");
    printf("6.排序（按年龄排序由小到大）\n");
    printf("0.退出\n");
    printf("============================\n");
    while (1)
    {
        printf("请选择相应的功能：");
        int n;
        scanf("%d", &n);
        switch (n)
        {
            case 1:
                print();
                break;
            case 2:
                dele();
                break;
            case 3:
                input();
                break;
            case 4:
                seekname();
                break;
            case 5:
                seekxueli();
                break;
            case 6:
                paixu();
                break;
            case 0:
                exit(0);
            default:
                printf("输入错误，请重新输入\n");
                break;
        }
    }

    return 0;
}
