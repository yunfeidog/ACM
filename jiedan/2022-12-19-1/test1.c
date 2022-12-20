#include "stdio.h"
#include "string.h"

//统计其中单词的个数。各单词以空格格开，空格数可以是多个。
char str[1000];
int main() {
    int  count = 0, countA = 0;
    scanf("%[^\n]", str);
    int len = strlen(str);
    for(int i=0;i<len;i++){
        if(i==0&&str[i]==' ')
            while (i<len&&str[i]==' ')i++;
        if(i==0&&str[i]=='a') countA++;
        //空格可能是多个
        if(str[i]==' '){
            count++;
            while (i<len&&str[i+1]==' '){
                i++;
            }
        }
        if(str[i]==' '&&str[i+1]=='a') countA++;


    }
    printf("%d %d", count+1, countA);

    return 0;
}
