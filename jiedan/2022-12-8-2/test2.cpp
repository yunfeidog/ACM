#include "bits/stdc++.h"

using namespace std;
const int N = 30;
const int M = 50;
struct name   //名字结构体
{
    char s[30];
    int v;   //ascll码值之和
} NAME[N];

struct hashs   //哈希表结构体
{
    char name[30];   //名字
    int key;   //关键字
    int sum;   //哈希表中含有的元素个数
} HASH[M];

void init()   //初始化
{
    int i, j, sum;
    for (i = 0; i < N; i++)
    {
        NAME[i].v = 0;
    }
    strcpy(NAME[0].s, "houhuiyu");//侯慧玉
    strcpy(NAME[1].s, "liutongxuan");//刘同轩
    strcpy(NAME[2].s, "liujiyuan");//刘继源
    strcpy(NAME[3].s, "wuzhe");//吴哲
    strcpy(NAME[4].s, "yaofanqi");//姚蕃淇
    strcpy(NAME[5].s, "sunchuwen");//孙楚旻
    strcpy(NAME[6].s, "songmingxue");//宋明雪
    strcpy(NAME[7].s, "zhangyongfei");//张勇飞
    strcpy(NAME[8].s, "zhangnanshuang");//张楠爽
    strcpy(NAME[9].s, "xumingyan");//徐明燕
    strcpy(NAME[10].s, "zengguangxun");//曾广巡
    strcpy(NAME[11].s, "liyong");//李勇
    strcpy(NAME[12].s, "liwenyao");//李文瑶
    strcpy(NAME[13].s, "lichenchuangyi");//李陈创一
    strcpy(NAME[14].s, "yangbinxu");//杨滨旭
    strcpy(NAME[15].s, "sangtianqi");//桑天奇
    strcpy(NAME[16].s, "lianghongting");//梁宏婷
    strcpy(NAME[17].s, "wangfuqiang");//王富强
    strcpy(NAME[18].s, "wanghongyuan");//王洪远
    strcpy(NAME[19].s, "wangtongshu");//王童姝
    strcpy(NAME[20].s, "wangpeng");//王鹏
    strcpy(NAME[21].s, "aizhanpeng"); //艾展鹏
    strcpy(NAME[22].s, "yuanyuan");//袁媛
    strcpy(NAME[23].s, "hexinlin");//贺薪霖
    strcpy(NAME[24].s, "xinghongxuan");//邢鸿轩
    strcpy(NAME[25].s, "guofanshu");//郭芃妤
    strcpy(NAME[26].s, "chenxuyan");//陈旭艳
    strcpy(NAME[27].s, "hanyutao");//韩玉涛
    strcpy(NAME[28].s, "lushiteng");//鹿世腾
    strcpy(NAME[29].s, "huangqichang");//黄启昌
    for (i = 0; i < N; i++)
    {
        sum = 0;
        for (j = 0; j < strlen(NAME[i].s); j++)
        {
            sum = sum + (NAME[i].s[j] - 'a');
        }
        NAME[i].v = sum;   //名字字母ascll码之和
    }
}

void creathash()    //构造哈希表
{
    int i;
    int n, m, counts;
    for (i = 0; i < M; i++)
    {
        strcpy(HASH[i].name, "0");
        HASH[i].key = 0;
        HASH[i].sum = 0;
    }
    for (i = 0; i < N; i++)
    {
        counts = 1;
        n = (NAME[i].v) % 47;
        m = n;
        if (HASH[n].sum == 0)   //不冲突
        {
            strcpy(HASH[n].name, NAME[i].s);
            HASH[n].key = NAME[i].v;
            HASH[n].sum = 1;
        } else   //如果发生了冲突
        {
            while (1)
            {
                m = (m + 1) % 47;
                counts++;
                if (HASH[m].key == 0)
                {
                    break;
                }
            }
            strcpy(HASH[m].name, NAME[i].s);
            HASH[m].key = NAME[i].v;
            HASH[m].sum = counts;
        }
    }
    return;
}

void searchhash()
{
    char name[30];
    int i, sum, n, m, counts;
    sum = 0;
    n = 0;
    counts = 1;
    printf("请输入要查找人的姓名拼音：\n");
    scanf("%s", name);
    for (i = 0; i < strlen(name); i++)
    {
        sum += (name[i] - 'a');
    }
    n = sum % 47;
    m = n;
    if (strcmp(HASH[n].name, name) == 0)
    {
        printf("姓名:%s 关键字:%d 查找长度:1\n", HASH[n].name, sum);
    } else if (HASH[n].sum == 0)
    {
        printf("没有找到这条记录！！！\n");
    } else
    {
        while (1)
        {
            m = (m + 1) % 47;
            counts++;
            if (strcmp(HASH[m].name, name) == 0)
            {
                printf("姓名:%s 关键字:%d 查找长度:%d\n", HASH[m].name, sum, counts);
                break;
            }
            if (HASH[m].key == 0)
            {
                printf("没有找到这条记录！！！\n");
                break;
            }
        }
    }
}

void displayhash()   //演示哈希表
{
    int i, sum;
    float ave;
    ave = 0.0;
    sum = 0;
    printf("\n地址\t关键字\t\t搜索长度\t姓名\n");
    for (i = 0; i < M; i++)
    {
        printf("%d", i);
        printf("\t%d", HASH[i].key);
        printf("\t\t%d", HASH[i].sum);
        printf("\t%s", HASH[i].name);
        printf("\n");
    }
    for (i = 0; i < M; i++)
    {
        sum += HASH[i].sum;
    }
    ave = ((sum) * 1.0) / N;
    printf("\n");
    printf("平均查找长度ASL(%d)=%.3lf\n", N, ave);
    return;
}

void display()
{
    int i;
    for (i = 0; i < 30; i++)
    {
        printf("\n\t关键字\t\t姓名\n");
        printf("\t%d", NAME[i].v);
        printf("\t%s", NAME[i].s);
    }
    return;
}

int menu()
{
    printf("\n\n");
    printf("\t汉字姓名拼音哈希表展示查找系统\n");
    printf("\t1.展示姓名拼音和关键字\n");
    printf("\t2.展示哈希表\n");
    printf("\t3.查找关键字\n");
    printf("\t4.退出\n");
    printf("\n");
    printf("\n");
    return 0;
}

int main()
{
    int n;
    int flag;
    flag = 1;
    while (1)
    {
        menu();

        if (flag == 1)
        {
            init();
            creathash();
            flag = 0;
        }
        scanf("%d", &n);
        getchar();
        if (n < 1 || n > 4)
        {
            printf("输入有误，请重新输入！！！\n");
            continue;
        } else
        {
            if (n == 1)
            {
                printf("展示所准备的姓名拼音及其所组成的关键字：\n");
                display();
            } else if (n == 2)
            {
                displayhash();
            } else if (n == 3)
            {
                searchhash();
            } else if (n == 4)
            {
                return 0;
            }
        }

    }
    return 0;
}
