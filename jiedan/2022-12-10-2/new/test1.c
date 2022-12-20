#include "stdio.h"
#include "stdlib.h"
#define MAX 1000

//解决约瑟夫问题

//定义一个动态循环队列
typedef struct {
    int *data;
    int head, rear;//队首和队尾指针
} Queue;

//初始化队列
Queue *init(int n) {
    Queue *q = (Queue *) malloc(sizeof(Queue));//申请一个队列的内存空间
    q->data = (int *) malloc(sizeof(int) * n);//申请一个队列的数据域的内存空间
    q->head = q->rear = 0;//队首和队尾指针置空
    return q;//返回队列
}

//判断队列是否为空
int empty(Queue *q) {
    return q->head == q->rear;//如果队首和队尾指针相等，返回1，否则返回0
}

//入队
int push(Queue *q, int val) {
    if ((q->rear + 1) % MAX == q->head) {//如果队尾指针加1后对100取余等于队首指针
        return 0;//返回0
    }
    q->data[q->rear] = val;//将val放入队尾
    q->rear = (q->rear + 1) % MAX;//队尾指针加1后对100取余
    return 1;//返回1
}

//出队
int pop(Queue *q) {
    if (empty(q)) {//如果队列为空
        return 0;//返回0
    }
    q->head = (q->head + 1) % MAX;//队首指针加1后对100取余
    return 1;//返回1
}

//取队首元素
int front(Queue *q) {
    return q->data[q->head];//返回队首元素
}

//解决约瑟夫问题
void solve(int n, int m) {
    Queue *q = init(n);//初始化队列
    for (int i = 1; i <= n; i++) {//将1到n依次入队
        push(q, i);
    }
    printf("n = %d, m = %d, the order is : \n", n, m);//输出n和m
    while (!empty(q)) {//如果队列不为空
        for (int i = 1; i < m; i++) {//出队m-1次
            push(q, front(q));//将队首元素放入队尾
            pop(q);//出队
        }
        //如果队列中只剩下一个元素，直接这是赢家
        if (q->head + 1 == q->rear) {
            printf("the monkey king is %d\n", front(q));//输出赢家
        } else {
            printf("%d leave the queue\n ", front(q));//输出出队元素
        }
        pop(q);//出队
    }
}

int main() {
    int n, m;
    printf("Please input n and m : ");//输入n和m
    scanf("%d%d", &n, &m);
    solve(n, m);//解决约瑟夫问题
    return 0;
}
