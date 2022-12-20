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

//广度优先搜索从顶点v0出发b遍历图g
void bfs(Graph *g, int v0) {
    int *visited = (int *) malloc(sizeof(int) * g->n);
    for (int i = 0; i < g->n; i++) {
        visited[i] = 0;
    }
    int *queue = (int *) malloc(sizeof(int) * g->n);
    int head = 0, tail = 0;
    queue[tail++] = v0;
    visited[v0] = 1;
    while (head < tail) {
        int v = queue[head++];
        printf("%d ", v);
        for (Edge *e = g->edges[v]; e != NULL; e = e->next) {
            if (visited[e->to] == 0) {
                queue[tail++] = e->to;
                visited[e->to] = 1;
            }
        }
    }
    printf("\n");
}

//深度优先搜索
void dfs(Graph *g, int v0) {
    int *visited = (int *) malloc(sizeof(int) * g->n);
    for (int i = 0; i < g->n; i++) {
        visited[i] = 0;
    }
    int *stack = (int *) malloc(sizeof(int) * g->n);
    int top = 0;
    stack[top++] = v0;
    visited[v0] = 1;
    while (top > 0) {
        int v = stack[--top];
        printf("%d ", v);
        for (Edge *e = g->edges[v]; e != NULL; e = e->next) {
            if (visited[e->to] == 0) {
                stack[top++] = e->to;
                visited[e->to] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    Graph g;
    init(&g, 7);
    insert(&g, 0, 2, 1);
    insert(&g, 0, 5, 1);
    insert(&g, 0, 6, 1);
    insert(&g, 0, 1, 1);
    insert(&g, 1, 3, 1);
    insert(&g, 1, 0, 1);
    insert(&g, 1, 4, 1);
    insert(&g, 1, 2, 1);
    insert(&g, 2, 0, 1);
    insert(&g, 2, 3, 1);
    insert(&g, 2, 6, 1);
    insert(&g, 2, 1, 1);
    insert(&g, 3, 1, 1);
    insert(&g, 3, 2, 1);
    insert(&g, 3, 4, 1);
    insert(&g, 4, 1, 1);
    insert(&g, 4, 3, 1);
    insert(&g, 5, 0, 1);
    insert(&g, 5, 6, 1);
    insert(&g, 6, 2, 1);
    insert(&g, 6, 5, 1);
    insert(&g, 6, 0, 1);
    printf("breadth first search: ");
    bfs(&g, 0);
    printf("depth first search: ");
    dfs(&g, 0);
    return 0;
}
