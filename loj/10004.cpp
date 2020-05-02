#include <cstdio>
#include <algorithm>
using namespace std;
int m,n;
bool vis[600];
bool flag;
/*
思想：
首先按照价格大小排序
只要我们在前a[i].deadtime能将其完成即可。

*/
struct point 
{
    int deadtime;
    int kane;
}a[600];
bool cmp(const point &a,const point &b)
{
    if(a.kane == b.kane)return a.deadtime < b.deadtime;
    return a.kane > b.kane;
}
int main()
{
    register int i,j;
    //freopen("1.in","r",stdin);
    scanf("%d%d",&m,&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i].deadtime);
    for(i=1;i<=n;i++)scanf("%d",&a[i].kane);
    sort(a+1,a+1+n,cmp);
    for(i=1;i<=n;i++)
    {
        flag = 0;
        for(j=a[i].deadtime;j>=1;j--)
        {
            if(!vis[j])
            {
                vis[j] = 1;
                flag = 1;
                break;
            }
        }
        if(!flag)m -= a[i].kane;
    }
    printf("%d",m);
    return 0;
}
