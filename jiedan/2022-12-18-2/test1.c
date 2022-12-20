#include "stdio.h"

int a[1010];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
       int x;
         scanf("%d", &x);
            a[x]++;
    }
    //给出一个数组，请你计算数组中仅出现2次的数有多少个,出现超过两次不算
    int ans=0;
    for(int i=0;i<1010;i++){
        if(a[i]==2){
            ans++;
        }
    }
    printf("%d",ans);


    return 0;
}
