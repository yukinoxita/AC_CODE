/*
Author  : yukki
Time    : 2020.9.1
OJ      : aoj
Pid     : 2796
*/
#include <cstdio>
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
int n,m;
int T;
set <int> s;
int a[10]={0,2,5,7,10,13,14,17,18};
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    cin>>T;
    while(T--)
    {
        s.clear();
        scanf("%d",&n);
        scanf("%d",&m);
        for(i=1;i<=n;i++)
        {
            int tmp;
            cin>>tmp;
            for(j=1;j<=8;j++)
                s.insert(tmp^(1<<a[j]-1));
        }
        for(i=1;i<=m;i++)
        {
            int tmp;
            cin>>tmp;
            bool flag = 0;
            for(j=1;j<=8;j++)
            {
                if(s.count(tmp^(1<<a[j]-1)) == 0)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag)
                printf("no\n");
            else
                printf("yes\n");
        }
        //printf("\n");
    }
    return 0;
}

