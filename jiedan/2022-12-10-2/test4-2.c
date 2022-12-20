#include "stdio.h"
#include "string.h"

#define N 100
int h[N], e[N], ne[N], idx;
int n, m;
//n为点数，m为边数

void add(int a, int b) {//a为起点，b为终点
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;//将b加入a的邻接表中
}

void create() {
    //创建邻接表
    memset(h, -1, sizeof h);
    add(1,2);
    add(1,3);
    add(2,3);
    add(2,4);
    add(2,5);
    add(3,4);
    add(4,5);
    add(5,3);
    add(5,1);
}

//深度优先生成树
int st[N];//记录每个点的状态
int dfs(int u) {//u为当前节点
    st[u] = 1;//标记u已经被访问
    if(u==1) printf("%d ", u);//如果u为1，输出u
    for (int i = h[u]; i != -1; i = ne[i]) {//遍历u的邻接表
        int j = e[i];//j为u的邻接点
        if (st[j]) continue;//如果j已经被访问过，跳过
        printf("%d ", j);//输出j
        dfs(j);//递归访问j的邻接点
    }
}

//广度优先生成树
int q[N];//队列
int bfs() {//从0开始遍历
    memset(st, 0, sizeof st);//初始化标记数组
    int hh = 0, tt = -1;//队列头尾指针
    q[++tt] = 2;//将2入队
    st[2] = 1;//标记2已经被访问
    printf("%d ", 2);//输出2
    while (hh <= tt) {//队列不为空
        int t = q[hh++];//取出队首元素
        for (int i = h[t]; i != -1; i = ne[i]) {//遍历t的邻接表
            int j = e[i];//j为t的邻接点
            if (st[j]) continue;//如果j已经被访问过，跳过
            st[j] = 1;//标记j已经被访问
            q[++tt] = j;//将j入队
            printf("%d ", j);//输出j
        }
    }
}

int main() {
    create();
    printf("深度优先生成树：");

    dfs(1);
    printf("\n");
    printf("广度优先生成树：");
    bfs();

    return 0;
}
