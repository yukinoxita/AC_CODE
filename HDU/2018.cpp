#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int cow[4];//a[0]:可以生产的奶牛-------a[1]:一年后能生产的奶牛-------a[2]:以此类推--a[3]:同理
int vis[60];//储存算过的答案
int all(int num)
{
    int i;
    int ans = 0;
    for(i=0;i<=3;i++)ans += cow[i];
    vis[num] = ans;
    return ans;
}
/*
其实这题完全可以直接算出1-54年的答案。
但是我懒，而且可能会浪费时间和空间
(在数据足够大的时候)
*/
int main()
{
    int i,j;
    freopen("2.in","r",stdin);
    freopen("2.out","w",stdout);
    while(1)
    {
        scanf("%d",&n);
        if(n == 0)break;
        cow[0] = 1;
        if(vis[n]){printf("%d\n",vis[n]);continue;}//储存数据，防止重复计算,提高效率
        if(n == 1){printf("1\n");continue;}
        for(i=1;i<n;i++)
        {
            cow[0] += cow[1];
            cow[1] =  cow[2];
            cow[2] =  cow[3];
            cow[3] =  cow[0];
            int tmp =all(i+1);
            if(i == n-1)printf("%d\n",tmp);
        }
        memset(cow,0,sizeof(cow));
    }
    //for(i=1;i<=10;i++)printf("%d ",vis[i]);
    return 0;
}