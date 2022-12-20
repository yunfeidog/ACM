#include "stdio.h"

//邻接矩阵存储
#define MAX 100
#define INF 0x3f3f3f3f

typedef struct {
    int n, m;
    int matrix[MAX][MAX];
} Graph;

//初始化图
void init(Graph *g, int n) {
    g->n = n;
    g->m = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g->matrix[i][j] = INF;
        }
    }
}

//插入边 x->y,权重为w
void insert(Graph *g, int x, int y, int w) {
    g->matrix[x][y] = w;
    g->m++;
}

//打印图
void output(Graph *g) {
    printf("n = %d, m = %d", g->n, g->m);
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            //如果两点之间有边
            if (g->matrix[i][j] != INF) {
                printf("(%d, %d) = %d\n", i, j, g->matrix[i][j]);
            }
        }
    }
}

int main() {
    Graph g;
    init(&g, 7);
    insert(&g, 1, 2, 1);
    insert(&g, 1, 3, 1);
    insert(&g, 1, 4, 1);
    insert(&g, 2, 5, 1);
    insert(&g, 3, 2, 1);
    insert(&g, 3, 5, 1);
    insert(&g, 3, 6, 1);
    insert(&g, 4, 6, 1);
    insert(&g, 5, 6, 1);
    output(&g);
    return 0;
}

