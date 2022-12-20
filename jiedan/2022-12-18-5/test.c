#include "stdio.h"
#include "string.h"

/**
 * 生日结构体
 */
struct brithday{
    int year;
    int month;
    int day;
};

/**
 * 星座结构体
 * @param name 星座名称
 * @param startMonth 开始月份
 * @param startDay 开始日期
 * @param endMonth 结束月份
 * @param endDay 结束日期
 * @param date 日期
 * @param month 月份
 * @param year 年份
 * @param age 年龄
 * @param brith 生日
 * @param constellation 配对星座
 */
struct constellation{
    char name[20];
    int startMonth;
    int startDay;
    int endMonth;
    int endDay;
    int age;
    struct brithday brith;
    char constellation[20];
}constellations[12];

/**
 * 初始化星座
 * @param constellations
 * @param len
 * @return
 *
 */

int initConstellation(){
    constellations[0].startMonth = 1;
    constellations[0].startDay = 20;
    constellations[0].endMonth = 2;
    constellations[0].endDay = 18;
    strcpy(constellations[0].name,"水瓶座");
    strcpy(constellations[0].constellation,"射手座");

    constellations[1].startMonth = 2;
    constellations[1].startDay = 19;
    constellations[1].endMonth = 3;
    constellations[1].endDay = 20;
    strcpy(constellations[1].name,"双鱼座");
    strcpy(constellations[1].constellation,"巨蟹座");

    constellations[2].startMonth = 3;
    constellations[2].startDay = 21;
    constellations[2].endMonth = 4;
    constellations[2].endDay = 19;
    strcpy(constellations[2].name,"白羊座");
    strcpy(constellations[2].constellation,"狮子");

    constellations[3].startMonth = 4;
    constellations[3].startDay = 20;
    constellations[3].endMonth = 5;
    constellations[3].endDay = 20;
    strcpy(constellations[3].name,"金牛座");
    strcpy(constellations[3].constellation,"处女座");

    constellations[4].startMonth = 5;
    constellations[4].startDay = 21;
    constellations[4].endMonth = 6;
    constellations[4].endDay = 21;
    strcpy(constellations[4].name,"双子座");
    strcpy(constellations[4].constellation,"天秤座");

    constellations[5].startMonth = 6;
    constellations[5].startDay = 22;
    constellations[5].endMonth = 7;
    constellations[5].endDay = 22;
    strcpy(constellations[5].name,"巨蟹座");
    strcpy(constellations[5].constellation,"双子座");

    constellations[6].startMonth = 7;
    constellations[6].startDay = 23;
    constellations[6].endMonth = 8;
    constellations[6].endDay = 22;
    strcpy(constellations[6].name,"狮子座");
    strcpy(constellations[6].constellation,"白羊座");

    constellations[7].startMonth = 8;
    constellations[7].startDay = 23;
    constellations[7].endMonth = 9;
    constellations[7].endDay = 22;
    strcpy(constellations[7].name,"处女座");
    strcpy(constellations[7].constellation,"金牛座");

    constellations[8].startMonth = 9;
    constellations[8].startDay = 23;
    constellations[8].endMonth = 10;
    constellations[8].endDay = 23;
    strcpy(constellations[8].name,"天秤座");
    strcpy(constellations[8].constellation,"双子座");

    constellations[9].startMonth = 10;
    constellations[9].startDay = 24;
    constellations[9].endMonth = 11;
    constellations[9].endDay = 22;
    strcpy(constellations[9].name,"天蝎座");
    strcpy(constellations[9].constellation,"魔蝎座");

    constellations[10].startMonth = 11;
    constellations[10].startDay = 23;
    constellations[10].endMonth = 12;
    constellations[10].endDay = 21;
    strcpy(constellations[10].name,"射手座");
    strcpy(constellations[10].constellation,"水瓶座");

    constellations[11].startMonth = 12;
    constellations[11].startDay = 22;
    constellations[11].endMonth = 1;
    constellations[11].endDay = 19;
    strcpy(constellations[11].name,"魔蝎座");
    strcpy(constellations[11].constellation,"天蝎座");
    return 0;
}

/**
 * 根据输入的日期判断星座
 * @param constellations
 * @param len
 * @param date
 * @param month
 * @return
 */

int getConstellation(struct constellation constellations[],int len,int date,int month) {
    int i;
    for (i = 0; i < len; i++) {
        if (month == constellations[i].startMonth && date >= constellations[i].startDay) {
            printf("你的星座是%s", constellations[i].name);
            return i;
        } else if (month == constellations[i].endMonth && date <= constellations[i].endDay) {
            return i;
        }
    }
    return -1;
}


/**
 * 根据输入的日期计算年龄
 */

int getAge(struct constellation constellations[],int len,int date,int month,int year){
    int i;
    for (i = 0; i < len; i++) {
        if (month == constellations[i].startMonth && date >= constellations[i].startDay) {
            constellations[i].age = 2019 - year;
            printf("你的年龄是%d", constellations[i].age);
            return i;
        } else if (month == constellations[i].endMonth && date <= constellations[i].endDay) {
            constellations[i].age = 2019 - year;
            printf("你的年龄是%d", constellations[i].age);
            return i;
        }
    }
    return -1;
}

/**
 * 根据星座匹配星座
 * @param constellations
 * @param len
 * @param index
 * @return
 */

int getConstellationByIndex(struct constellation constellations[],int len,int index) {
    if (index >= 0 && index < len) {
        printf("你的星座是%s", constellations[index].constellation);
        return 0;
    }
    return -1;

/**
 * 菜单
 * 可以选择的功能
 * 1.根据生日计算星座
 * 2.计算年龄
 * 3.根据星座匹配对应的星座
 * 4.退出
 */
void menu();

int main() {
    while (1)
    {
        menu();
    }

    return 0;
}

void menu(){
    printf("1.根据生日计算星座");
    printf("2.计算年龄");
    printf("3.根据星座匹配对应的星座");
    printf("4.退出");
    int op;
    scanf("%d",&op);
    switch (op){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            break;
    }
}