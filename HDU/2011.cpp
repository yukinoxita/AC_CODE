#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int check(int num)
{
    if(num%2==0)return -1;
    return 1;
}
double ans()
{
    double cnt = 0;
    register double i;
    for (i=1;i<=n;i++)cnt += check(i)*(1/i);
    return cnt;
}
int main()
{
    int i;
   // freopen("2.in","r",stdin);
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&n);
        printf("%.2lf\n",ans());
    }
    return 0;
}