/*
Author  : yukki
Time    : 2020.8.29
OJ      : luogu
Pid     : 1439
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m;
int a[100010];
int f[100010];
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    memset(f,0x3f,sizeof(f));
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        a[tmp] = i;
    }
    for(i=1;i<=n;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        int x = a[tmp];
        *lower_bound(f+1,f+1+n,x) = x;
    }
    printf("%d\n",lower_bound(f+1,f+1+n,f[0])-f-1);

	return 0;
}

