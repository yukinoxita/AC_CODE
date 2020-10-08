/*
Author  : yukki
Time    : 2020.9.1
OJ      : luogu
Pid     : 2121
*/
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int n,m,k;
int fa[100002];
struct node
{
    int u,v,w;
};
vector <node> vec;
void addEdge(int x,int y,int z)
{
    vec.push_back({x,y,z});
}
bool cmp(const node & a,const node & b){return a.w > b.w;}
int find(int x){return x == fa[x] ? x : fa[x] = find(fa[x]);}
int kruskal()
{
    vector <node>::iterator it;
    int cnt = 0;
    int ans = 0;
    for(it=vec.begin();it!=vec.end();it++)
    {
        node now = *it;
        int fx = find(now.u);
        int fy = find(now.v);
        if(fx != fy)
        {
            fa[fx] = fy;
            cnt++;
            ans += now.w;
        }
        if(cnt == k)break;
    }
    return ans;
}
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d",&k);
    for(i=1;i<=n;i++)fa[i] = i;
    for(i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        addEdge(x,y,z);
    }
    sort(vec.begin(),vec.end(),cmp);
    cout<<kruskal()<<endl;
    return 0;
}

