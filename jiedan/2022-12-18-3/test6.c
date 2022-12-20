#include "stdio.h"


int x1, y1, x2, y2, x3, y3, x4, y4, x, y;

int judge(int x1, int y1, int x, int y) {
    for (int i = x1 - 1; i <= x1 + 1; i++) {
        for (int j = y1 - 1; j <= y1 + 1; j++) {
            if (i >= 1 && i <= 100 && j >= 1 && j <= 100) {
                if (i == x && j == y)return 1;
            }
        }
    }
    return 0;
}


int main() {
    int n, res = 0;
    scanf("%d", &n);
    int last = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        scanf("%d%d%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4, &x, &y);
        cnt += judge(x1, y1, x, y);
        cnt += judge(x2, y2, x, y);
        cnt += judge(x3, y3, x, y);
        cnt += judge(x4, y4, x, y);
        if (cnt == 0) {
            if (last != 1)
                last = 0;
        }else{
            if(last==0){
                last++;
                res=res>last?res:last;
            }else{
                last++;
                res=res>last?res:last;
            }
        }
    }
    printf("%d", res);
    return 0;
}

