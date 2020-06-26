/*
Author  : yukki
Time    : 2020.6.26
OJ      : luogu
Pid     : 1824
 */
#include <cstdio>
#include <algorithm> 
using namespace std;
int n,c;
int a[100010];
/*
 和noi中眺石头那题类似
 
 */
void bin_search()
{
    int l = 1;
    int r = a[n]+1;
    int mid;
    int i;
    while(l<r)
    {
        mid = (l+r)>>1;
        int pre = a[1];
        int cnt=0;
        for(i=2;i<=n;i++)
        {
            if(a[i]-pre < mid)cnt++;
            else
                pre = a[i];
        }
        if(n-cnt < c)r = mid;//这里mid+1就不对
        else l = mid+1;
    }
    printf("%d\n",l-1);
}
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    scanf("%d%d",&n,&c);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    bin_search();
	return 0;
}

