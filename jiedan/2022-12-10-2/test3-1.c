#include "stdio.h"
#include "string.h"

#define N 100

int g[N][N];
//邻接表
int n, m;
//n为点数，m为边数
int e[N], ne[N], h[N], idx;

void add(int a, int b) {//a为起点，b为终点
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;//将b加入a的邻接表中
}

void create() {//创建邻接表

    memset(h, -1, sizeof h);
    g[1][2] = 1;
    g[1][3] = 1;
    g[1][4] = 1;
    g[2][5] = 1;
    g[3][2] = 1;
    g[3][5] = 1;
    g[3][6] = 1;
    g[4][6] = 1;
    g[5][6] = 1;
    //邻接表建图
    add(1, 2);

    add(1, 3);
    add(1, 4);
    add(2, 5);
    add(3, 2);
    add(3, 5);
    add(3, 6);
    add(4, 6);
    add(5, 6);
}

int main(){
    create();
    //邻接矩阵
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            printf("%d ", g[i][j]);//输出邻接矩阵
        }
        printf("\n");
    }
    //邻接表

    for (int i = 1; i <= 6; i++) {
        printf("%d: ", i);
        for (int j = h[i]; j != -1; j = ne[j]) {
            printf("%d ", e[j]);//输出邻接表
        }
        printf("\n");
    }
    return 0;
}


