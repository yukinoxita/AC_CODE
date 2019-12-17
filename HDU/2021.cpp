#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int vis[500000];//vis[i]表示当工资为i时需要的最少的钞票数
int t[6] = {100,50,10,5,2,1};
/*
算法：贪心
讲解:
本题每个老师的工资单独去算最少多少
张钞票我们就尽可能地用最大地钞票面
额去减他的工资同时记录下来已经算过
的工资数，如果下次再遇到就直接使用
*/
int find_ans(int num)
{
    int i;
    int sit = num;
    int cnt = 0;
    for(i=0;i<=5;i++)
        while(num-t[i]>=0){cnt++;num -= t[i];}
    vis[sit] = cnt;
    return cnt;
}
int main()
{
    int i,j;
    freopen("2.in","r",stdin);
    int ans = 0;
    while(1)
    {
        ans = 0;
        scanf("%d",&n);
        if(n == 0)break;
        for(i=1;i<=n;i++)
        {
            int tmp;
            scanf("%d",&tmp);
            if(vis[tmp])ans += vis[tmp];
            else ans += find_ans(tmp);
        }
        printf("%d\n",ans);
    }
    return 0;
}