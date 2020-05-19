#include <cstdio>
#include <cstring>
int n,m,s;
struct Edge
{
    int u,v,w,nex;
}e[500010];
int head[100010];
bool vis[100010];
int sit;
int dis[100010];
void addEdge(int u,int v,int w)
{
    e[++sit] = {u,v,w,head[u]};
    head[u] = sit;
}
void dj(int pos)
{
    dis[pos] = 0;
    int i,j,t;
    for(i=1;i<=n;i++)
    {
        int minn = 2147483647;
        t=-1;
        for(j=1;j<=n;j++)
        {
            if(vis[j])continue;
            if(minn > dis[j])
            {minn = dis[j];t = j;}
        }
        if(t==-1)break;
        vis[t] = 1; //标记
        for( j = head[t] ; j !=-1 ; j = e[j].nex)
        {
            int v= e[j].v;
            if( dis[v] > dis[t] + e[j].w)
                dis[v] = dis[t] + e[j].w;
        }
    }
}
int main()
{
    register int i;
    memset(head,-1,sizeof(head));
    scanf("%d%d%d",&n,&m,&s);
    for(i=1;i<=n;i++)dis[i] = 2147483647;
    for(i=1;i<=m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        addEdge(a,b,c);
    }
    dj(s);
    for(i=1;i<=n;i++)printf("%d ",dis[i]);

    return 0;
}
