/*
Author  : yukki
Time    : 2020.9.1
OJ      : luogu
Pid     : 1194
*/
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int fa[550];
struct node
{
    int u,v,w;
};
vector <node> vec;
void addEdge(int x,int y,int z)
{
    vec.push_back({x,y,z});
}
bool cmp(const node & a,const node & b){return a.w<b.w;}
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int kruskal()
{
    vector <node>::iterator it;
    int ans = 0;
    int cnt = 0;
    for(it=vec.begin();it!=vec.end();it++)
    {
        node tmp = *it;
        int fx = find(tmp.u);
        int fy = find(tmp.v);
        if(fx != fy)
        {
            cnt++;
            ans += tmp.w;
            fa[fx] = fy;
        }
        if(cnt == n-1)break;
    }
    return ans;
}
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    scanf("%d",&n);
    scanf("%d",&m);
    if(m == 1){printf("%d\n",n);return 0;}
    if(m == 2)
    {
        int tmp;
        int ans = 0;
        scanf("%d",&tmp);
        scanf("%d",&tmp);
        scanf("%d",&tmp);
        ans = tmp + n;
        scanf("%d",&tmp);
        if(ans > (n<<1))ans = (n<<1);
        printf("%d\n",ans);
        return 0;
    }
    vec.clear();
    for(i=1;i<=m;i++)fa[i] = i;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=m;j++)
        {
            int tmp;
            scanf("%d",&tmp);
            if(i<j && tmp != 0)//没有优惠不建边
            {
                addEdge(i,j,tmp);
            }
        }
    }
    sort(vec.begin(),vec.end(),cmp);
    int ans = kruskal() + n;
    if(ans > (n*m))ans = n*m;//判断直接买是不是更便宜
    printf("%d\n",ans);
    return 0;
}

