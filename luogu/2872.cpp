/*
Author  : yukki
Time    : 2020.10.3
OJ      : luogu
Pid     : 2872
*/
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
int n,m;
struct point
{
    int x,y;
}P[1020];
struct node
{
    int u,v;
    double w;
};
vector <node> vec;
int fa[1020];
double juli(int a,int b)
{
    double ans = 0.0;
    ans =  (double)sqrt((double)(P[a].x - P[b].x)*(P[a].x - P[b].x) + (double)(P[a].y - P[b].y)*(P[a].y - P[b].y));
    return ans;
}
bool cmp(const node & a,const node & b)
{
    if(a.w == b.w)return a.u < b.u;
    return a.w<b.w;
}
void addEdge(int x,int y,double w)
{
    vec.push_back({x,y,w});
}
int find(int num){return num == fa[num]?num:fa[num]=find(fa[num]);}
double kruskal()
{
    double ans = 0.0;
    int cnt = 0;
    vector <node>::iterator it;
    for(it=vec.begin()+1;it!=vec.end();it++)
    {
        node t = *it;
        int fu = find(t.u);
        int fv = find(t.v);
        if(fu != fv)
        {
            ans += t.w;
            fa[fu] = fv;
            cnt++;
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

    for(i=1;i<=n;i++)fa[i] = i;
    vec.clear();
    vec.push_back({0,0,0.0});

    for(i=1;i<=n;i++)
        scanf("%d%d",&P[i].x,&P[i].y);

    for(i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        addEdge(x,y,0.0);
    }

    for(i=1;i<n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            double len = juli(i,j);
            addEdge(i,j,len);
        }
    }
    sort(vec.begin()+1,vec.end(),cmp);
    printf("%.2lf\n",kruskal());
    return 0;
}
