#include "stdio.h"
#include "string.h"

#define N 100

int h[N],e[N],ne[N],idx;

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void init(){
    memset(h,-1,sizeof h);
    idx=0;
    add(1,2);
    add(2,1);
    add(1,3);
    add(3,1);
    add(1,4);
    add(4,1);
    add(2,5);
    add(5,2);
    add(3,2);
    add(2,3);
    add(3,5);
    add(5,3);
    add(3,6);
    add(6,3);
    add(4,6);
    add(6,4);
    add(5,6);
    add(6,5);
}

//遍历图
void dfs(int u){
    printf("%d ",u);
    for(int i=h[u];i!=-1;i=ne[i]){
        int j=e[i];
        dfs(j);
    }
}

int main() {
    init();
    dfs(1);
}