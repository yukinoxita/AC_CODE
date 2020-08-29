/*
Author  : yukki
Time    : 2020.8.20
OJ      : luogu
Pid     : 1216
 */
#include <cstdio>

#define scnaf scanf
int n;
int a[1001][1001];
int f[1001][1001];
int rec[1001][1001];
int pos;
int max(int x,int y){return x>y?x:y;}
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
            scanf("%d",&a[i][j]);
    }
    for(i=n;i>=1;i--)
    {
        for(j=1;j<=i;j++)
        {
            /*
            if(f[i+1][j] > f[i+1][j+1])rec[i][j]=0;
            else rec[i][j]=1;
            */
            f[i][j] = max(f[i+1][j],f[i+1][j+1]) + a[i][j];
        }
    }
    printf("%d\n",f[1][1]);
    /*
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
            printf("%d ",rec[i][j]);
        printf("\n");
    }
    printf("\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }

    pos = 1;
    for(i=1;i<=n;i++)
    {
        printf("%d\n",a[i][pos]);
        pos += rec[i][pos];
    }
    */
	return 0;
}

