#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define scnaf scanf
#define MAXN 1000010
using namespace std;
int n,m;
/*
思路：
由于向量星储存边的规则是head[i]
只记录最后一条边的位置，所以我们
需要先排序再添加边，然后搜索套路    
*/
struct Edge
{
    int u,v,nex;
}e[MAXN];
int head[100050];
bool vis[100050];
int sit;
int start = 999999999;
struct node {int u,v;}aa[MAXN];
int min(int x,int y){return x<y?x:y;}
void ADD(int x,int y)
{
    e[++sit] = (Edge) {x,y,head[x]};
    head[x] = sit;
}
void dfs(int pos)
{
    vis[pos] = 1;
    printf("%d ",pos);
    int i;
    for(i=head[pos];i!=-1;i=e[i].nex)
    {
         
        int v = e[i].v;
        if(!vis[v])dfs(v);
    }
}
void bfs(int start)
{
    queue<int> q;
    q.push(start);
    int i;
    while(!q.empty())
    {
        int pos = q.front();
        q.pop();
        vis[pos] = 1;
        printf("%d ",pos);
        for(i=head[pos];i!=-1;i=e[i].nex)
        {
            int v = e[i].v;
            if(!vis[v]){q.push(v);vis[v] = 1;}
        }
    }
}
bool cmp(const node &a,const node &b)
{
    /*一开始规则写错了wa了4个点*/
    if(a.u == b.u) return a.v > b.v;
    else if(a.u < b.u) return 1;
    else return 0;

}
int main()
{
    register int i;
    scnaf("%d%d",&n,&m);
    for(i=1;i<=n;i++)head[i] = -1;
    for(i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        aa[i].u = a;
        aa[i].v = b;
        start = min(start,a);
        start = min(start,b);
    }
    sort(aa+1,aa+1+m,cmp);
    for(i=1;i<=m;i++)
    {
        //printf("%d %d\n",aa[i].u,aa[i].v);
        ADD(aa[i].u,aa[i].v);
    }
    dfs(start);
    printf("\n");
    memset(vis,0,sizeof(vis));
    bfs(start);
    return 0;
}

