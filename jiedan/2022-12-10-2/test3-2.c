#include "stdio.h"
#include "string.h"

//邻接表
#define N 100
int h[N], e[N], ne[N], idx;
int n, m;
//n为点数，m为边数
void add(int a, int b) {//a为起点，b为终点
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;//将b加入a的邻接表中
}
void create() {
    memset(h, -1, sizeof h);
    //邻接表建图
    add(0,2);
    add(0,5);
    add(0,6);
    add(0,1);
    add(1,3);
    add(1,0);
    add(1,4);
    add(1,2);
    add(2,0);
    add(2,3);
    add(2,6);
    add(2,1);
    add(3,1);
    add(3,2);
    add(3,4);
    add(4,1);
    add(4,3);
    add(5,0);
    add(5,6);
    add(6,0);
    add(6,2);
    add(6,5);
}

//DFS遍历

int st[N];//标记数组
int dfs(int u) {
    st[u] = 1;//标记u已经被访问
    for (int i = h[u]; i != -1; i = ne[i]) {//遍历u的所有邻接点
        int j = e[i];//j为u的邻接点
        if (st[j]) continue;//如果j已经被访问过，跳过
        printf("%d ", j);//输出j
        dfs(j);//递归访问j
    }
}

//BFS遍历
int q[N];//队列
int bfs() {
    memset(st, 0, sizeof st);//初始化标记数组
    int hh = 0, tt = -1;//队列头尾指针
    q[++tt] = 0;//将0入队
    st[0] = 1;//标记0已经被访问
    while (hh <= tt) {//队列不为空
        int t = q[hh++];//队首元素出队
        for (int i = h[t]; i != -1; i = ne[i]) {//遍历t的所有邻接点
            int j = e[i];//j为t的邻接点
            if (st[j]) continue;//如果j已经被访问过，跳过
            q[++tt] = j;//将j入队
            st[j] = 1;//标记j已经被访问
            printf("%d ", j);//输出j
        }
    }
}

int main() {
    create();
    //dfs
    printf("dfs: ");
    dfs(0);
    //bfs

    printf("\nbfs: ");
    bfs();
    return 0;
}
