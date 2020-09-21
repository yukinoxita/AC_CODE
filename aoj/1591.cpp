/*
Author  : yukki
Time    : 2020.9.12
OJ      : aoj
Pid     : 1591
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define  F1(i,n) for(i=1;i<=n;i++)
#define  F0(i,n) for(i=0;i<=n;i++)
#define _F1(i,n) for(i=n;i>=1;i--)
#define _F0(i,n) for(i=n;i>=0;i--)
using namespace std;
int n,m;
int a[100100];
int b[100100];
int f[100100];
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    while(cin>>n)
    {
        memset(f,0x3f,sizeof(f));
        F1(i,n)scanf("%d",&b[i]);
        F1(i,n)a[i] = b[n-i+1];
        F1(i,n)
        {
            *lower_bound(f+1,f+1+n,a[i]) = a[i];
        }
        printf("%d\n",lower_bound(f+1,f+1+n,f[0])-f-1);
    }
    return 0;
}

