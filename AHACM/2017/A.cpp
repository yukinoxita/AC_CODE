/*
Author  : yukki
Time    : 2020.9.6
OJ      : AHACM
Pid     : A
*/
#include <cstdio>
#include <cmath>
#define  F1(i,n) for(i=1;i<=n;i++)
#define  F0(i,n) for(i=0;i<=n;i++)
#define _F1(i,n) for(i=n;i>=1;i--)
#define _F0(i,n) for(i=n;i>=0;i--)
double money;
int n;
int t;
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    scanf("%d",&t);
    int cnt = 0;
    while(t--)
    {
        cnt++;
        scanf("%d%lf",&n,&money);
        double all = 0.0;
        F1(i,n)
        {
            double tmp;
            int num;
            int tt;
            scanf("%lf%d",&tmp,&num);
            all += tmp*num*10;
        }
        all = ceil(all);
        all /= 10;
        if(all > money){printf("Case %d: -1\n",cnt);continue;}
        printf("Case %d: %.2lf\n",cnt,money-all);
    }

	return 0;
}

