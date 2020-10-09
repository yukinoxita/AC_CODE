/*
Author  : yukki
Time    : 2020.10.8
OJ      : luogu
Pid     : 1141
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define  F1(i,n) for(i=1;i<=n;i++)
#define  F0(i,n) for(i=0;i<=n;i++)
#define _F1(i,n) for(i=n;i>=1;i--)
#define _F0(i,n) for(i=n;i>=0;i--)
using namespace std;
int n,m;
int step[4][2]=
{
    {0,1},
    {0,-1},
    {1,0},
    {-1,0}
};
struct node
{
    int x,y;
};
queue <node> q;
char map[1005][1005];
int sit[1005][1005];
bool vis[1005][1005];
vector <int> vec;
inline bool inmap(int x,int y){return x>=1 && x<=n && y>=1 && y<=n;}
void bfs(int x,int y,int pos)
{
    int cnt = 0;
    q.push({x,y});
    vis[x][y] = 1;
    while(!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        cnt++;
        sit[x][y] = pos;
        for(int i=0;i<4;i++)
        {
            int nx = x+step[i][0];
            int ny = y+step[i][1];
            if(!vis[nx][ny] && inmap(nx,ny) && map[nx][ny] != map[x][y])
            {
                vis[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }
    vec.push_back(cnt);
}
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    scanf("%d",&n);
    scanf("%d",&m);
    for(i=1;i<=n;i++)
        cin>>map[i]+1;
    int cnt = 0;
    vec.push_back(0);
    memset(vis,0,sizeof(vis));
    while(m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(sit[a][b])
        {
            printf("%d\n",vec[sit[a][b]]);
        }
        else
        {
            cnt++;
            bfs(a,b,cnt);
            printf("%d\n",vec[sit[a][b]]);
        }
    }
    return 0;
}

