/*
Author  : yukki
Time    : 2020.9.12
OJ      : aoj
Pid     : 1587
*/
#include <cstdio>
#define  F1(i,n) for(i=1;i<=n;i++)
#define  F0(i,n) for(i=0;i<=n;i++)
#define _F1(i,n) for(i=n;i>=1;i--)
#define _F0(i,n) for(i=n;i>=0;i--)
/*
    多组输入个P
*/
int n,m;
int map[120][120];
int sx,sy;
int ans = 0;
bool vis[120][120];
int s[4][2]=
{
    {1,0},
    {0,1},
    {-1,0},
    {0,-1}
};
bool inmap(int x,int y){return (x>=1 && x<=n && y>=1 && y<=m);}
void dfs(int x,int y)
{
    ans++;
    vis[x][y] = 1;
    int i;
    F0(i,3)
    {
        int nx = x + s[i][0];
        int ny = y + s[i][1];
        if(map[nx][ny] != 0 && !vis[nx][ny] && inmap(nx,ny))
            dfs(nx,ny);
    }
}
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d%d",&sx,&sy);
    F1(i,n)
    {
        F1(j,m)
        {
            scanf("%d",&map[i][j]);
        }
    }
    dfs(sx,sy);
    printf("%d\n",ans);
    return 0;
}

