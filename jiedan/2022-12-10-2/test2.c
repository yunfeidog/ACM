
#include<stdio.h>
#include<string.h>

#define N 100010

int num[N], t1 = -1;//t1为栈顶指针
int t2 = -1, ls;//t2为队列头指针，ls为队列尾指针
char op[N], s[N];//栈num存操作数，栈op存操作符，t1和t2分别为栈顶指针

int hash(char ch) {//判断操作符优先级
    if (ch == '+' || ch == '-') return 1;//加减优先级最低
    else return 2;//乘除优先级最高
}//运算符hash

void cal(int num[N], char op[N]) {
    int b = num[t1--];//弹出栈顶元素
    int a = num[t1--];//弹出栈顶元素
    char theta = op[t2--];//弹出栈顶元素
    if (theta == '+') num[++t1] = a + b;//栈顶元素相加
    else if (theta == '-') num[++t1] = a - b;//栈顶元素相减
    else if (theta == '*') num[++t1] = a * b;//栈顶元素相乘
    else num[++t1] = a / b;//栈顶元素相除
}//运算函数
int main() {
    scanf("%s", s);
    int ls = strlen(s);

    for (int i = 0; i < ls; i++) {//遍历字符串
        char c = s[i];//取出字符串中的字符
        if ((c - '0' >= 0) && (c - '0' <= 9)) {//如果是数字
            int j = i, t = 0;//j为指针，t为临时变量
            while (j < ls && (s[j] - '0' >= 0) && (s[j] - '0' <= 9)) t = 10 * t + s[j++] - '0';//将数字转换为整数
            num[++t1] = t;//将整数压入栈
            i = j - 1;//指针后移
        }//读取计算一个操作数并存入num栈
        else if (c == '(') op[++t2] = c;//左括号可以直接入栈op
        else if (c == ')') {//右括号需要将op栈中的运算符弹出直到遇到左括号
            while (t2 >= 0) {//栈不为空
                if (op[t2] != '(') cal(num, op);//如果栈顶元素不是左括号，就弹出栈顶元素进行运算
                else {//如果栈顶元素是左括号
                    t2--;//弹出左括号
                    break;//跳出循环
                }
            }
        }//如果是右括号则一直运算直至碰到左括号脱括号
        else {
            while (t2 >= 0 && op[t2] != '(' && hash(c) <= hash(op[t2])) cal(num, op);//如果当前运算符优先级小于等于栈顶运算符优先级，就弹出栈顶元素进行运算
            op[++t2] = c;//将当前运算符压入栈
        }//当栈外优先级小于等于栈内优先级，对栈内进行运算，最后将c存入op栈
    }
    while (t2 >= 0) cal(num, op);//继续运算直至op栈空
    printf("%d", num[0]);//num栈顶元素即为最后的运算结果

    return 0;
}