#include <cstdio>
#include <cstring>
int T,n,m;
int  map[250][250];
bool vis[250][250];
int step[4][2]={
    {0,1},
    {1,0},
    {0,-1},
    {-1,0}
};
int ans=0;
int cnt=0;
int maxx(int x,int y)
{
    if(x>y)return x;
    return y;
}
bool inmap(int x,int y)
{
    if(x>=1 && x<=n && y>=1 && y<=m)return true;
    return false;
}
void dfs(int x,int y)
{
    vis[x][y]=1;
    ans=maxx(ans,cnt);
    int i,j;
    int nx,ny;
    for(i=0;i<=3;i++)
    {
        nx=x+step[i][0];
        ny=y+step[i][1];   
        if(!vis[nx][ny] && map[nx][ny]==1 && inmap(nx,ny))
        {cnt++;dfs(nx,ny);}
    }
    ans=maxx(ans,cnt);
}
void test()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(map[i][j]==1)
            {
                if(vis[i][j])printf("1 ");
                else printf("0 ");
            }
            else 
                printf(". ");
        }
        printf("\n");
    }
}
int main()
{
    int i,j;
    //freopen("2.in","r",stdin);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)   
            for(j=1;j<=m;j++)
                scanf("%d",&map[i][j]);

        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {
                if(map[i][j]==1 && !vis[i][j]){cnt++;dfs(i,j);cnt=0;}
            }
        printf("%d",ans);
        if(T)printf("\n");
        //test();
        memset(map,0,sizeof(map));
        memset(vis,0,sizeof(vis));
        ans=0;
    }
    return 0;
}
