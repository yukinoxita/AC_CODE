/*
Author  : yukki
Time    : 2020.9.1
OJ      : luogu
Pid     : 1077
*/
#include <cstdio>
#define  F1(i,n) for(i=1;i<=n;i++)
#define  F0(i,n) for(i=0;i<=n;i++)
#define _F1(i,n) for(i=n;i>=1;i--)
#define _F0(i,n) for(i=n;i>=0;i--)
/*
f[i][j]表示前i种花一共摆j个时的解
f[i][j] = sum{f[i-1][j-k]}(0 <= k <= min(a[i],j))
可优化,未来的自己不妨再想一想
*/
int n,m;
int a[120];
int f[120][120];
int min(int x,int y){return x<y?x:y;}
int main()
{
    register int i,j,k;
    freopen("in","r",stdin);
    scanf("%d",&n);
    scanf("%d",&m);
    F1(i,n)scanf("%d",a+i);
    f[0][0] = 1;
    F1(i,n)
    {
        F0(j,m)
        {
            //for(k=0;k<=min(j,a[i]);k++)
            F0(k,min(j,a[i]))
            {
                f[i][j] = (f[i][j] + f[i-1][j-k]) % 1000007;
            }
        }
    }
    printf("%d\n",f[n][m]);
	return 0;
}

