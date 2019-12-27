#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
bool vis[110];
int a[110];
int n,m;
/*
{A}-{B}就是属于A且不属于B的部分
思路:
    1)先把A记录到一个数组，然后把b记录到一个bool数组
    2)遍历A数组，计算出有多少数字不在符合要求。
    3)再次遍历，输出数字。
    4)这样写主要是因为格式问题 --> 又读了一遍题目发现不要这么麻烦，step2省略

*/
int main()
{
    int i,j;
    freopen("2.in","r",stdin);
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(n == 0 && m == 0)break;
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        for(i=1;i<=m;i++)
        {
            int tmp;
            scanf("%d",&tmp);
            vis[tmp] = 1;
        }
        sort(a+1,a+1+n);//从小到大输出需要排序
        bool flag = false;
        for(i=1;i<=n;i++)
            if(!vis[a[i]])
                {printf("%d ",a[i]);flag = 1;}
        if(!flag)printf("NULL");
        printf("\n");
        memset(vis,0,sizeof(vis));
        memset(a,0,sizeof(a));
    }
    return 0;
}