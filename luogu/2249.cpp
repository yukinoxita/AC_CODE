/*
Author  : yukki
Time    : 2020.6.26
OJ      : luogu
Pid     : 2249
 */
#include <cstdio>

int n,m;
int a[1000010];
int bin_search(int key)
{
    int l=1,r=n;
    int mid;
    while(l<r)
    {
        mid = (l+r)>>1;
        if(a[mid] < key)l=mid+1;
        else
            r=mid;
    }
    if(a[l] == key)return l;
    else return -1;
}
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<=m;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        printf("%d ",bin_search(tmp));
    }
	return 0;
}

