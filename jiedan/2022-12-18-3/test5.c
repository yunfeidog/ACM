#include "stdio.h"

int n, m;
int a[10001];


int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) {
        int x,t,l,r;
        scanf("%d", &x);
        switch (x) {
            case 1:
                scanf("%d%d", &l, &r);
                int ans = 0;
                for (int i = l; i <= r; i++) ans = ans * 2 + a[i];
                printf("%d\n", ans);
                break;
            case 2:
                scanf("%d", &t);
                printf("%d\n", a[t]);
                break;
            case 3:
                scanf("%d", &t);
                a[t] ^= 1;
                break;

        }

    }


    return 0;
}
