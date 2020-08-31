/*
Author  : yukki
Time    : 2020.9.1
OJ      : luogu
Pid     : 1233
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define  F1(i,n) for(i=1;i<=n;i++)
#define  F0(i,n) for(i=0;i<=n;i++)
#define _F1(i,n) for(i=n;i>=1;i--)
#define _F0(i,n) for(i=n;i>=0;i--)
using namespace std;
/*
这题对一个属性排序后
可转换成对另一个属性
求LIS
*/
int n,m;
struct gun
{
    int x;
    int y;
}a[5005];
int b[5005];
bool cmp(const gun & a,const gun & b){return a.x>b.x;}
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    memset(b,0x3f,sizeof(b));
    scanf("%d",&n);
    int sit = 1;
    F1(i,n<<1)
    {
        int tmp;
        scanf("%d",&tmp);
        if(i%2==1)a[sit].x = tmp;
        else a[sit++].y = tmp;
    }
    //F1(i,n)printf("x = %d,y = %d\n",a[i].x,a[i].y);
    sort(a+1,a+1+n,cmp);
    //F1(i,n)printf("x = %d,y = %d\n",a[i].x,a[i].y);
    F1(i,n)
    {
        *lower_bound(b+1,b+1+n,a[i].y) = a[i].y;
    }
    printf("%d\n",lower_bound(b+1,b+1+n,b[0])-b-1);
	return 0;
}

