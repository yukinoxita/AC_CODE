/*
Author  : yukki
Time    : 2020.9.21
OJ      : aoj
Pid     : 1952
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#define  F1(i,n) for(i=1;i<=n;i++)
#define  F0(i,n) for(i=0;i<=n;i++)
#define _F1(i,n) for(i=n;i>=1;i--)
#define _F0(i,n) for(i=n;i>=0;i--)
using namespace std;
int n,m;
int start,endd;
int head[1000000];
bool vis[1000000];
struct node
{
    int u,v,nex;
};
vector <node> vec;
struct point
{
    int p,step;
};
queue <point> q;
void addEdge(int x,int y)
{
    vec.push_back({x,y,head[x]});
    head[x] = vec.size()-1;
}
void bfs()
{
    int i,j;
    bool flag = 0;
    for(i=head[start];i!=-1;i=vec[i].nex)
    {
        q.push({vec[i].v,1});
        //printf("%d\n",vec[i].v);
    }
    vis[start] = 1;
    while(!q.empty())
    {
        point tmp = q.front();
        q.pop();
        vis[tmp.p] = 1;
        if(tmp.p == endd)
        {
            printf("%d\n",tmp.step);
            flag = 1;
            break;
        }
        for(i=head[tmp.p];i!=-1;i=vec[i].nex)
        {
            q.push({vec[i].v,tmp.step+1});
        }
    }
    if(!flag)printf("Connot reach\n");
}
void clear()
{
    while(!q.empty()){q.pop();}
}
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    while(cin>>n>>m>>start>>endd)
    {
        memset(head,-1,sizeof(head));
        memset(vis,0,sizeof(vis));
        vec.clear();
        vec.push_back({0,0,-1});
        clear();
        F1(i,m)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            addEdge(x,y);
            addEdge(y,x);
        }
        bfs();
        /*
        vector <node>::iterator it;
        for(it=vec.begin();it!=vec.end();it++)
        {
            node tmp = *it;
            cout<<tmp.u<<" "<<tmp.v<<" "<<tmp.nex<<enddl;
        }
        */
    }

    return 0;
}

