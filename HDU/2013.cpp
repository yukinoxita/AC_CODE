#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int ans = 0;
int main()
{
    int i,j;
   // freopen("2.in","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        ans = 1;
        for(i=1;i<n;i++)
            ans = (ans + 1) * 2;
        printf("%d\n",ans);
    }
    return 0;
}