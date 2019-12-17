#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
double point[101];
double ans = 0;
int main()
{
    int i,j;
    freopen("2.in","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        ans = 0.0;
        for(i=1;i<=n;i++)scanf("%lf",&point[i]);
        sort(point+1,point+n+1);
        for(i=2;i<n;i++)ans += point[i];
        printf("%.2lf\n",ans/(n-2));
        memset(point,0,sizeof(point));
    }
    return 0;
}