/*
Author  : yukki
Time    : 2020.6.26
OJ      : luogu
Pid     : 1182
 */
#include <cstdio>

int n,m;
int a[100020];
int all;
int ans;
int maxx;
int check(int num)
{
    int i;
    int cnt=0;
    int v=0;
    for(i=1;i<=n;i++)
    {
        if(v+a[i] <= num)v += a[i];
        else
        {
            v = a[i];
            cnt++;
        }
    }
    return cnt+1;
}
void bin_search()
{
    int l,r;
    l = maxx;
    r = all+1;
    int mid;
    while(l<r)
    {
        mid = (l+r)>>1;
        // 样例第一次9但是能分三个组，但是还有可能存在更小的数字，所以r要变小。
        // r右边的数字都不能要
        // check(mid)代表在每组最大mid时能够分多少组
        if(check(mid) <= m)
            r = mid;
        else
            l = mid+1;
    }
    printf("%d\n",l);
}
int main()
{
    register int i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){scanf("%d",&a[i]);all+=a[i];maxx=maxx>a[i]?maxx:a[i];}
    /*
     这里maxx的原因很简单，你不可能用一个装不下的盒子来装他。
     l=1的话那要是有大于1的数字怎么办？？？
     
     */
    maxx=1;
    bin_search();
	return 0;
}

