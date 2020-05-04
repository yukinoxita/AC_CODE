#include <cstdio>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
int fa[20002];
map<string,int> ma;
int k;
int n,m;
string s,s1;
int find(int pos)
{
    if(fa[pos] == pos)return pos;
    fa[pos] = find(fa[pos]);//优化
    return fa[pos];
}
void unione(int a,int b)
{
    int x = find(a);
    int y = find(b);
    if(x != y);
        fa[y] = x;
}
int main()
{
    register int i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        cin>>s;
        ma[s] = i;
        fa[i] = i;
    }
    for(i=1;i<=m;i++)
    {
        cin>>s>>s1;
        unione(ma[s],ma[s1]);
    }
    scanf("%d",&k);
    for(i=1;i<=k;i++)
    {
        cin>>s1>>s;
        if(find(ma[s1]) == find(ma[s]))printf("Yes.\n");
        else printf("No.\n");
    }
    return 0;
}
