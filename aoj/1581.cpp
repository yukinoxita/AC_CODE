/*
Author  : yukki
Time    : 2020.9.12
OJ      : aoj
Pid     : 1581
*/
#include <cstdio>
#include <set>
#include <algorithm>
#include <iostream>
#define  F1(i,n) for(i=1;i<=n;i++)
#define  F0(i,n) for(i=0;i<=n;i++)
#define _F1(i,n) for(i=n;i>=1;i--)
#define _F0(i,n) for(i=n;i>=0;i--)
using namespace std;
int n,m;
set <int> s;
set <int>::iterator it;
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    scanf("%d",&n);
    F1(i,n)
    {
        scanf("%d",&m);
        s.insert(m);
    }
    cout<<s.size()<<endl;
    for(it=s.begin();it!=s.end();it++)
        cout<<*it<<" ";


    return 0;
}

