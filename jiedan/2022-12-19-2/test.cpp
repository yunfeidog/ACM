#include <bits/stdc++.h>

using namespace std;




//模拟购买双色球程序

//定义一个结构体，用来存储购买的双色球的信息，可能为单注或多注和红色复式，蓝色复式组合复式
struct ssq {
    int red[21];//红色球 1-33
    int blue[17];//蓝色球 1-16
    int redNum = 6;//红色球个数
    int blueNum = 1;//蓝色球个数
    int count = 1;//注数
    int redType = 0;//红色球类型 0单注 1复式
    int blueType = 0;//蓝色球类型 0单注 1复式
    int type = 0;//类型 0单注 1复式
    int price = 0;//价格
} ssqs[1000];
int len1;//购买的双色球数组长度


//定义一个结构体，用来存储中奖的双色球的信息
struct win {
    int red[7];
    int blue[2];
} winner[2];


void buy();//购买彩票

int generationRandom(int x, int y);//随机生成一个x-y的整数数

void print();//打印购买的双色球

void print(int x);//打印购买的双色球

void update();//更新购买的双色球

void generate();//生成中奖的双色球

void settlement();//结算

void check();//检查中奖

void menu();//菜单


int main() {
    while (1) menu();
}


void menu(){
    cout << "欢迎使用双色球购买系统" << endl;
    cout << "1.彩票投注" << endl;
    cout << "2.修改号码" << endl;
    cout << "3.结算彩票" << endl;
    cout << "4.输出彩票信息" << endl;
    cout << "5.兑奖" << endl;
    cout << "6.退出" << endl;
    cout << "请输入您的选择：";
    int n;
    cin >> n;
    switch (n) {
        case 1:
            cout << "彩票投注" << endl;
            buy();
            break;
        case 2:
            cout << "修改号码" << endl;
            update();
            break;
        case 3:
            cout << "结算彩票" << endl;
            settlement();
            break;
        case 4:
            cout << "输出彩票信息" << endl;
            generate();
            break;
        case 5:
            cout << "兑奖" << endl;
            check();
            break;
        case 6:
            cout << "退出" << endl;
            exit(0) ;
        default:
            cout << "输入错误" << endl;
            break;
    }
}

//随机生成一个x-y的整数数
int generationRandom(int x, int y) {
    return rand() % (y - x + 1) + x;
}

//彩票投注
void buy() {
    len1++;
    cout << "请输入投注类型1.单注、2.复式：";
    int type;
    cin >> type;
    if (type == 1) {
        cout << "1.随机生成、2.手动输入 【6红，1蓝】：";
        int type1;
        cin >> type1;
        if (type1 == 1) {
            //随机生成6个红球
            for (int i = 1; i <= 6; i++) {
                int num = generationRandom(1, 33);
                ssqs[len1].red[i] = num;
            }
            //随机生成1个蓝球
            int num = generationRandom(1, 16);
            ssqs[len1].blue[1] = num;

        } else if (type1 == 2) {
            //手动输入6个红球
            cout << "请输入6个红球：";
            for (int i = 1; i <= 6; i++) {
                int num;
                cin >> num;
                ssqs[len1].red[i] = num;
            }
            //手动输入1个蓝球
            cout << "请输入1个蓝球：";
            int num;
            cin >> num;
            ssqs[len1].blue[1] = num;

        } else {
            cout << "输入错误" << endl;
        }
        cout << "请输入注数：";
        int count;
        cin >> count;
        ssqs[len1].count = count;
        ssqs[len1].price = count * 2;
        cout << "投注成功，共花费" << ssqs[len1].price << "元" << endl;
    } else if (type == 2) {
        //复式购买
        cout << "请输入购买的红球个数：";
        int redNum;
        cin >> redNum;
        ssqs[len1].redNum = redNum;
        cout << "请输入购买的蓝球个数：";
        int blueNum;
        cin >> blueNum;
        ssqs[len1].blueNum = blueNum;
        cout << "请输入1.随机生成、2.手动输入：";
        int type1;
        cin >> type1;
        if (type1 == 1) {
            //随机生成红球
            for (int i = 1; i <= redNum; i++) {
                int num = generationRandom(1, 33);
                ssqs[len1].red[i] = num;
            }
            //随机生成蓝球
            for (int i = 1; i <= blueNum; i++) {
                int num = generationRandom(1, 16);
                ssqs[len1].blue[i] = num;
            }
        } else if (type1 == 2) {
            //手动输入红球
            cout << "请输入" << redNum << "个红球：";
            for (int i = 1; i <= redNum; i++) {
                int num;
                cin >> num;
                ssqs[len1].red[i] = num;
            }
            //手动输入蓝球
            cout << "请输入" << blueNum << "个蓝球：";
            for (int i = 1; i <= blueNum; i++) {
                int num;
                cin >> num;
                ssqs[len1].blue[i] = num;
            }

        } else {
            cout << "输入错误" << endl;
        }
        cout << "请输入注数：";
        int count;
        cin >> count;
        ssqs[len1].count = count;
        ssqs[len1].price = count * 2;
        cout << "投注成功，共花费" << ssqs[len1].price << "元" << endl;
    } else {
        cout << "输入错误" << endl;

    }
}

//打印购买的彩票信息
void print() {
    for (int i = 1; i <= len1; i++) {
        cout << "第" << i << "注：";
        cout << "红球：";
        for (int j = 1; j <= ssqs[i].redNum; j++) {
            cout << ssqs[i].red[j] << " ";
        }
        cout << "蓝球：";
        for (int j = 1; j <= ssqs[i].blueNum; j++) {
            cout << ssqs[i].blue[j] << " ";
        }
        cout << "注数：" << ssqs[i].count << " ";
        cout << "金额：" << ssqs[i].price << " ";
        cout << endl;
    }
}

void print(int x) {
    cout << "第" << x << "张彩票信息如下：";
    cout << "红球：";
    for (int j = 1; j <= ssqs[x].redNum; j++) {
        cout << ssqs[x].red[j] << " ";
    }
    cout << endl;
    cout << "蓝球：";
    for (int j = 1; j <= ssqs[x].blueNum; j++) {
        cout << ssqs[x].blue[j] << " ";
    }
    cout << endl;
    cout << "注数：" << ssqs[x].count << " " << endl;
    cout << "金额：" << ssqs[x].price << " " << endl;
}

void update() {
    cout << "请输入要修改第几张彩票：";
    int num;
    cin >> num;
    //修改红球号码
    for (int i = 1; i <= ssqs[num].redNum; i++) {
        cout << "请输入第" << i << "个红球号码：";
        int num1;
        cin >> num1;
        ssqs[num].red[i] = num1;
    }
    //修改蓝球号码
    for (int i = 1; i <= ssqs[num].blueNum; i++) {
        cout << "请输入第" << i << "个蓝球号码：";
        int num1;
        cin >> num1;
        ssqs[num].blue[i] = num1;
    }
    cout << "修改成功" << endl;
}

void settlement(){
    int sum=0;
    for(int i=1;i<=len1;i++){
        sum+=ssqs[i].price;
    }
    cout<<"共花费"<<sum<<"元"<<endl;
}


void generate() {
    //生成中奖号码
    for (int i = 1; i <= 6; i++) {
        int num = generationRandom(1, 33);
        winner->red[i] = num;
    }
    for (int i = 1; i <= 1; i++) {
        int num = generationRandom(1, 16);
        winner->blue[i] = num;
    }
    cout << "中奖号码如下：" << endl;
    cout << "红球：";
    for (int i = 1; i <= 6; i++) {
        cout << winner->red[i] << " ";
    }
    cout << endl;
    cout << "蓝球：";
    for (int i = 1; i <= 1; i++) {
        cout << winner->blue[i] << " ";
    }
    cout << endl;
}


//兑奖
void check() {
    int count = 0;
    for (int i = 1; i <= len1; i++) {
        int redCount = 0;
        int blueCount = 0;
        for (int j = 1; j <= 6; j++) {
            for (int k = 1; k <= 6; k++) {
                if (ssqs[i].red[j] == winner->red[k]) {
                    redCount++;
                }
            }
        }
        for (int j = 1; j <= 1; j++) {
            for (int k = 1; k <= 1; k++) {
                if (ssqs[i].blue[j] == winner->blue[k]) {
                    blueCount++;
                }
            }
        }
        if (redCount == 6 && blueCount == 1) {
            cout << "恭喜您中了一等奖" << endl;
            cout << "中奖号码如下：" << endl;
            cout << "红球：";
            for (int i = 1; i <= 6; i++) {
                cout << winner->red[i] << " ";
            }
            cout << endl;
            cout << "蓝球：";
            for (int i = 1; i <= 1; i++) {
                cout << winner->blue[i] << " ";
            }
            cout << endl;
            print(i);
            count++;
        } else if (redCount == 6 && blueCount == 0) {
            cout << "恭喜您中了二等奖" << endl;
            cout << "中奖号码如下：" << endl;
            cout << "红球：";
            for (int i = 1; i <= 6; i++) {
                cout << winner->red[i] << " ";
            }
            cout << endl;
            cout << "蓝球：";
            for (int i = 1; i <= 1; i++) {
                cout << winner->blue[i] << " ";
            }
            cout << endl;
            print(i);
            count++;
        } else if (redCount == 5 && blueCount == 1) {
            cout << "恭喜您中了三等奖" << endl;
            cout << "中奖号码如下：" << endl;
            cout << "红球：";
            for (int i = 1; i <= 6; i++) {
                cout << winner->red[i] << " ";
            }
            cout << endl;
            cout << "蓝球：";
            for (int i = 1; i <= 1; i++) {
                cout << winner->blue[i] << " ";
            }
            cout << endl;
            print(i);
            count++;
        } else if (redCount == 5 && blueCount == 0) {

            cout << "恭喜您中了四等奖" << endl;
            cout << "中奖号码如下：" << endl;
            cout << "红球：";
            for (int i = 1; i <= 6; i++) {
                cout << winner->red[i] << " ";
            }
            cout << endl;
            cout << "蓝球：";
            for (int i = 1; i <= 1; i++) {
                cout << winner->blue[i] << " ";
            }
            cout << endl;
            print(i);
            count++;
        } else if (redCount == 4 && blueCount == 1) {
            cout << "恭喜您中了五等奖" << endl;
            cout << "中奖号码如下：" << endl;
            cout << "红球：";
            for (int i = 1; i <= 6; i++) {
                cout << winner->red[i] << " ";
            }
            cout << endl;
            cout << "蓝球：";
            for (int i = 1; i <= 1; i++) {
                cout << winner->blue[i] << " ";
            }
            cout << endl;
            print(i);
            count++;
        } else if (redCount == 4 && blueCount == 0) {
            cout << "恭喜您中了六等奖" << endl;
            cout << "中奖号码如下：" << endl;
            cout << "红球：";
            for (int i = 1; i <= 6; i++) {
                cout << winner->red[i] << " ";
            }
            cout << endl;
            cout << "蓝球：";
            for (int i = 1; i <= 1; i++) {
                cout << winner->blue[i] << " ";
            }
            cout << endl;
            print(i);
            count++;
        } else if (redCount == 3 && blueCount == 1) {
            cout << "恭喜您中了七等奖" << endl;
            cout << "中奖号码如下：" << endl;
            cout << "红球：";
            for (int i = 1; i <= 6; i++) {
                cout << winner->red[i] << " ";
            }
            cout << endl;
            cout << "蓝球：";
            for (int i = 1; i <= 1; i++) {
                cout << winner->blue[i] << " ";
            }
            cout << endl;
            print(i);
            count++;
        }
    }
    if (count == 0) {
        cout << "很遗憾，您没有中奖" << endl;
    }
    //计算中奖金额
    int money = 0;
    if (count == 1) {
        money = 1000000;
    } else if (count == 2) {
        money = 300000;
    } else if (count == 3) {
        money = 30000;
    } else if (count == 4) {
        money = 10000;
    } else if (count == 5) {
        money = 3000;
    } else if (count == 6) {
        money = 200;
    } else if (count == 7) {
        money = 10;
    }
    cout << "您一共中奖" << count << "注，中奖金额为：" << money << "元" << endl;
}