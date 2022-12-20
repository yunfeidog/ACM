#include "stdio.h"

int a[10010];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    while (m--) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            //输出区间l,r的十进制表示
            int l, r;
            scanf("%d%d", &l, &r);
            int ans = 0;
            for (int i = l - 1; i < r; i++) {
                ans = ans * 2 + a[i];
            }
            printf("%d\n", ans);
        } else if (op == 2) {
            int x;
            scanf("%d", &x);
            //判断第x位是不是1
            if (a[x-1] == 1) {
                printf("1\n");
            } else {
                printf("0\n");
            }

        } else {
            int x;
            scanf("%d", &x);
            //将第x位取反
            a[x - 1] ^= 1;
            //输出第x位的值
            printf("%d\n", a[x - 1]);
        }
    }

    return 0;
}
