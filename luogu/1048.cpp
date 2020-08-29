/*
Author  : yukki
Time    : 2020.9.1
OJ      :
Pid     :
*/
#include <cstdio>

int n,m;
int f[1050];
int w[100];
int v[100];
int max(int x,int y){return x>y?x:y;}
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    scanf("%d",&n);
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",w+i,v+i);
    }
    for(i=1;i<=m;i++)
    {
        for(j=n;j>=0;j--)
        {
            if(j >= w[i])f[j] = max(f[j-w[i]] + v[i],f[j]);
        }
    }
    printf("%d\n",f[n]);
	return 0;
}

