/*
Author  : yukki
Time    : 2020.9.1
OJ      : aoj
Pid     : 1584
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#define  F1(i,n) for(i=1;i<=n;i++)
#define  F0(i,n) for(i=0;i<=n;i++)
#define _F1(i,n) for(i=n;i>=1;i--)
#define _F0(i,n) for(i=n;i>=0;i--)
using namespace std;
int n,m;
int sx,sy;
bool vis[60][60];
char map[60][60];
int step[5][2]=
{
    {0,0},
    {1,0},
    {0,1},
    {-1,0},
    {0,-1}
};
int ans;
int max(int x,int y){return x>y?x:y;}
int ue(int x,int y)
{
    int i;
    int cnt = 0;
    for(i=x-1;i>=0;i--)
    {
        if(map[i][y] == 'G')cnt++;
        if(map[i][y] == '#')break;
    }
    return cnt;
}
int shita(int x,int y)
{
    int i;
    int cnt = 0;
    for(i=x+1;i<=n;i++)
    {
        if(map[i][y] == 'G')cnt++;
        if(map[i][y] == '#')break;
    }
    return cnt;
}
int hidari(int x,int y)
{
    int i;
    int cnt = 0;
    for(i=y-1;i>=0;i--)
    {
        if(map[x][i] == 'G')cnt++;
        if(map[x][i] == '#')break;
    }
    return cnt;
}
int migi(int x,int y)
{
    int i;
    int cnt = 0;
    for(i=y+1;i<=m;i++)
    {
        if(map[x][i] == 'G')cnt++;
        if(map[x][i] == '#')break;
    }
    return cnt;
}
void print()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            printf("%c",map[i][j]);
        printf("\n");
    }
    
}
bool in_map(int x,int y){return (x>=0 && x<n && y>=0 && y<m);}
void dfs(int x,int y)
{
    int i;
    vis[x][y] = 1;
    for(i=1;i<=4;i++)
    {
        int nx,ny;
        nx = x + step[i][0];
        ny = y + step[i][1];
        if(in_map(nx,ny) && !vis[nx][ny] && map[nx][ny] == '.')
            dfs(nx,ny);
    }
}
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    while(cin>>n>>m>>sx>>sy)
    {
        ans = 0;
        memset(map,0,sizeof(map));
        memset(vis,0,sizeof(vis));
        F0(i,n-1)cin>>map[i];
        dfs(sx,sy);
        //print();
        F0(i,n-1)
        {
            F0(j,m-1)
            {
                if(map[i][j] == '.' && vis[i][j])
                {
                    int cnt = 0;
                    cnt += ue(i,j);
                    cnt += shita(i,j);
                    cnt += migi(i,j);
                    cnt += hidari(i,j);
                    ans = max(ans,cnt);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

