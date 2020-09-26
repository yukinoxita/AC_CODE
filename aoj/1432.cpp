/*
Author  : yukki
Time    : 2020.9.26
OJ      : aoj
Pid     : 1432
*/
#include <cstdio>
#include <list>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int n,m;
list <int> *adj;
int *indegree;
vector <int> ans;
priority_queue <int> q;
void addEdge(int x,int y)
{
    adj[x].push_back(y);
    indegree[y]++;
}
bool topsort()
{
    int i;
    list <int>::iterator it;
    int cnt = 0;
    for(i=1;i<=n;i++)
        if(indegree[i] == 0)q.push(i);

    while(!q.empty())
    {
        int tmp = q.top();
        q.pop();
        ans.push_back(tmp);
        cnt++;
        for(it=adj[tmp].begin();it!=adj[tmp].end();it++)
        {
            indegree[*it]--;
            if(!indegree[*it])q.push(*it);
        }
    }
    if(cnt < n)return 0;
    return 1;
}
int main()
{
    register int i,j;
    int T;
    freopen("in","r",stdin);
    cin>>T;
    while(T--)
    {
        scanf("%d",&n);
        scanf("%d",&m);
        ans.clear();
        adj = new list <int>[n+1];
        indegree = new int[n+1];
        for(i=1;i<=n;i++)indegree[i] = 0;
        for(i=1;i<=m;i++)
        {
            int x,y;
            cin>>x>>y;
            addEdge(x,y);
        }
        if(topsort())
        {
            vector<int>::iterator it;
            for(it=ans.begin();it!=ans.end();it++)
                cout<<*it<<" ";
        }
        else
            cout<<-1;
        cout<<endl;
        delete [] adj;
        delete [] indegree;
    }
    return 0;
}
