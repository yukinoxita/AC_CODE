#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#define xx tmp.x
#define yy tmp.y
#define pp tmp.power
#include <queue>
using namespace std;
//int map[1002][1002];
/*
用更新数组方法试一试
*/
char map[1002][1002];
int ans[1002][1002];
bool vis[1002][1002];
int step[8][2]=
{
    -1,0,
    -1,1,
    0,1,
    1,1,
    1,0,
    1,-1,
    0,-1,
    -1,-1
};
int n,m;
int sx,sy,tx,ty;
int que;
struct point
{
    int x,y,power,check; 
    bool operator < (const point &a) const 
    { 
        return power>a.power;//最小值优先 
    } 
};
priority_queue<point> q;
bool inmap(int x,int y){return x>0 && y>0 && x<=n && y<=m;}
void bfs()
{
    register int i,j;
    int nx,ny,nt;
    memset(ans,0x7f,sizeof(ans));
    //memset(vis,0,sizeof(vis));
    q = priority_queue<point>();
    //vis[sx][sy] = 1;
    ans[sx][sy] = 0;//显然
    q.push((point){sx,sy,0});
    while(!q.empty())
    {
        point tmp = q.top();
        //if(ans[xx][yy] > pp)ans[xx][yy] = pp;
        q.pop();
        //if(xx == tx && yy == ty){printf("%d\n",ans[tx][ty]);return;}
        //if(xx == tx && yy == ty){printf("%d\n",pp);return;}
        for(i=0;i<8;i++)       
        {
            nx = xx + step[i][0];
            ny = yy + step[i][1];
            nt = pp + (i != map[xx-1][yy-1]-'0');
            //if(!vis[nx][ny] && inmap(nx,ny))
            if(nt < ans[tx][ty] && nt < ans[nx][ny] && inmap(nx,ny))
            {
                if(nx != tx || ny != ty)
                    q.push((point) {nx,ny,nt});
                ans[nx][ny] = nt;
                //vis[xx][yy] = 1;
            }
        }
    }
    printf("%d\n",ans[tx][ty]);
}
int main()
{
    register int i,j;
    //freopen("1.in","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<n;i++)cin>>map[i];
        scanf("%d",&que);
        for(i=1;i<=que;i++)
        {
            scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
            if(sx==tx && sy==ty){printf("0\n");continue;}
            bfs();
        }
    }
    return 0;
}
