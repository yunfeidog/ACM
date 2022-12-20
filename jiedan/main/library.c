#include "stdio.h"
#include "string.h"

/**
 * 书籍信息
 */
struct Book
{
    char id[100];
    char name[100];
    char author[100];
    char publisher[100];

} books[10010];
/**
 * 书的数量
 */
int len = 0;

/**
 * 添加书籍
 */
void addBook();

/**
 * 显示书籍
 */
void showBook();

/**
 * 按作者查找书籍
 */
void queryBookByAuthor();

/**
 * 按出版社查找书籍
 */
void queryBookByPublisher();

/**
 * 删除书籍
 */
void deleteBook();

/**
 * 统计书籍
 */
void statistics();

int main()
{
    printf("欢迎使用图书管理系统\n");
    printf("1.添加图书\n");
    printf("2.显示图书信息\n");
    printf("3.查询作者图书\n");
    printf("4.查询出版社图书\n");
    printf("5.删除图书\n");
    printf("6.统计信息\n");
    printf("7.退出\n");
    while (1)
    {
        printf("请输入你的选择:\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 1)
        {
            addBook();
        } else if (choice == 2)
        {
            showBook();
        } else if (choice == 3)
        {
            queryBookByAuthor();
        } else if (choice == 4)
        {
            queryBookByPublisher();
        } else if (choice == 5)
        {
            deleteBook();
        } else if (choice == 6)
        {
            statistics();
        } else if (choice == 7)
        {
            printf("退出\n");
            break;
        } else
        {
            printf("输入错误，请重新输入\n");
        }
    }
    return 0;
}

/**
 * 添加图书
 */
void addBook()
{
    printf("添加图书\n");
    printf("请输入图书编号:\n");
    scanf("%s", books[len].id);
    printf("请输入图书名称:\n");
    scanf("%s", books[len].name);
    printf("请输入图书作者:\n");
    scanf("%s", books[len].author);
    printf("请输入图书出版社:\n");
    scanf("%s", books[len].publisher);
    //查询图书是否存在，如果存在，提示图书已存在，不需要添加
    for (int i = 0; i < len; ++i)
    {
        if (strcmp(books[i].id, books[len].id) == 0)
        {
            printf("图书已存在，不需要添加\n");
            return;
        }
    }
    len++;
    printf("添加成功\n");

}

/**
 * 显示图书信息
 */
void showBook()
{
    printf("显示图书信息\n");
    printf("请输入图书编号:\n");
    char id[100];
    scanf("%s", id);
    for (int i = 0; i < len; ++i)
    {
        if (strcmp(books[i].id, id) == 0)
        {
            printf("图书编号:%s\n", books[i].id);
            printf("图书名称:%s\n", books[i].name);
            printf("图书作者:%s\n", books[i].author);
            printf("图书出版社:%s\n", books[i].publisher);
            return;
        }
    }
}

/**
 * 根据作者查询图书
 */
void queryBookByAuthor()
{
    printf("查询作者图书\n");
    printf("请输入作者名称:\n");
    char author[100];
    scanf("%s", author);
    for (int i = 0; i < len; ++i)
    {
        if (strcmp(author, books[i].author) == 0)
        {
            printf("图书编号:%s\n", books[i].id);
            printf("图书名称:%s\n", books[i].name);
            printf("图书作者:%s\n", books[i].author);
            printf("图书出版社:%s\n", books[i].publisher);
        }
    }
}

/**
 * 查询出版社图书
 */
void queryBookByPublisher()
{
    printf("查询出版社图书\n");
    printf("请输入出版社名称:\n");
    char publisher[100];
    scanf("%s", publisher);
    printf("该出版社的图书有:\n");
    for (int i = 0; i < len; ++i)
    {
        if (strcmp(publisher, books[i].publisher) == 0)
        {
            printf("图书编号:%s\n", books[i].id);
            printf("图书名称:%s\n", books[i].name);
            printf("图书作者:%s\n", books[i].author);
            printf("图书出版社:%s\n", books[i].publisher);
        }
    }
}

/**
 * 删除图书
 */
void deleteBook()
{
    printf("删除图书\n");
    printf("请输入图书编号:\n");
    char id[100];
    scanf("%s", id);
    //判断是否存在
    int index = -1;
    for (int i = 0; i < len; ++i)
    {
        if (strcmp(books[i].id, id) == 0)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        printf("图书不存在，无法删除\n");
        return;
    }
    //删除
    for (int i = index; i < len - 1; ++i)
    {
        books[i] = books[i + 1];
    }
    len--;
    printf("删除成功\n");
}


/**
 * 统计信息
 */
void statistics()
{
    printf("统计图书信息\n");
    //统计共有多少书
    printf("共有%d本书\n", len);
    //统计共有多少个出版社
    int count = 0;
    for (int i = 0; i < len; ++i)
    {
        int flag = 1;
        for (int j = 0; j < i; ++j)
        {
            if (strcmp(books[i].publisher, books[j].publisher) == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            count++;
        }
    }
    printf("共有%d个出版社\n", count);
    //统计每个出版社的图书数量
    for (int i = 0; i < len; ++i)
    {
        int flag = 1;
        for (int j = 0; j < i; ++j)
        {
            if (strcmp(books[i].publisher, books[j].publisher) == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            int count = 0;
            for (int j = 0; j < len; ++j)
            {
                if (strcmp(books[i].publisher, books[j].publisher) == 0)
                {
                    count++;
                }
            }
            printf("%s出版社共有%d本图书\n", books[i].publisher, count);
        }
    }

    //统计作者的数量
    count = 0;
    for (int i = 0; i < len; ++i)
    {
        int flag = 1;
        for (int j = 0; j < i; ++j)
        {
            if (strcmp(books[i].author, books[j].author) == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            count++;
        }
    }
    printf("共有%d个作者\n", count);
    //统计每个作者的图书数量
    for (int i = 0; i < len; ++i)
    {
        int flag = 1;
        for (int j = 0; j < i; ++j)
        {
            if (strcmp(books[i].author, books[j].author) == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            int count = 0;
            for (int j = 0; j < len; ++j)
            {
                if (strcmp(books[i].author, books[j].author) == 0)
                {
                    count++;
                }
            }
            printf("%s作者共有%d本图书\n", books[i].author, count);
        }
    }
}

