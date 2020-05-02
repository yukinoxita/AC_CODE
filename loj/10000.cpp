#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int ans;
int pre;
struct point {int l,r;}a[1100];
bool cmp(const point &a,const point &b)
{
    if(a.r == b.r) return a.l<b.l;
    return a.r<b.r;
}
int main()
{
    register int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d%d",&a[i].l,&a[i].r);
    sort(a+1,a+1+n,cmp);
    //for(i=1;i<=n;i++)printf("%d %d\n",a[i].l,a[i].r);
    pre = a[1].r;
    for(i=2;i<=n;i++)
    {
        if(pre <= a[i].l){ans++;pre = a[i].r;}
    }
    printf("%d\n",ans+1);
    return 0;
}