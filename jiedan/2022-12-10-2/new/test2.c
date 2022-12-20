#include "stdio.h"
#include "stdlib.h"

#define MAX 100

//解决表达式求值
//定义一个栈
typedef struct {
    int *data;
    int top;//栈顶指针
} Stack;

//初始化栈
Stack *init(int n) {
    Stack *s = (Stack *) malloc(sizeof(Stack));//申请一个栈的内存空间
    s->data = (int *) malloc(sizeof(int) * n);//申请一个栈的数据域的内存空间
    s->top = -1;//栈顶指针置空
    return s;//返回栈
}

//判断栈是否为空

int empty(Stack *s) {
    return s->top == -1;//如果栈顶指针等于-1，返回1，否则返回0
}

//入栈
int push(Stack *s, int val) {
    if (s->top + 1 == MAX) {//如果栈顶指针加1后等于100
        return 0;//返回0
    }
    s->data[++s->top] = val;//将val放入栈顶
    return 1;//返回1
}

//出栈
int pop(Stack *s) {
    if (empty(s)) {//如果栈为空
        return 0;//返回0
    }
    s->top--;//栈顶指针减1
    return 1;//返回1
}

//取栈顶元素
int top(Stack *s) {
    if (empty(s)) {//如果栈为空
        return 0;//返回0
    }
    return s->data[s->top];//返回栈顶元素
}


//判断运算符优先级
int priority(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(':
            return 3;
    }
    return 0;
}

//判断是否为运算符
int is_op(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')';
}

//判断是否为数字
int is_num(char ch) {
    return ch >= '0' && ch <= '9';
}

//计算
int calc(int a, int b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
    return 0;
}

//表达式求值
int exp_value(char *str) {
    Stack *num = init(MAX), *op = init(MAX);//初始化两个栈
    int i = 0;//定义一个变量
    while (str[i]) {//循环遍历字符串
        if (is_num(str[i])) {//如果是数字
            int temp = 0;//定义一个变量
            while (is_num(str[i])) {//循环遍历字符串
                temp = temp * 10 + str[i] - '0';//将字符串转换为数字
                i++;//i加1
            }
            push(num, temp);//将数字入栈
            i--;//i减1
        } else if (is_op(str[i])) {//如果是运算符
            if (empty(op) || str[i] == '(' || priority(str[i]) > priority(top(op))) {//如果栈为空或者运算符为左括号或者运算符优先级大于栈顶元素优先级
                push(op, str[i]);//将运算符入栈
            } else {//否则
                while (!empty(op) && priority(str[i]) <= priority(top(op))) {//循环遍历栈
                    int a = top(num);//定义一个变量
                    pop(num);//出栈
                    int b = top(num);//定义一个变量
                    pop(num);//出栈
                    int c = top(op);//定义一个变量
                    pop(op);//出栈
                    push(num, calc(b, a, c));//将计算结果入栈
                }
                if (str[i] != ')') {//如果运算符不为右括号
                    push(op, str[i]);//将运算符入栈
                }
            }
        }
        i++;//i加1
    }
    while (!empty(op)) {//循环遍历栈
        int a = top(num);//定义一个变量
        pop(num);//出栈
        int b = top(num);//定义一个变量
        pop(num);//出栈
        int c = top(op);//定义一个变量
        pop(op);//出栈
        push(num, calc(b, a, c));//将计算结果
    }
    return top(num);//返回栈顶元素
}

int main() {
    char str[MAX] = {0};//定义一个字符串
    scanf("%[^\n]s", str);//输入字符串
    printf("%d\n", exp_value(str));//输出字符串
    return 0;//返回0
}