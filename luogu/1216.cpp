/*
 *title : 数字三角形
 *
 * */
#include <cstdio>
int f[1002][1002];
int a[1002][1002];
int n;
int ans = 0;
int max(int x,int y){return x>y?x:y;}
int main()
{
    register int i,j;
    freopen("1.in","r",stdin);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=i;j++)scanf("%d",&a[i][j]);

    f[1][1] = a[1][1];
    for(i=2;i<=n;i++)
    {
        for(j=1;j<=i;j++)
            f[i][j] = max(f[i-1][j-1],f[i-1][j]) + a[i][j];
    }
    for(i=1;i<=n;i++)ans = max(ans,f[n][i]);
    printf("%d\n",ans);
    return 0;
}
