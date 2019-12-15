#include <cstdio>
#include <cmath>
#define PI 3.1415927
double r;
double ans;
int main()
{
    int i;
   // freopen("2.in","r",stdin);
    while(scanf("%lf",&r)!=EOF)
    {
        ans = (r*r*r*PI*4)/3.0;
        printf("%.3lf\n",ans);
    }
    return 0;
}