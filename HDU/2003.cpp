#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
double r;
double ans;
int main()
{
    int i;
 //   freopen("2.in","r",stdin);
    while(scanf("%lf",&r)!=EOF)
    {
        r = abs(r);
        printf("%.2lf\n",r);
    }
    return 0;
}