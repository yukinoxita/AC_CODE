#include <cstdio>
#include <cstring>
/*
 *思路：反向存图，从大点向小点dfs
 * */
int n,m;
struct Edge
{
    int u,v,nex;
}e[100005];
bool vis[100005];
int ans[100005];
int sit = 0;
int head[100005];
void Add(int x,int y)
{
    e[++sit] = (Edge){x,y,head[x]};
    head[x] = sit;
}
void dfs(int pos,int pre)
{
    vis[pos] = 1;
    ans[pos] = pre;
    int i;
    for(i=head[pos];i!=-1;i=e[i].nex)
    {
        if(!vis[e[i].v])dfs(e[i].v,pre);
    }
}
int main()
{
    register int i;
    scanf("%d%d",&n,&m);
    memset(head,-1,sizeof(head));
    for(i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        Add(y,x);
    }
    for(i=n;i>0;i--)
        if(!vis[i])dfs(i,i);

    for(i=1;i<=n;i++)printf("%d ",ans[i]);
    return 0;
}
