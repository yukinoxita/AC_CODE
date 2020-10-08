/*
Author  : yukki
Time    : 2020.10.8
OJ      : aoj
Pid     : 1437
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#define  F1(i,n) for(i=1;i<=n;i++)
#define  F0(i,n) for(i=0;i<=n;i++)
#define _F1(i,n) for(i=n;i>=1;i--)
#define _F0(i,n) for(i=n;i>=0;i--)
#define INF 0x7f7f7f7f
using namespace std;
int n,m,k;
const int maxn = 505;
namespace subtask1
{
    bool Vis[maxn*2],Visf[maxn*2];
    vector<int> ed[maxn*2];
    int q[maxn*2];
    void add(int u,int v)
    {
        ed[u].push_back(v);
    }
    int other(int x)
    {
        if(x<=n) return x+n;else return x-n;
    }
    int bfs(int x)
    {
        for(int i=1;i<=n+n;i++) Visf[i]=Vis[i];
        int beg=1,en=1;
        q[1]=x;
        Visf[x]=true;
        while(beg<=en)
        {
            x=q[beg++];
            for(int i=0;i<ed[x].size();i++)
                if(!Visf[ed[x][i]])
                {
                    if(Visf[other(ed[x][i])]) return 1;
                    Visf[ed[x][i]]=true;
                    q[++en]=ed[x][i];
                }
        }
        return 0;
    }
    void mark(int x)
    {
        int beg=1,en=1;
        q[1]=x;
        Vis[x]=true;
        while(beg<=en)
        {
            x=q[beg++];
            for(int i=0;i<ed[x].size();i++)
                if(!Vis[ed[x][i]])
                {
                    Vis[ed[x][i]]=true;
                    q[++en]=ed[x][i];
                }
        }
    }
    void solve()
    {
        for(int i=1;i<=n+n;i++) ed[i].clear();
        for(int i=1;i<=k;i++)
        {
            int op,u,v;
            scanf("%d%d%d",&op,&u,&v);
            if(op==1)
            {
                add(u,v);
                add(v+n,u+n);
            }
            if(op==2)
            {
                add(u+n,v);
                add(v+n,u);
            }
            if(op==3)
            {
                add(u,v+n);
                add(v,u+n);
            }
            if(op==4)
            {
                add(u+n,v);
                add(v+n,u);
            }
            if(op==5)
            {
                add(u,v);
                add(v+n,u+n);
                add(u+n,v+n);
                add(v,u);
            }
        }
        for(int i=1;i<=n+n;i++) Vis[i]=false;
        for(int i=1;i<=n;i++)
        {
            if((!Vis[i])&&(!Vis[i+n]))
            {
                if(bfs(i+n)==0)
                {
                    mark(i+n);
                } else
                if(bfs(i)==0)
                {
                    mark(i);
                } else
                {
                    puts("impossible.");
                    return;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(Vis[i]) putchar('1');else putchar('0');
            if(i<n) putchar(' '); else putchar('\n');
        }
    }
}
struct node
{
    int u,v,w,nex;
};
int head[600];
int dis[600];
bool vis[600];
bool visit[600];//dfs*用
vector <node> vec;
vector <int> path[600];
vector <int> ans;
int cnt;
priority_queue <pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
void addEdge(int x,int y,int z)
{
    vec.push_back({x,y,z,head[x]});
    head[x] = vec.size() - 1;
}
void dijkstra(int pos)
{
    for(int i=1;i<=n;i++)dis[i] = INF;
    dis[pos] = 0;
    q.push({0,pos});
    while(!q.empty())
    {
        int now = q.top().second;
        q.pop();
        if(vis[now])continue;
        vis[now] = 1;
        for(int i=head[now];i!=-1;i=vec[i].nex)
        {
            if(dis[vec[i].v] > dis[now] + vec[i].w)
            {
                dis[vec[i].v] = dis[now] + vec[i].w;
                path[vec[i].v].clear();
                path[vec[i].v].push_back(now);
                q.push({dis[vec[i].v],vec[i].v});
                continue;
            }
            if(dis[vec[i].v] == dis[now] + vec[i].w)
            {
                path[vec[i].v].push_back(now);
                q.push({dis[vec[i].v],vec[i].v});
            }
        }
    }
}
void dfs2(int pos)
{
    int i,j;
    for(i=0;i<path[pos].size();i++)
    {
        if(!visit[path[pos][i]])
        {
            ans.push_back(path[pos][i]);
            if(path[pos][i] == 1)
            {
                cnt++;
                //cout<<"the"<<cnt<<" : ";
                //for(j=ans.size()-1;j>=0;j--)cout<<ans[j]<<" ";
                //cout<<endl;
            }
            if(path[pos][i] != 1)
                visit[path[pos][i]] = 1;
            dfs2(path[pos][i]);
            //visit[path[pos][i]] = 0; i ra na i
            ans.pop_back();
        }
    }
}
void dfs1(int pos)
{
    int i,j;
    for(i=0;i<path[pos].size();i++)
    {
        ans.push_back(path[pos][i]);
        if(path[pos][i] == 1)
        {
            cnt++;
            //cout<<"the"<<cnt<<" : ";
            //for(j=ans.size()-1;j>=0;j--)cout<<ans[j]<<" ";
            //cout<<endl;
        }
        int tmp = path[pos][i];
        //dfs(path[pos][i]);
        dfs1(tmp);
        ans.pop_back();
    }
}
void dfs(int pos)
{
    int i,j;
    /*
        1 a b ：表示如果攻打城池a，则必须攻打城池b
        2 a b ：表示城池a,b至少攻打一个
        3 a b ：表示如果城池a攻打了，则城池b不能攻打
        4 a b ：表示如果城池a没有攻打，则城池b必须攻打
        5 a b ：表示城池a与城池b只能都攻打或者都不攻打
    */
    //kekka[pos] = 0;
    for(i=pos-1;i>=1;i--)
    {
        
    }
    dfs(pos+1);
    //kekka[pos] = 1;
    dfs(pos+1);

}
int main()
{
    register int i,j;
    int T;
    freopen("in","r",stdin);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&k);

        vec.clear();
        ans.clear();
        cnt = 0;//最短路数量
        for(i=1;i<=n;i++)path[i].clear();
        while(!q.empty())q.pop();
        vec.push_back({0,0,0,-1});
        memset(head,-1,sizeof(head));
        memset(dis,0,sizeof(dis));
        memset(vis,0,sizeof(vis));
        memset(visit,0,sizeof(visit));

        F1(i,m)
        {
            int x,y,z;
            cin>>x>>y>>z;
            addEdge(x,y,z);
        }
        /*
        F1(i,k)
        {
            int flag,a,b;
            cin>>flag>>a>>b;
            kankei[a][b] = flag;
            kankei[b][a] = flag;
        }*/
        subtask1::solve();//copy某位老哥的，这个我确实不会，而且没看懂
        dijkstra(1);
        if(dis[n] == 0x7f7f7f7f)
        {
            cout<<-1<<endl<<-1<<endl;
            continue;
        }
        /*
        cout<<"ans = "<<dis[n]<<endl;
        for(i=1;i<=n;i++)
        {
            cout<<i<<" : ";
            for(j=0;j<path[i].size();j++)
            {
                cout<<path[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        ans.push_back(n);
        dfs1(n);
        cout<<cnt<<endl;
        cnt = 0;
        dfs2(n);
        cout<<cnt<<endl;
    }

    return 0;
}
