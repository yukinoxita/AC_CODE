/*
Author  : yukki
Time    : 2020.8.20
OJ      : luogu
Pid     : 2196
 */
#include <cstdio>
/*
f[i] = max{f[j]} + a[i];
f[i] 表示第i个为终点的时候挖地雷的最大值
*/
int n;
int max(int x,int y){return x>y?x:y;}
bool map[30][30];
int a[30];
int pre[30];
int f[30];
void print(int pos)
{
    if(pre[pos] == 0)
    {
        printf("%d",pos);
        return;
    }
    print(pre[pos]);
    printf(" %d",pos);
}
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            int tmp;
            scanf("%d",&tmp);
            if(tmp == 0)map[i][j] = 0;
            else map[i][j] = 1;
        }
    }
    f[1] = a[1];
    int last_point;
    int maxx = 0;
    for(i=2;i<=n;i++)
    {
        for(j=1;j<i;j++)
        {
            if(!map[j][i])continue;
            //符合就刷新
            if(f[i] < f[j] + a[i])
            {
                f[i] = f[j];
                pre[i] = j;
            }
        }
        f[i] += a[i];//最后才能加
        if(maxx < f[i])
        {
            maxx = f[i];
            last_point = i;
        }
    }
    print(last_point);
    printf("\n%d\n",maxx);
	return 0;
}

