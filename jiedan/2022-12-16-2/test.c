#include "stdio.h"
#include "string.h"

//设备结构体
struct Device {
    int id;
    char type[20];
    char name[20];
    double price;
    char date[20];
    int flag;//是否报废 ，0表示未报废，1表示已报废
    char flagdate[20];//报废日期
} device[100];
int len = 0;

void add();//添加设备

void update();//修改设备

void show();//对设备进行分类显示

void del();//删除设备

void query();//查询设备

void save();//保存设备信息

int main() {
    printf("欢迎使用设备管理系统\n");
    while (1) {
        printf("1.添加设备\n");
        printf("2.修改设备\n");
        printf("3.对设备进行分类显示\n");
        printf("4.删除已报废设备\n");
        printf("5.查询设备\n");
        printf("6.退出\n");
        printf("请输入你的选择：\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            add();
        } else if (choice == 2) {
            update();
        } else if (choice == 3) {
            show();
        } else if (choice == 4) {
            del();
        } else if (choice == 5) {
            query();
        } else if (choice == 6) {
            printf("退出系统\n");
            save();
            break;
        }
    }

    return 0;
}

void add() {
    printf("请输入设备的id：\n");
    scanf("%d", &device[len].id);
    printf("请输入设备的类型：\n");
    scanf("%s", device[len].type);
    printf("请输入设备的名称：\n");
    scanf("%s", device[len].name);
    printf("请输入设备的价格：\n");
    scanf("%lf", &device[len].price);
    printf("请输入设备的购买日期：\n");
    scanf("%s", device[len].date);
    printf("请输入设备的状态：\n");
    scanf("%d", &device[len].flag);
    if (device[len].flag == 1) {
        printf("请输入设备的报废日期：\n");
        scanf("%s", device[len].flagdate);
    }else{
        strcpy(device[len].flagdate,"无");
    }
    len++;
    printf("添加成功\n");
}


void update() {
    printf("请输入要修改的设备的id：\n");
    int id;
    scanf("%d", &id);
    for (int i = 0; i < len; i++) {
        if (device[i].id == id) {
            printf("请输入设备的类型：\n");
            scanf("%s", device[i].type);
            printf("请输入设备的名称：\n");
            scanf("%s", device[i].name);
            printf("请输入设备的价格：\n");
            scanf("%lf", &device[i].price);
            printf("请输入设备的购买日期：\n");
            scanf("%s", device[i].date);
            printf("请输入设备的状态：\n");
            scanf("%d", &device[i].flag);
            if (device[i].flag == 1) {
                printf("请输入设备的报废日期：\n");
                scanf("%s", device[i].flagdate);
            }else{
                strcpy(device[i].flagdate,"无");
            }
            printf("修改成功\n");
            return;
        }
    }
    printf("没有找到该设备\n");
}

void show() {
    printf("1.未报废设备\n");
    printf("2.已报废设备\n");
    printf("请输入你的选择：\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        for (int i = 0; i < len; i++) {
            if (device[i].flag == 0) {
                printf("设备的id：%d\n", device[i].id);
                printf("设备的类型：%s\n", device[i].type);
                printf("设备的名称：%s\n", device[i].name);
                printf("设备的价格：%lf\n", device[i].price);
                printf("设备的购买日期：%s\n", device[i].date);
                printf("设备的状态：%d\n", device[i].flag);
            }
        }
    } else if (choice == 2) {
        for (int i = 0; i < len; i++) {
            if (device[i].flag == 1) {
                printf("设备的id：%d\n", device[i].id);
                printf("设备的类型：%s\n", device[i].type);
                printf("设备的名称：%s\n", device[i].name);
                printf("设备的价格：%lf\n", device[i].price);
                printf("设备的购买日期：%s\n", device[i].date);
                printf("设备的状态：%d\n", device[i].flag);
                printf("设备的报废日期：%s\n", device[i].flagdate);
            }
        }
    }
}

void del() {
    //删除已经报废的设备
    int sum = 0;//报废设备的金钱
    for (int i = 0; i < len; ++i){
        if (device[i].flag == 1){
            //删除
            sum += device[i].price;
            for (int j = i; j < len; ++j) {
                device[j] = device[j + 1];
            }
            len--;
            i--;

        }
    }
    printf("报废设备的总价值为：%d\n",sum);
}

void query() {
    printf("请输入要查询的设备的id：\n");
    int id;
    scanf("%d", &id);
    for (int i = 0; i < len; i++) {
        if (device[i].id == id) {
            printf("设备的id：%d\n", device[i].id);
            printf("设备的类型：%s\n", device[i].type);
            printf("设备的名称：%s\n", device[i].name);
            printf("设备的价格：%lf\n", device[i].price);
            printf("设备的购买日期：%s\n", device[i].date);
            printf("设备的状态：%d\n", device[i].flag);
            printf("设备的报废日期：%s\n", device[i].flagdate);
            return;
        }
    }
    printf("没有找到该设备\n");
}

void save() {
    FILE *fp = fopen("H:\\C++\\VsCode_cpp\\jiedan\\2022-12-16-2\\device.txt", "w");
    if (fp == NULL) {
        printf("打开文件失败\n");
        return;
    }
    for (int i = 0; i < len; i++) {
        fprintf(fp, "%d %s %s %lf %s %d %s\n", device[i].id, device[i].type, device[i].name, device[i].price, device[i].date, device[i].flag, device[i].flagdate);
    }
    fclose(fp);
    printf("保存成功\n");
}
