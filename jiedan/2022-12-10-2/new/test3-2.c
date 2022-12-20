#include "stdio.h"
#include "stdlib.h"

//邻接表存储
#define MAX 100
#define INF 0x3f3f3f3f

typedef struct Edge {
    int to, w;
    struct Edge *next;
} Edge;

typedef struct {
    int n, m;
    Edge *edges[MAX];
} Graph;

//初始化图
void init(Graph *g, int n) {
    g->n = n;
    g->m = 0;
    for (int i = 0; i < n; i++) {
        g->edges[i] = NULL;
    }
}

//插入边 x->y,权重为w
void insert(Graph *g, int x, int y, int w) {
    Edge *e = (Edge *) malloc(sizeof(Edge));
    e->to = y;
    e->w = w;
    e->next = g->edges[x];
    g->edges[x] = e;
    g->m++;
}

//打印图

void output(Graph *g) {
    printf("n = %d, m = %d\n", g->n, g->m);
    for (int i = 0; i < g->n; i++) {
        for (Edge *e = g->edges[i]; e != NULL; e = e->next) {
            printf("(%d, %d) = %d\n", i, e->to, e->w);
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
