/*
 *title : 和为给定数
 * */
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
long long int m;
int a[100001];
bool check(int sit)
{
    int l = sit+1;
    int r = n;
    int mid;
    while(l != r)
    {
        mid = (l+r)>>1;
        if(a[sit] + a[mid] == m)return true;
        if(a[sit] + a[mid] > m)
            r = mid; 
        else
            l = mid + 1;
    }
    return(a[sit] + a[l] == m);
}
int main()
{
    register int i;
    freopen("1.in","r",stdin);
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    scanf("%lld",&m);
    sort(a+1,a+n+1);
    if(a[1]+a[2]>m || a[n]+a[n-1]<m){printf("No");return 0;}
    for(i=1;;i++)
    {
        if(a[i]+a[i+1] > m){printf("No");break;}
        if(a[i]+a[i+1] == m){printf("%d %d",a[i],m-a[i]);break;}
        if(check(i)){printf("%d %d",a[i],m-a[i]);break;}
    }
    return 0;
}
