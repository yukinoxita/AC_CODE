/*
Author  : yukki
Time    : 2020.8.5
OJ      : luogu
Pid     : 3955
 */
#include <cstdio>
#include <algorithm>
#define scnaf scanf
using namespace std;
int n,q;
int book[1010];
int su[10]={1,10,100,1000,10000,100000,1000000,10000000};
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;i++)scanf("%d",&book[i]);
    sort(book+1,book+1+n);
    for(i=1;i<=q;i++)
    {
        int len,num;
        scanf("%d%d",&len,&num);
        int idx = -1;
        for(j=1;j<=n;j++)
        {
            if(book[j]%su[len] == num){idx = book[j];break;}
        }
        if(idx == -1)printf("-1\n");
        else printf("%d\n",idx);
    }
	return 0;
}

