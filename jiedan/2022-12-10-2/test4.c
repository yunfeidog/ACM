#include "stdio.h"
#include "stdlib.h"

//二叉搜索树的建立
typedef struct node {//二叉搜索树的结点
    int data;//数据域
    struct node *lchild, *rchild;//左右孩子指针
} Node;//二叉搜索树的结点类型

Node *create(int data) {//创建一个结点
    Node *p = (Node *) malloc(sizeof(Node));//申请一个结点的内存空间
    p->data = data;//将数据放入结点中
    p->lchild = p->rchild = NULL;//左右孩子指针置空
    return p;//返回结点
}
//二叉搜索树的插入
Node *insert(Node *root, int data) {
    if (root == NULL) {//如果根结点为空
        return create(data);//创建一个结点
    }
    if (root->data == data) {//如果根结点的数据域等于data
        return root;//返回根结点
    }
    if (root->data > data) {//如果根结点的数据域大于data
        root->lchild = insert(root->lchild, data);//递归插入左子树
    } else {//如果根结点的数据域小于data
        root->rchild = insert(root->rchild, data);//递归插入右子树
    }
    return root;//返回根结点
}

void preorder(Node *root) {//前序遍历
    if (root == NULL) {//如果根结点为空
        return;//返回
    }
    printf("%d ", root->data);//输出根结点的数据域
    preorder(root->lchild);//递归遍历左子树
    preorder(root->rchild);//递归遍历右子树
}

void inorder(Node *root) {//中序遍历
    if (root == NULL) {//如果根结点为空
        return;//返回
    }
    inorder(root->lchild);//递归遍历左子树
    printf("%d ", root->data);//输出根结点的数据域
    inorder(root->rchild);//递归遍历右子树
}

void postorder(Node *root) {//后序遍历
    if (root == NULL) {//如果根结点为空
        return;//返回
    }
    postorder(root->lchild);//递归遍历左子树
    postorder(root->rchild);//递归遍历右子树
    printf("%d ", root->data);//输出根结点的数据域
}

int main() {
    int n;
    scanf("%d", &n);
    Node *root = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);//插入数据
    }
    printf("前序遍历：");
    preorder(root);//前序遍历
    printf("\n");
    printf("中序遍历：");
    inorder(root);//中序遍历
    printf("\n");
    printf("后序遍历：");
    postorder(root);//后序遍历

    //查找数据
    int x;
    scanf("%d", &x);
    Node *p = root;
    while (p != NULL) {//如果p不为空
        if (p->data == x) {//如果p的数据域等于x
            printf("find %d", x);//输出找到x
            break;//跳出循环
        }
        if (p->data > x) {//如果p的数据域大于x
            p = p->lchild;//p指向左孩子
        } else {//如果p的数据域小于x
            p = p->rchild;//p指向右孩子
        }
    }
    if (p == NULL) {//如果p为空
        printf("not find %d", x);//输出未找到x
    }



    return 0;
}

