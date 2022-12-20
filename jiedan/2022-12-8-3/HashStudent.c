#include "stdio.h"
#include "string.h"

char Name[72][20] = {"zhuwenbo", "liukaixing", "hukairui", "yechen", "aili", "zhan gzhenni", "chenzhilei", "anyuwei",
                     "lilongjie", "wanghaoran", "songliudi", "huqinyi", "zhangzelin", "zhangyuxuan", "hejiayun",
                     "shiran", "liaohuixianiilong", "xulihuan", "wangzhiyuan", "lixinrui", "caochenyuan", "caochenyuan",
                     "zhaoy", "liruijie", "jiayongqi", "chenxingyu", "wusiyuan", "zengyulin", "yuanhui", "wujiani",
                     "zhongyiging",
                     "hanyuxi", "wangruotong", "liudinghan", "xiayifan", "renyi", "zhangzirui", "chenyilin",
                     "jiangjiaruo",
                     "luobeier", "zhaoyutong", "jiaoyushu", "maike", "mengxiangfu", "liugingyang", "liangzichang",
                     "y uziqi", "tianxinyuan", "suzhiyuan", "shenyingtong", "huangpinzhang", "peiruimin", "che nzijia",
                     "cailuwei", "wuxinhong", "zengzhigeng", "kuangyimin", "changxinyu", "yangkun", "shengjiajun",
                     "lilong", "quxuan", "chenyugi", "meiting", "zhuchenxiao", "weitian", "chenjiahao", "jiyuxiang",
                     "xuxinyao", "make", "yeziling", "yangzhehan",};
const int N = 72;
const int M = 100;
const int H = 131;

int idx[200];

struct name {
    char s[20];
    int v;   //ascii码和
} NAME[72];

struct hashs   //哈希表
{
    char name[30];   //名字
    int key;   //关键字
    int sum;   //哈希表中含有的元素个数
} HASH[100];

void init() {
    int i, j, sum;
    for (i = 0; i < N; i++) {
        NAME[i].v = 0;
    }
    for (int i = 0; i < 72; i++) {
        strcpy(NAME[i].s, Name[i]);
    }
    for (i = 0; i < N; i++) {
        sum = 0;
        for (j = 0; j < strlen(NAME[i].s); j++) {
            sum = sum + (NAME[i].s[j] - 'a');
        }
        NAME[i].v = sum;   //名字字母ascll码之和
    }
}

void creathash()    //构造哈希表
{
    int i;
    int n, m, counts;
    for (i = 0; i < M; i++) {
        strcpy(HASH[i].name, "0");
        HASH[i].key = 0;
        HASH[i].sum = 0;
    }
    for (i = 0; i < N; i++) {
        counts = 1;
        n = (NAME[i].v) % H;
        m = n;
        if (HASH[n].sum == 0)   //不冲突
        {
            strcpy(HASH[n].name, NAME[i].s);
            HASH[n].key = NAME[i].v;
            HASH[n].sum = 1;
        } else   //如果发生了冲突
        {
            while (HASH[m].sum != 0) {
                m = (n + counts * counts) % H;
                counts++;
            }
            strcpy(HASH[m].name, NAME[i].s);
            HASH[m].key = NAME[i].v;
            HASH[m].sum = 1;
        }
    }
    return;
}

void searchhash() {
    char name[30];
    int i, sum, n, m, counts;
    sum = 0;
    n = 0;
    counts = 1;
    printf("请输入要查找人的姓名拼音：\n");
    scanf("%s", name);
    for (i = 0; i < strlen(name); i++) {
        sum += (name[i] - 'a');
    }
    n = sum % 131;
    m = n;
    if (strcmp(HASH[n].name, name) == 0) {
        printf("姓名:%s 关键字:%d 碰撞次数:1\n", HASH[n].name, sum);
        //打印hash函数
        printf("hash函数为：");
        for (int i = 0; i < strlen(name); i++) {
            printf("%d+", name[i] - 'a');
        }
        printf("=%d\n", sum);
        printf("hash函数对131取余为：%d\n", sum % 131);
    } else if (HASH[n].sum == 0) {
        printf("没有找到这条记录！！！\n");
    } else {
        printf("hash函数为：");
        while (1) {
            idx[counts] = m;
            m = (m + 1) % H;
            counts++;
            if (strcmp(HASH[m].name, name) == 0) {
                //打印hash函数
                for (int i = 0; i < strlen(name); i++) {
                    printf("%d+", name[i] - 'a');
                }
                printf("=%d\n", sum);
                printf("hash函数对131取余为：%d\n", sum % 131);


                printf("姓名:%s 关键字:%d 碰撞次数:%d\n", HASH[m].name, sum, counts);
                break;
            }
            if (HASH[m].key == 0) {
                printf("没有找到这条记录！！！\n");
                break;
            }
        }
    }
}

void displayhash()   //打印哈希表
{
    int i, sum;
    sum = 0;
    printf("\n地址\t关键字\t\t搜索长度\t姓名\n");
    for (i = 0; i < M; i++) {
        printf("%d", i);
        printf("\t%d", HASH[i].key);
        printf("\t\t%d", HASH[i].sum);
        printf("\t%s", HASH[i].name);
        printf("\n");
    }
    for (i = 0; i < M; i++) {
        sum += HASH[i].sum;
    }
}

void display() {
    int i;
    for (i = 0; i < 72; i++) {
        printf("关键字:%d 姓名:%s\n", NAME[i].v, NAME[i].s);
    }
}

int menu() {
    printf("\n************************************\n");
    printf("欢迎使用哈希表查找系统\n");
    //hash函数公式
    printf("1.展示姓名拼音和关键字\n");
    printf("2.展示哈希表\n");
    printf("3.查找关键字\n");
    printf("4.退出\n");
    printf("请输入你的选择：\n");
    return 0;
}

int main() {
    int n;
    int flag;
    flag = 1;
    while (1) {
        menu();

        if (flag == 1) {
            init();
            creathash();
            flag = 0;
        }
        scanf("%d", &n);
        getchar();
        if (n < 1 || n > 4) {
            printf("输入有误，请重新输入！！！\n");
            continue;
        } else {
            if (n == 1) {
                printf("展示所准备的拼音及其所组成的关键字：\n");
                display();
            } else if (n == 2) {
                displayhash();
            } else if (n == 3) {
                searchhash();
            } else if (n == 4) {
                return 0;
            }
        }

    }
}
