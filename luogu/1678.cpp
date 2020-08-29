/*
Author  : yukki
Time    : 2020.6.1
OJ      : luogu
Pid     : 1678
 */
#include <cstdio>
#include <algorithm>
#define scnaf scanf
using namespace std;
/*
    找到第一个>=tmp的数字后
    左边那个一定是<=tmp的数字
*/
int n,m;
int a[100100];
long long int ans = 0;
int bin_search(int key)
{
    int l,r;
    l = 1;
    r = n+1;
    int mid;
    while(l<r)
    {
        mid = (l+r)>>1;
        if(a[mid] > key)
            r = mid;
        else
            l = mid+1;
    }
    return l-1;
}
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    a[n+1] = 99999999;
    sort(a+1,a+1+n);
    for(i=1;i<=m;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        int fsit;
        int esit;
        if(tmp <= a[1]){ans += (a[1]-tmp);continue;}
        if(tmp >= a[n]){ans += (tmp-a[n]);continue;}

        int sit  = bin_search(tmp);
        fsit = a[sit];
        esit = a[sit+1];
        /*
        printf("tmp  = %d\n",tmp);
        printf("fsit = %d\n",fsit);
        printf("esit = %d\n",esit);
        printf("\n");
        */
        ans += min(tmp-fsit,esit-tmp);
    }
    printf("%lld\n",ans);
	return 0;
}

