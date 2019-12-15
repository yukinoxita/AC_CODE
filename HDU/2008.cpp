#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int main()
{
    int i;
   // freopen("2.in","r",stdin);
    while(1)
    {
        scanf("%d",&n);
        if(n == 0)break;
        int fu = 0;
        int zero = 0;
        int zh = 0;
        while(n--)
        {
            double a;
            scanf("%lf",&a);
            if(a>0)zh++;
            else if(a<0)fu++;
            else zero++;
        }
        printf("%d %d %d\n",fu,zero,zh);
    }
    return 0;
}