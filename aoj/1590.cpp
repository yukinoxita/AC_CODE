/*
Author  : yukki
Time    : 2020.9.12
OJ      : AOJ
Pid     : 1590
*/
#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
#define  F1(i,n) for(i=1;i<=n;i++)
#define  F0(i,n) for(i=0;i<=n;i++)
#define _F1(i,n) for(i=n;i>=1;i--)
#define _F0(i,n) for(i=n;i>=0;i--)
using namespace std;
struct node
{
    int x,y,step;
};
queue <node> q;
bool map[120][120];
bool vis[120][120];
int s[4][2]=
{
    {1,0},
    {0,1},
    {-1,0},
    {0,-1}
};
int sx,sy,ex,ey;
int n,m;
bool flag;
inline bool inmap(int x,int y){return (x>=1 && x<=n && y>=1 && y<=m);}
void bfs()
{
    node tmp = {sx,sy,0};
    q.push(tmp);
    while(!q.empty())
    {
        tmp = q.front();
        vis[tmp.x][tmp.y] = 1;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = tmp.x + s[i][0];
            int ny = tmp.y + s[i][1];
            if(nx == ex && ny == ey)
            {
                printf("%d\n",tmp.step+1);
                flag = 1;
                q = queue <node>();
                break;
            }
            if(!vis[nx][ny] && !map[nx][ny] && inmap(nx,ny))
            {
                q.push({nx,ny,tmp.step+1});
            }
        }
    }
    if(!flag){printf("No Way!\n");}
}
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    while(cin>>n>>m)
    {
        memset(map,0,sizeof(map));
        memset(vis,0,sizeof(vis));
        flag = 0;
        q = queue <node>();
        F1(i,n)
        {
            F1(j,m)
            {
                int tmp;
                cin>>tmp;
                if(tmp != 0)map[i][j] = 1;
            }
        }
        cin>>sx>>sy>>ex>>ey;
        bfs();
    }
    return 0;
}

