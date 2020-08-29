/*
Author  : yukki
Time    : 2020.8.18
OJ      : luogu
Pid     : 1181
 */
#include <cstdio>

#define scnaf scanf
int n,m;
int a[101000];
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    int ans = 0;
    int cnt = 0;
    for(i=1;i<=n;i++)
    {
        if(ans + a[i] <= m)ans += a[i];
        else
        {
            ans = a[i];
            cnt++;
        }
    }
    printf("%d\n",cnt+1);
	return 0;
}

