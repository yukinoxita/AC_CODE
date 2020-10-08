/*
Author : yukki
Time   : 2020.9.26
Oj     : luogu
Pid    : 4779
*/
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>
#define INF 0x7fffffff
using namespace std;
int n,m,s;
int* head;
bool* vis;
long long int* dis;
struct node
{
    int u,v,w,nex;
};
vector <node> vec;
priority_queue <pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
void addEdge(int x,int y,int z)
{
    vec.push_back({x,y,z,head[x]});
    head[x] = vec.size() - 1;
}
void dj()
{
    int i;
    for(i=1;i<=n;i++)dis[i] = INF;
    dis[s] = 0;
    q.push(make_pair(0,s));
    while(!q.empty())
    {
        int now = q.top().second;
        q.pop();
        if(vis[now])continue;
        vis[now] = 1;
        for(i=head[now];i!=-1;i=vec[i].nex)
        {
            if(dis[vec[i].v] > dis[now] + vec[i].w)
            {
                dis[vec[i].v] = dis[now] + vec[i].w;
                q. push(make_pair(dis[vec[i].v],vec[i].v));
            }
        }
    }
}
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d",&s);//起点

    head = new int[n+1];
    vis = new bool[n+1];
    dis = new long long int[n+1];
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
    vec.push_back({0,0,0,-1});

    for(i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        addEdge(x,y,z);
        //addEdge(y,x,z);
    }
    dj();
    for(i=1;i<=n;i++)cout<<dis[i]<<" ";
    cout<<endl;
    delete [] dis;
    delete [] vis;
    delete [] head;
    vec.clear();
    return 0;
}
