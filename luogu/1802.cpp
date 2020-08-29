/*
Author  : yukki
Time    : 2020.8.20
OJ      : luogu
Pid     : 1802
*/
#include <cstdio>

int n,m;
int l[1050];
int w[1050];
int v[1050];
long long int f[1050];
int max(int x,int y){return x>y?x:y;}
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    scanf("%d",&n);
    scanf("%d",&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d",&l[i],&w[i],&v[i]);
    }
    /*
    非状压
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(j < v[i])
                f[i][j] = f[i-1][j] + l[i];
            else 
                f[i][j] = max(f[i-1][j-v[i]]+w[i],f[i-1][j]+l[i]);
        }
    }
    printf("%lld\n",f[n][m]*5);
    */
    for(i=1;i<=n;i++)
    {
        for(j=m;j>=0;j--)
        {
            if(j < v[i])
                f[j] = f[j] + l[i];
            else 
                f[j] = max(f[j-v[i]]+w[i],f[j]+l[i]);
        }
    }
    printf("%lld\n",f[m]*5);
	return 0;
}

