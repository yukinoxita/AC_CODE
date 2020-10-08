/*
Author  : yukki
Time    : 2020.10.8
OJ      : aoj
Pid     : 2795
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#define  F1(i,n) for(i=1;i<=n;i++)
#define  F0(i,n) for(i=0;i<=n;i++)
#define _F1(i,n) for(i=n;i>=1;i--)
#define _F0(i,n) for(i=n;i>=0;i--)
using namespace std;
int T;
int n,m;
int mx[1000005];
int mn[1000005];
int su[1000005];
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    cin>>T;
    while(T--)
    {
        scanf("%d",&n);
        memset(mx,0,sizeof(mn));
        memset(mn,0x3f,sizeof(mn));
        F1(i,n)
            scanf("%d",su+i);
        mx[1] = su[1];
        mn[n] = su[n];
        for(i=2;i<n;i++)
            mx[i] = max(mx[i-1],su[i-1]);
        for(i=n-1;i>=2;i--)
            mn[i] = min(mn[i+1],su[i+1]);
        int ans = 0;
        for(i=2;i<n;i++)
            ans = max(max(0,mx[i]-su[i])+max(su[i]-mn[i],0),ans);

        printf("%d\n",ans);
    }
    return 0;
}
