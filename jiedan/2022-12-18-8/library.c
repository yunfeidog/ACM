#include "stdio.h"
#include "string.h"
#include "stdlib.h"

struct book{
    char id[100];
    char name[100];
    char author[100];
    char fenlei[100];
    char date[100];
    char publisher[100];
    double price;
}books[100];

int len = 0;

void add();//添加图书

void show();//显示图书信息

void queryByName();//查询图书信息

void queryByAuthor();//查询图书信息

void menu();//菜单

void saveToFile();//保存到文件

int main() {
    while (1)menu();

    return 0;
}

void menu(){
    printf("欢迎使用图书管理系统\n");
    printf("1.添加图书\n");
    printf("2.显示图书信息\n");
    printf("3.按书名查询图书信息\n");
    printf("4.按作者查询图书信息\n");
    printf("5.退出\n");
    printf("请输入你的选择：");

    int n;
    scanf("%d",&n);
    if(n==1)add();
    else if(n==2)show();
    else if(n==3)queryByName();
    else if(n==4)queryByAuthor();
    else if(n==5){
        printf("退出系统\n");
        saveToFile();
        exit(0);
    }
}

void saveToFile(){
    FILE *fp = fopen("books.txt","w");
    for (int i = 0; i < len; ++i) {
        fprintf(fp,"%s %s %s %s %s %s %lf\n",books[i].id,books[i].name,books[i].author,books[i].fenlei,books[i].date,books[i].publisher,books[i].price);
    }
    fclose(fp);
}

void add(){
    printf("请依次输入登录号、书名、作者、分类、出版日期、出版社、价格\n");
    scanf("%s%s%s%s%s%s%lf", books[len].id, books[len].name, books[len].author, books[len].fenlei, books[len].date, books[len].publisher, &books[len].price);
    len++;
    printf("添加成功\n");
}

void show(){
    printf("登录号\t书名\t作者\t分类\t出版日期\t出版社\t价格\n");
    for (int i = 0; i < len; i++) {
        printf("%s\t%s\t%s\t%s\t%s\t%s\t%lf\n", books[i].id, books[i].name, books[i].author, books[i].fenlei, books[i].date, books[i].publisher, books[i].price);
    }
}

void queryByName(){
    printf("请输入要查询的书名：\n");
    char name[100];
    scanf("%s", name);
    int flag = 0;
    for (int i = 0; i < len; i++) {
        if (strcmp(books[i].name, name) == 0) {
            printf("登录号\t书名\t作者\t分类\t出版日期\t出版社\t价格\n");
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%lf\n", books[i].id, books[i].name, books[i].author, books[i].fenlei, books[i].date, books[i].publisher, books[i].price);
            flag = 1;
        }
    }
    if (flag == 0) {
        printf("没有找到该书\n");
    }
}

void queryByAuthor(){
    printf("请输入要查询的作者：\n");
    char author[100];
    scanf("%s", author);
    int flag = 0;
    for (int i = 0; i < len; i++) {
        if (strcmp(books[i].author, author) == 0) {
            printf("登录号\t书名\t作者\t分类\t出版日期\t出版社\t价格\n");
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%lf\n", books[i].id, books[i].name, books[i].author, books[i].fenlei, books[i].date, books[i].publisher, books[i].price);
            flag = 1;
        }
    }
    if (flag == 0) {
        printf("没有找到该作者\n");
    }
}