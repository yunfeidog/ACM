#include<stdio.h>
#include<string.h>

int shu(char a[])
{
    int f = 0;
    char *p = a;
    while ((*p) != '\0')
    {
        f += *p - 'a';
        p++;
    }
    f = f % 51;
    return f;
}//哈希函数
typedef struct node
{
    char b[30];
} node, node1[52];//哈希表
int main()
{
    int h0, i;
    node1 b;
    char a[30];
    for (i = 0; i < 52; i++)
        strcpy(b[i].b, "  ");
    while (i)
    {
        printf("请输入学生姓名:");
        scanf("%s", a);
        h0 = shu(a);
        if (strcmp(b[h0].b, "  ") == 0)
            strcpy(b[h0].b, a);
        else
        {
            while (strcmp(b[h0].b, "  ") != 0)
                h0 = (h0 + 1) % 52;
            strcpy(b[h0].b, a);
        }
        printf("继续输入按1否则按0:");
        scanf("%d", &i);
    }//输入人名建立哈希表
    i = 1;
    while (i)
    {
        printf("输入查找学生姓名:");
        scanf("%s", a);
        h0 = shu(a);
        if (strcmp(b[h0].b, a) == 0)
            printf("该学生是%s\n", a);
        else
        {
            while (strcmp(b[h0].b, "  ") != 0 && strcmp(b[h0].b, a) != 0)
                h0 = (h0 + 1) % 52;
            if (strcmp(b[h0].b, "  ") == 0)
                printf("没有该学生\n");
            else
                printf("该学生是%s\n", a);
        }
        printf("继续查找请按1，否则按0:");
        scanf("%d", &i);
    } //哈希表查找学生人名
}
