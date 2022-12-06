#include<stdio.h>
#include<math.h>
#define N 110
double map[N][N]={};
int n;
int gauss()
{
    int c,f;
    for(c=0,f=0;c<n;c++)
    {
        int t=f;
        for(int i=f;i<n;i++)
        {
            if(fabs(map[i][c])>fabs(map[t][c]))
                t=i;
        }
        if(fabs(map[t][c]) < 1e-6)  continue;

        for(int i=c;i<n+1;i++)
        {
            double temp=map[t][i];
            map[t][i]=map[f][i];
            map[f][i]=temp;
        }

        for(int i=n;i>=c;i--)  map[f][i]/=map[f][c];

        for(int i=f+1;i<n;i++)
        {
            if(fabs(map[i][c])>1e-6)
                for(int j=n;j>=c;j--)
                    map[i][j]-=map[f][j]*map[i][c];
        }
        f++;
    }
    if(f<n)
    {
        for(int i=f;i<n;i++)
            if(map[i][n]>1e-6)
                return 2;
        return 1;
    }
    for(int i=n-1;i>=0;i--)
        for(int j=i+1;j<n;j++)
            map[i][n]-=map[j][n]*map[i][j];
    return 0;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<=n;j++)
            scanf("%lf",&map[i][j]);
    int d=gauss();
    if(d==2)
        printf("No solution");
    else if(d==1)
        printf("Infinite group solutions");
    else
        for(int i=0;i<n;i++)
            printf("%.2lf\n",map[i][n]);
}