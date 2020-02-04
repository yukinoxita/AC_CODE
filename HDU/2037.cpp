#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
struct time
{
    int sta,end;
}a[120];
int n;
/*
算法：贪心
思路：根据结束时间排序，找到下一个能接续的时间
*/
bool cmp(const time &a,const time &b){return a.end < b.end;}
void tanxin()
{
    int i,j;
    int cnt = 1;
    int sit = 1;//从第一个开始
    for(i=2;i<=n;i++)
    {
        if(a[sit].end <= a[i].sta)
        {
            cnt++;
            sit = i;
            continue;
        }
    }
    printf("%d\n",cnt);
}
int main()
{
    int i;
    freopen("1.in","r",stdin);
    while(1)
    {
        scanf("%d",&n);
        if(n == 0)break;
        for(i=1;i<=n;i++)scanf("%d%d",&a[i].sta,&a[i].end);
        sort(a+1,a+1+n,cmp);
        tanxin();
    }
    //for(i=1;i<=n;i++)printf("%d %d\n",a[i].sta,a[i].end);
    return 0;
}
