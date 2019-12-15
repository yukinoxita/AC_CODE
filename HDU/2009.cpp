#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int b;
double a;
int main()
{
    int i;
    //freopen("2.in","r",stdin);
    while(scanf("%lf%d",&a,&b)!=EOF)
    {
        double ans = 0.0;
        ans = a;
        while(--b)
        {
            ans += sqrt(a);
            a = sqrt(a);
        }
        printf("%.2f\n",ans);
    }
    return 0;
}