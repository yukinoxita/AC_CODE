/*
Author  : yukki
Time    : 2020.9.23
OJ      : aoj
Pid     : 1954
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#define  F1(i,n) for(i=1;i<=n;i++)
#define  F0(i,n) for(i=0;i<=n;i++)
#define _F1(i,n) for(i=n;i>=1;i--)
#define _F0(i,n) for(i=n;i>=0;i--)
using namespace std;
int n,m;
int hitsuji,ookami;
int tmp_h,tmp_o;
bool vis[5000][5000];
char map[5000][5000];
int step[4][2]=
{
    {0,1},
    {1,0},
    {-1,0},
    {0,-1}
};
bool inmap(int x,int y){return (x>=0 && x<n && y>=0 && y<m);}
void dfs(int x,int y)
{
    int i;
    vis[x][y] = 1;
    if(map[x][y] == 'o')tmp_h++;
    if(map[x][y] == 'v')tmp_o++;
    F0(i,3)
    {
        int nx = x + step[i][0];
        int ny = y + step[i][1];
        if(inmap(nx,ny) && !vis[nx][ny] && map[nx][ny] != '#')dfs(nx,ny);
    }
}
void cnm(int x,int y)
{
    int i;
    map[x][y] = '#';
    F0(i,3)
    {
        int nx = x + step[i][0];
        int ny = y + step[i][1];
        if(inmap(nx,ny) && map[nx][ny] != '#'){cnm(nx,ny);continue;}
    }
}
void print()
{
    int i;
    F0(i,n-1)
        cout<<map[i]<<endl;
}
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    while(cin>>n>>m)
    {
        memset(map,0,sizeof(map));
        memset(vis,0,sizeof(vis));
        hitsuji = 0;
        ookami  = 0;
        F0(i,n-1)cin>>map[i];
        F0(i,m-1)
        {
            if(map[0][i] != '#')cnm(0,i);
            if(map[n-1][i] != '#')cnm(n-1,i);
        }
        F0(i,n-1)
        {
            if(map[i][0] != '#')cnm(i,0);
            if(map[i][m-1] != '#')cnm(i,m-1);
        }
        F0(i,n-1)
        {
            F0(j,m-1)
            {
                if(!vis[i][j] && map[i][j] != '#')
                {
                    tmp_h = 0;
                    tmp_o = 0;
                    dfs(i,j);
                    hitsuji += (tmp_h>tmp_o?tmp_h:0);
                    ookami += (tmp_o>=tmp_h?tmp_o:0);
                }
            }
        }
        printf("%d %d\n",hitsuji,ookami);
        print();
    }
    return 0;
}

