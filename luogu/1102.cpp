/*
Author  : yukki
Time    : 2020.8.18
OJ      : luogu
Pid     : 1102
 */
#include <cstdio>
#include <algorithm>
using namespace std;

#define scnaf scanf
int n,m;
int a[200040];
long long int cnt = 0;
int minn;
int bin_search(int key)
{
    int l,r;
    l = 1;
    r = minn;
    int mid;
    while(l<r)
    {
        mid = (l+r)>>1;
        if(a[mid] < key)
            l = mid+1;
        else
            r = mid;
    }
    return l;
}
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for(i=n;i>=1;i--)
    {
        if(a[i] - m <= 0)break;
        minn = i;
        int fsit,esit;
        /*我们要去寻找第一个大于x的数的下标
        还有第一个大于x-1的下标
        x = a[i] - m
        eg:
            9 1
            1 1 1 3 3 3 3 3 4
        我们如何确定一共有多少个3?
        fsit = 4
        esit = 9
        cnt += esit-fsit
        如何确定有几个2呢？
        fsit = 4
        esit = 4
        cnt += esit-fsit;
        */
        fsit = bin_search(a[i]-m);
        esit = bin_search(a[i]-m+1);
        cnt += (esit-fsit);
    }
    printf("%lld\n",cnt);
	return 0;
}

