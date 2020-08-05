/*
Author  : yukki
Time    : 2020.8.1
OJ      : luogu
Pid     : 1158
*/
#include <cstdio>
#include <algorithm>
using namespace std;

#define scnaf scanf
/*
思路
我们根据所有点到l1，l2的
距离分为被l1拦截的和其他
被l2拦截的我们只需要找到
一个点使得两个和最小即可


*/
int x1,x2,y1,y2;
struct point
{
    int l1,l2;//与l1,l2之间的就
}a[100100];
int n;
int maxx(int x,int y){return x>y?x:y;}
int minn(int x,int y){return x<y?x:y;}
inline bool cmp(const point & q,const point & p){return q.l1<p.l1;}
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[i].l1 = (x-x1)*(x-x1)+(y-y1)*(y-y1);
        a[i].l2 = (x-x2)*(x-x2)+(y-y2)*(y-y2);
    }
    sort(a+1,a+1+n,cmp);
    int ans = a[n].l1;
    int hei = -1;
    //for(i=1;i<=n;i++)printf("%d\n",a[i].l1);
    /*
        这里每次去找i+1的最大值，枚举到一个i使ans最小
    */
    for(i=n-1;i>=1;i--)
    {
        hei = maxx(hei,a[i+1].l2);
        ans = minn(ans,a[i].l1+hei);
    }
    printf("%d\n",ans);
	return 0;
}

