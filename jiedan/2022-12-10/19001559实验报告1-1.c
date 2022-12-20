#include "stdio.h"

//计算C(m,n)的值
int f(int m, int n)
{
    if (m == n || n == 0)
        return 1;
    else
        return f(m - 1, n - 1) + f(m - 1, n);
}


int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d", f(n, m));
    return 0;
}
