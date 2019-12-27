#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int ans;
int n,m;
/*
(a%n) * (b%n) == (a*b) % n
*/
int main()
{
    int i,j;
    freopen("2.in","r",stdin);
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(n == 0 && m == 0)break;
        ans = 1;
        for(i=1;i<=m;i++)
            ans = ((ans%1000) * n) % 1000;
        printf("%d\n",ans);
    }
    return 0;
}