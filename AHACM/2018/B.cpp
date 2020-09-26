/*
Author  : yukki
Time    : 2020.9.7
OJ      : AHACM
Pid     : B
*/
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
const int maxn = 1e5+5;
int n,t;
map <string,int> m;
map <string,int>::iterator iter;
struct node
{
    int u,v,nex;
}e[maxn];
int head[maxn];
bool vis[maxn];
int sit = 0;//存放边
void addEdge(int u,int v)
{
    e[++sit] = {u,v,head[u]};
    head[u] = sit;
}
bool flag = 0;
void dfs(int pos)
{
    int i;
    vis[pos] = 1;
    for(i=head[pos];i!=-1;i=e[i].nex)
    {
        int v = e[i].v;
        //printf("%d ",v);
        if(!vis[v]){dfs(v);vis[v] = 0;}
        else flag = 1;
    }
}
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int cnt_p = 0;
        //初始化
        flag = 0;
        sit = 0;
        memset(head,-1,sizeof(head));
        m.clear();

        for(i=1;i<=n;i++)
        {
            string tmp,tmp1;
            cin>>tmp>>tmp1;
            if(m.count(tmp) == 0)
            {
                //s.insert(tmp);
                m.insert(make_pair(tmp,++cnt_p));
            }
            if(m.count(tmp1) == 0)
            {
                //s.insert(tmp1);
                m.insert(make_pair(tmp1,++cnt_p));
            }
            //cout<<m[tmp]<<" "<<m[tmp1]<<endl;
            addEdge(m[tmp],m[tmp1]);
        }
        //cout<<endl;
        for(i=1;i<=cnt_p;i++)
        {
            dfs(i);
            memset(vis,0,sizeof(vis));
            if(flag){printf("Failed\n");break;}
        }//搜索从i点是否有环
        if(!flag)printf("Passed\n");
    }
	return 0;
}

