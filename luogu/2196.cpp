#include <cstdio>
/*
f[i] = max{f[j]} + a[i];
f[i] 表示第i个为终点的时候挖地雷的最大值

*/
bool toori[21][21];
int n;
int a[21];
int f[21];
int ans[21];
int max;
int t;
void print(int pos)
{
    if(ans[pos] == 0)
    {
        printf("%d", pos);
        return ;
    }
    print(ans[pos]);
    printf(" %d",pos);
}
int main()
{
    register int i,j;
 //   freopen("1.in","r",stdin);
    scanf("%d",&n);
    for(i=1;i<=n;i++){scanf("%d",&a[i]);}//f[i] = a[i];}
    for(i=1;i<n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            int tmp;
            scanf("%d",&tmp);
            if(tmp)toori[i][j] = 1;
        }
    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(toori[j][i] && f[j]>f[i])
            {
                f[i] = f[j];
                ans[i] = j;
            }
        }
        f[i] += a[i];
        if(max < f[i])
        {
            max = f[i];
            t = i;
        }
    }
    print(t);
    printf("\n%d\n",max);
    return 0;
}