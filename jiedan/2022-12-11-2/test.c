#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
#include "judger.h"
#include "player.h"

char password[20] = "abcdefg";


struct player player[110];
struct judger judger[110];
int len = 0;
char sex[5][10] = {"女", "男", "未填"};


void init() {
    //读取player.txt文件，
    //将文件中的数据读取到player数组中,第一行为len
    //接下来为len行数据，每行数据为id,name,sex,score1,score2,score3,score4,score5,score6,score7,score8,score9,score10
    //打开文件
    FILE *fp = fopen("H:\\C++\\VsCode_cpp\\jiedan\\2022-12-11-2\\Player_Info.txt", "r");
    fscanf(fp, "%d", &len);
    for (int i = 0; i < len; i++) {
        fscanf(fp, "%s %s %d ", player[i].id, player[i].name, &player[i].sex);
        for (int j = 0; j < 10; j++) {
            fscanf(fp, "%lf", &player[i].score[j]);
        }
    }

    fclose(fp);
//    printf("len = %d\n", len);
//    输出player数组中的数据
//    for (int i = 0; i < len; i++) {
//        printf("%s %s %d \n", player[i].id, player[i].name, player[i].sex);
//    }

    int idx;
    //从文件S_info读取性别
    FILE *fp1 = fopen("H:\\C++\\VsCode_cpp\\jiedan\\2022-12-11-2\\S_info.txt", "r");
    fscanf(fp1, "%d", &idx);
    fclose(fp1);

    //从文件J_info读取裁判信息
    FILE *fp2 = fopen("H:\\C++\\VsCode_cpp\\jiedan\\2022-12-11-2\\Judger.txt", "r");
    fscanf(fp2, "%d", &idx);
    for (int j = 0; j < idx; ++j) {
        fscanf(fp2, "%s", judger[j].name);
    }
    fclose(fp2);

}

//1.按选手姓名排序，输出
void sortByName() {
    //按选手姓名排序，输出
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (strcmp(player[i].name, player[j].name) > 0) {
                struct player temp = player[i];
                player[i] = player[j];
                player[j] = temp;
            }
        }
    }
    for (int i = 0; i < len; i++) {
        printf("%s %s %s ", player[i].id, player[i].name, sex[player[i].sex]);
        //输出选手的成绩
        for (int j = 0; j < 10; j++) {
            printf("%.2lf ", player[i].score[j]);
        }
        printf("\n");
    }
}

//2.计算所有选手最后得分,去掉一个最高分，去掉一个最低分，然后求平均分
void calculate() {
    //计算所有选手最后得分,去掉一个最高分，去掉一个最低分，然后求平均分
    for (int i = 0; i < len; i++) {
        double max = player[i].score[0];
        double min = player[i].score[0];
        double sum = 0;
        for (int j = 0; j < 10; j++) {
            if (player[i].score[j] > max) {
                max = player[i].score[j];
            }
            if (player[i].score[j] < min) {
                min = player[i].score[j];
            }
            sum += player[i].score[j];
        }
        player[i].sum = (sum - max - min) / 8;
    }
    //输出所有选手最后得分
    for (int i = 0; i < len; i++) {
        printf("%s %s %s %.2lf\n", player[i].id, player[i].name, sex[player[i].sex], player[i].sum);
    }
}


//3.按所有选手最后得分排序，输出
void sortByScore() {
    //计算所有选手最后得分,去掉一个最高分，去掉一个最低分，然后求平均分
    for (int i = 0; i < len; i++) {
        double max = player[i].score[0];
        double min = player[i].score[0];
        double sum = 0;
        for (int j = 0; j < 10; j++) {
            if (player[i].score[j] > max) {
                max = player[i].score[j];
            }
            if (player[i].score[j] < min) {
                min = player[i].score[j];
            }
            sum += player[i].score[j];
        }
        player[i].sum = (sum - max - min) / 8;
    }
    //按所有选手最后得分排序，输出
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (player[i].sum < player[j].sum) {
                struct player temp = player[i];
                player[i] = player[j];
                player[j] = temp;
            }
        }
    }
    //输出所有选手最后得分
    for (int i = 0; i < len; i++) {
        printf("%s %s %s %.2lf\n", player[i].id, player[i].name, sex[player[i].sex], player[i].sum);
    }
}

//4.对评委打分进行裁判，找出最接近平均分的评委，输出，找出与平均分差距最大的评委，输出
void judge() {
    //对评委打分进行裁判，找出最接近平均分的评委，输出，找出与平均分差距最大的评委，输出
    double sum = 0;
    for (int i = 0; i < len; i++) {
        sum += player[i].sum;
    }
    double avg = sum / len;
    double min = 100000;
    double max = 0;
    int min_idx = 0;
    int max_idx = 0;
    for (int i = 0; i < len; i++) {
        if (fabs(avg - player[i].sum) < min) {
            min = fabs(avg - player[i].sum);
            min_idx = i;
        }
        if (fabs(avg - player[i].sum) > max) {
            max = fabs(avg - player[i].sum);
            max_idx = i;
        }
    }
    printf("最接近平均分的评委是%s %s %lf \n", player[min_idx].id, player[min_idx].name, player[min_idx].sum);
    printf("与平均分差距最大的评委是%s %s %lf \n", player[max_idx].id, player[max_idx].name, player[max_idx].sum);
}


//5.添加选手及其得分
void add() {
    //添加选手及其得分
    printf("请输入选手的id，姓名，性别，10次打分：\n");
    scanf("%s %s %d", player[len].id, player[len].name, &player[len].sex);
    for (int i = 0; i < 10; i++) {
        scanf("%lf", &player[len].score[i]);
    }
    len++;
    printf("添加成功！\n");
}

//6.修改选手信息
void update() {
    //修改选手信息
    printf("请输入要修改的选手的id：\n");
    char id[20];
    scanf("%s", id);
    int idx = -1;
    for (int i = 0; i < len; i++) {
        if (strcmp(player[i].id, id) == 0) {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        printf("没有找到该选手！\n");
    } else {
        printf("请输入选手的id，姓名，性别，10次打分：\n");
        scanf("%s %s %d", player[idx].id, player[idx].name, &player[idx].sex);
        for (int i = 0; i < 10; i++) {
            scanf("%lf", &player[idx].score[i]);
        }
        printf("修改成功！\n");
    }
}

//7.根据姓名查询选手

void query() {
    //根据姓名查询选手
    printf("请输入要查询的选手的姓名：\n");
    char name[20];
    scanf("%s", name);
    int idx = -1;
    for (int i = 0; i < len; i++) {
        if (strcmp(player[i].name, name) == 0) {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        printf("没有找到该选手！\n");
    } else {
        printf("选手的id，姓名，性别，10次打分：\n");
        printf("%s %s %s  ", player[idx].id, player[idx].name, sex[player[idx].sex]);
        for (int i = 0; i < 10; i++) {
            printf("%.2lf    ", player[idx].score[i]);
        }
        printf("\n");
    }
}


//8.修改系统密码

void changePassword() {
    //修改系统密码
    printf("请输入原密码：\n");
    char oldPassword[20];
    scanf("%s", oldPassword);
    if (strcmp(oldPassword, password) == 0) {
        printf("请输入新密码：\n");
        scanf("%s", password);
    } else {
        printf("密码错误！\n");
    }
}

void menu() {
    printf("====================================\n");
    printf("1.按选手姓名排序，输出\n");
    printf("2.计算所有选手最后得分，输出\n");
    printf("3.按所有选手最后得分排序，输出\n");
    printf("4.对评委打分进行裁判，输出\n");
    printf("5.添加选手及其成绩\n");
    printf("6.修改给定选手得分\n");
    printf("7.按姓名查询选手\n");
    printf("8.修改系统密码\n");
    printf("9.退出\n");
}

char *encrypt(char *str) {
    // 获取字符串的长度
    int length = strlen(str);

    // 对每个字符进行移位
    for (int i = 0; i < length; i++) {
        str[i] = str[i] << 1;
    }

    return str;
}


int main() {
    init();
    printf("\n");
    while (1) {
        printf("请输入登录密码：");
        char input[20];
        scanf("%s", input);
        int flag = 0;
        for (int i = 0; i < strlen(input); i++) {
            if ((input[i] - '0') != (password[i] - 'a' + 1)) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            printf("登录成功！\n");
            break;
        } else{
            printf("密码错误！\n");
        }
    }
    while (1) {
        menu();
        printf("请输入要执行的操作：\n");
        int op;
        scanf("%d", &op);
        if (op == 1) {
            sortByName();
        } else if (op == 2) {
            calculate();
        } else if (op == 3) {
            sortByScore();
        } else if (op == 4) {
            judge();
        } else if (op == 5) {
            add();
        } else if (op == 6) {
            update();
        } else if (op == 7) {
            query();
        } else if (op == 8) {
            changePassword();
        } else if (op == 9) {
            break;
        } else {
            printf("输入错误！\n");
        }
    }
    return 0;
}
