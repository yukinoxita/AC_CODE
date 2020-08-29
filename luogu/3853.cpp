/*
Author  : yukki
Time    : 2020.6.1
OJ      : luogu
Pid     : 3853
 */
#include <cstdio>

#define scnaf scanf
int len,n,k;
int a[100010];
int l,r;
bool check(int llen)
{
    register int i;
    int cnt = 0;//记录当前距离需要添加多少个路障
    /*
        假设当前为0 101两个路障，当前llen为51
        需要添加的路障数为(101-0)/51 = 1
        如果llen为50
        需要添加的路障数为(101-0)/50 = 2
        只要需要添加的路障大于k那么mid就太小了
            mid = l+1
    
    */
    for(i=1;i<n;i++)
    {
        int tmp = a[i+1] - a[i];
        if(tmp >= llen)
        {
            cnt += (tmp / llen);
            if(tmp % llen == 0)
                cnt--;
        }
    }
    if(cnt <= k)return 1;
    return 0;
}
int main()
{
    register int i;
    freopen("in","r",stdin);
    scanf("%d%d%d",&len,&n,&k);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    l = 1;
    r = len;
    int mid;
    while(l<r)
    {
        mid = (l+r)>>1;
        if(check(mid))
            r = mid;
        else
            l = mid+1;
    }
    printf("%d\n",l);
	return 0;
}

