/*
Author  : yukki
Time    : 2020.8.30
OJ      : luogu
Pid     : 2758
*/
#include <cstdio>
#include <cstring>
int n,m;
char a[2020];
char b[2020];
int f[2020][2020];
int min(int x,int y,int z)
{
    if(x > y)x = y;
    if(x > z)x = z;
    return x;
}
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    scanf("%s",a+1);
    scanf("%s",b+1);
    int len1 = strlen(a+1);
    int len2 = strlen(b+1);
    for(i=1;i<=len1;i++)f[i][0] = i;
    for(i=1;i<=len2;i++)f[0][i] = i;
    for(i=1;i<=len1;i++)
    {
        for(j=1;j<=len2;j++)
        {
            if(a[i] == b[j])f[i][j] = min(f[i-1][j-1],f[i-1][j]+1,f[i][j-1]+1);
            else
            {
                f[i][j] = min(f[i-1][j],f[i][j-1],f[i-1][j-1]) + 1;
            }
        }
    }
    printf("%d\n",f[len1][len2]);
	return 0;
}

