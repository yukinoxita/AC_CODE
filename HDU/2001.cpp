#include <cstdio>
#include <cmath>
double a,b,c,d;
double ans;
int main()
{
    int i;
    while(scanf("%lf%lf%lf%lf",&a,&b,&c,&d)!=EOF)
    {
        ans = sqrt((a-c)*(a-c) + (b-d)*(b-d));
        printf("%.2lf\n",ans);
    }
    return 0;
}