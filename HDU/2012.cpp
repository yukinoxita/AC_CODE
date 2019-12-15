#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int x,y;
bool vis[3000];
int sit = 0;
bool flag = false;
bool check(int n)
{
    int ans = n*n+n+41;
    if(!vis[ans])return 1;
    return 0;
}
int main()
{
    int i,j;
    for(i=2;i<=2600;i++)
    {
        if(!vis[i])
        for(j=i+i;j<=2600;j+=i)vis[j] = 1;
    }
    //for(i=2;i<=2600;i++)if(!vis[i])printf("%d ",i);
    //freopen("2.in","r",stdin);
    while(1)
    {
        flag = 0;
        scanf("%d%d",&x,&y);
        if(x == 0 && y == 0) break;
        for(i=x;i<=y;i++)
            if(!check(i)){flag = 1;break;}
        if(flag)printf("Sorry\n");
        else printf("OK\n");
    }
    return 0;
}