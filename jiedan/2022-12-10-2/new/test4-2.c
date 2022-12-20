#include "stdio.h"
#include "stdlib.h"

#define MAX 100
#define INF 0x3f3f3f3f

//二叉树
typedef struct Node {
    int data;
    struct Node *lchild, *rchild;
} Node;


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



Node *getNewNode(int data) {
    Node *p = (Node *) malloc(sizeof(Node));
    p->data = data;
    p->lchild = p->rchild = NULL;
    return p;
}

Node *insertTree(Node *root, int data) {
    if (root == NULL) {
        return getNewNode(data);
    }
    if (root->data == data) {
        return root;
    }
    if (root->data > data) {
        root->lchild = insertTree(root->lchild, data);
    } else {
        root->rchild = insertTree(root->rchild, data);
    }
    return root;
}

void preorder(Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}

void inorder(Node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->lchild);
    printf("%d ", root->data);
    inorder(root->rchild);
}

void postorder(Node *root) {
    if (root == NULL) {
        return;
    }
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d ", root->data);
}

void clear(Node *root) {
    if (root == NULL) {
        return;
    }
    clear(root->lchild);
    clear(root->rchild);
    free(root);
}

//图的广度优先搜索建立二叉树
Node *buildTree(Graph *g, int v0) {
    int *visited = (int *) malloc(sizeof(int) * g->n);
    for (int i = 0; i < g->n; i++) {
        visited[i] = 0;
    }
    int *queue = (int *) malloc(sizeof(int) * g->n);
    int head = 0, tail = 0;
    queue[tail++] = v0;
    visited[v0] = 1;
    Node *root = NULL;
    while (head < tail) {
        int v = queue[head++];
        root = insertTree(root, v);
        for (Edge *e = g->edges[v]; e != NULL; e = e->next) {
            if (visited[e->to] == 0) {
                queue[tail++] = e->to;
                visited[e->to] = 1;
            }
        }
    }
    return root;
}

//图的深度优先搜索建立二叉树
Node *buildTree2(Graph *g, int v0) {
    int *visited = (int *) malloc(sizeof(int) * g->n);
    for (int i = 0; i < g->n; i++) {
        visited[i] = 0;
    }
    int *stack = (int *) malloc(sizeof(int) * g->n);
    int top = -1;
    stack[++top] = v0;
    visited[v0] = 1;
    Node *root = NULL;
    while (top != -1) {
        int v = stack[top--];
        root = insertTree(root, v);
        for (Edge *e = g->edges[v]; e != NULL; e = e->next) {
            if (visited[e->to] == 0) {
                stack[++top] = e->to;
                visited[e->to] = 1;
            }
        }
    }
    return root;
}



int main() {
    Graph g;
    init(&g, 5);

    insert(&g, 1, 2, 1);
    insert(&g, 1, 3, 1);
    insert(&g, 2, 3, 1);
    insert(&g, 2, 4, 1);
    insert(&g, 2, 5, 1);
    insert(&g, 3, 4, 1);
    insert(&g, 4, 5, 1);
    insert(&g, 5, 1, 1);
    insert(&g, 5, 3, 1);
    Node *root = NULL;
    buildTree(&g, 1);
    preorder(root);
    root = NULL;
    buildTree2(&g, 1);
    preorder(root);
    return 0;
}

