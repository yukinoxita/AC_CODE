/*
Author  : yukki
Time    : 2020.8.6
OJ      : luogu
Pid     : 2670
 */
#include <cstdio>

#define scnaf scanf
int n,m;
char map[150][150];
int ans[150][150];
inline void update(int x,int y)
{
    ans[x-1][y]++;
    ans[x+1][y]++;
    ans[x][y+1]++;
    ans[x][y-1]++;
    ans[x-1][y-1]++;
    ans[x+1][y+1]++;
    ans[x+1][y-1]++;
    ans[x-1][y+1]++;
}
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%s",&map[i][1]);

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)//printf("%c",map[i][j]);
        {
            if(map[i][j] == '*')update(i,j);
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(map[i][j] == '*')printf("*");
            else
                printf("%d",ans[i][j]);
        }
        printf("\n");
    }
	return 0;
}

