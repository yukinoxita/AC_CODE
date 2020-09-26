/*
Author  : yukki
Time    : 2020.9.6
OJ      : AHACM
Pid     : I
*/
#include <cstdio>
#include <cstring>
#define  F1(i,n) for(i=1;i<=n;i++)
#define  F0(i,n) for(i=0;i<=n;i++)
#define _F1(i,n) for(i=n;i>=1;i--)
#define _F0(i,n) for(i=n;i>=0;i--)
int n,m;
bool map[220][220];
int t;
int ans;
int  max(int x,int y){return x>y?x:y;}
int  min(int x,int y){return x<y?x:y;}
void dfs(int x,int y)
{
    int i,j;
    int p1,len1;
    //确定从本点开始在本行最大长度
    // y+1 是因为x,y一定是1
    for(i=y+1;i<=m+1;i++)
        if(map[x][i] == 0){len1 = i-y;p1 = i-1;break;}
    if(len1 == 1)return;

    //point1(x,p1)
    //point2(p2,y)
    //point3(p3,p1)

    //确定这一行两个点向下各自延伸的长度
    int len2,p2;
    int len3,p3;
    //如果最后循环到最后一个也是1的话也要考虑

    for(i=x+1;i<=n+1;i++)
        if(map[i][y] == 0){len2 = i-x;p2 = i-1;break;}
    if(len2 == 1)return;

    for(i=x+1;i<=n+1;i++)
        if(map[i][p1] == 0){len3 = i-x;p3 = i-1;break;}
    if(len3 == 1)return;

    int forx = min(p2,p3);
    for(i=y+1;i<=p1;i++)
    {
        if(map[forx][i] == 0)return;
    }
    ans = max(len1*min(len2,len3),ans);
}
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%d",&m);
        ans = 0;
        memset(map,0,sizeof(map));
        F1(i,n)
            F1(j,m)
            {
                int tmp;
                scanf("%d",&tmp);
                if(tmp != 0)map[i][j] = 1;
                else map[i][j] = 0;
            }
        F1(i,n)
            F1(j,m)
                if(map[i][j] == 1)dfs(i,j);

        printf("%d\n",ans);
    }
	return 0;
}

