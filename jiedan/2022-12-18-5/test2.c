#include "stdio.h"
#include "string.h"
#include "stdlib.h"

/**
 * 星座结构体
 * @param name 星座名称
 * @param startMonth 开始月份
 * @param startDay 开始日期
 * @param endMonth 结束月份
 * @param endDay 结束日期
 * @param age 年龄
 * @param match 配对星座
 */
struct constellation
    {
        char name[20];
        int startMonth;
        int startDay;
        int endMonth;
        int endDay;
        int age;
        char match[20];
    } constellations[12];


/**
 * 生日结构体
 * @param year 年份
 * @param month 月份
 * @param day 日期
 * @param constellation 星座
 * @param age 年龄
 * @param constellation 配对星座
 * @param match 配对星座
 */
struct people
    {
        int year;
        int month;
        int day;
        int age;
        char constellationName[20];
        char matchName[20];
    } peoples;

/**
 * 计算星座
 * @param peoples
 */
void countConstellation(struct people *people);

/**
 * 初始化星座
 *
 * @return
 */
int initConstellation();


int main()
    {
        //星座的初始化操作
        initConstellation();

        //输入你得生日信息
        printf("请输入你的生日(年 月 日)：");
        scanf("%d %d %d", &peoples.year, &peoples.month, &peoples.day);
        //当前年份为2022年12月
        //计算年龄
        peoples.age = 2022 - peoples.year;
        //计算星座
        countConstellation(&peoples);
        //输出结果
        printf("你的星座是：%s\n", peoples.constellationName);
        //输出匹配星座
        printf("你的配对星座是：%s\n", peoples.matchName);

        return 0;
    }


/**
* 计算星座
* @param peoples
*/
void countConstellation(struct people *people)
    {
        for (int i = 0; i < 12; ++i)
            {
                if (people->month == constellations[i].startMonth && people->day >= constellations[i].startDay)
                    {
                        strcpy(people->constellationName, constellations[i].name);
                        strcpy(people->matchName, constellations[i].match);
                        break;
                    } else if (people->month == constellations[i].endMonth && people->day <= constellations[i].endDay)
                    {
                        strcpy(people->constellationName, constellations[i].name);
                        strcpy(people->matchName, constellations[i].match);
                        break;
                    }
            }
    }


/**
* 初始化星座
*
* @return
*/
int initConstellation()
    {
        constellations[0].startMonth = 1;
        constellations[0].startDay = 20;
        constellations[0].endMonth = 2;
        constellations[0].endDay = 18;
        strcpy(constellations[0].name, "水瓶座");
        strcpy(constellations[0].match, "射手座");

        constellations[1].startMonth = 2;
        constellations[1].startDay = 19;
        constellations[1].endMonth = 3;
        constellations[1].endDay = 20;
        strcpy(constellations[1].name, "双鱼座");
        strcpy(constellations[1].match, "巨蟹座");

        constellations[2].startMonth = 3;
        constellations[2].startDay = 21;
        constellations[2].endMonth = 4;
        constellations[2].endDay = 19;
        strcpy(constellations[2].name, "白羊座");
        strcpy(constellations[2].match, "狮子");

        constellations[3].startMonth = 4;
        constellations[3].startDay = 20;
        constellations[3].endMonth = 5;
        constellations[3].endDay = 20;
        strcpy(constellations[3].name, "金牛座");
        strcpy(constellations[3].match, "处女座");

        constellations[4].startMonth = 5;
        constellations[4].startDay = 21;
        constellations[4].endMonth = 6;
        constellations[4].endDay = 21;
        strcpy(constellations[4].name, "双子座");
        strcpy(constellations[4].match, "天秤座");

        constellations[5].startMonth = 6;
        constellations[5].startDay = 22;
        constellations[5].endMonth = 7;
        constellations[5].endDay = 22;
        strcpy(constellations[5].name, "巨蟹座");
        strcpy(constellations[5].match, "双子座");

        constellations[6].startMonth = 7;
        constellations[6].startDay = 23;
        constellations[6].endMonth = 8;
        constellations[6].endDay = 22;
        strcpy(constellations[6].name, "狮子座");
        strcpy(constellations[6].match, "白羊座");

        constellations[7].startMonth = 8;
        constellations[7].startDay = 23;
        constellations[7].endMonth = 9;
        constellations[7].endDay = 22;
        strcpy(constellations[7].name, "处女座");
        strcpy(constellations[7].match, "金牛座");

        constellations[8].startMonth = 9;
        constellations[8].startDay = 23;
        constellations[8].endMonth = 10;
        constellations[8].endDay = 23;
        strcpy(constellations[8].name, "天秤座");
        strcpy(constellations[8].match, "双子座");

        constellations[9].startMonth = 10;
        constellations[9].startDay = 24;
        constellations[9].endMonth = 11;
        constellations[9].endDay = 22;
        strcpy(constellations[9].name, "天蝎座");
        strcpy(constellations[9].match, "魔蝎座");

        constellations[10].startMonth = 11;
        constellations[10].startDay = 23;
        constellations[10].endMonth = 12;
        constellations[10].endDay = 21;
        strcpy(constellations[10].name, "射手座");
        strcpy(constellations[10].match, "水瓶座");

        constellations[11].startMonth = 12;
        constellations[11].startDay = 22;
        constellations[11].endMonth = 1;
        constellations[11].endDay = 19;
        strcpy(constellations[11].name, "魔蝎座");
        strcpy(constellations[11].match, "天蝎座");
        return 0;
    }

