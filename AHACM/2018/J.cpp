/*
Author  : yukki
Time    : 2020.8.17
OJ      : AHACM
Pid     : 2802
Title   : 2018ACM J
 */
#include <cstdio>
#include <cstring>
#define scnaf scanf
/*
本题对我来说最坑的点
就是mid与l
现在已经找到了属于我的风格的写法
*/
int t;
int n,m;
int a[100005];
int l,r;
int mid;
int minn;
int min(int x,int y){return x<y?x:y;}
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(a,0,sizeof(a));
        r = 0;
        l = 10000005;
        for(i=1;i<=n;i++){scanf("%d",&a[i]);r += a[i];l = min(l,a[i]);}
        int ans = 0;
        int cnt = 0;
        while(l<r)//这里如果写l<=r的话那么r=mid-1
        {
            mid = (l+r)>>1;
            ans = 0;
            cnt = 0;
            for(i=1;i<=n;i++)
            {
                if(ans + a[i] <= mid)ans += a[i];
                else
                {
                    ans = a[i];
                    cnt++;
                }
            }
            cnt++;
            /*
                很显然如果cnt <= m的话mid的值
                有可能就是答案，所以令r = mid
            */
            if(cnt <= m )r = mid;
            else l = mid+1;
        }
        /*
            跳出while的时候l就是最优解
        */
        ans = cnt = 0;
        minn = 999999999;
        for(i=1;i<=n;i++)
        {
            if(ans + a[i] <= l)ans += a[i];
            else
            {
                minn = min(minn,ans);
                ans = a[i];
            }
        }
        minn = min(minn,ans);
        printf("%d\n",minn);
        //printf("l = %d\n",l);
        //printf("minn = %d\n",minn);
        //printf("mid  = %d\n",mid);
    }
	return 0;
}

