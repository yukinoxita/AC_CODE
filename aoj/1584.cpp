/*
Author  : yukki
Time    : 2020.9.1
OJ      : aoj
Pid     : 1584
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#define  F1(i,n) for(i=1;i<=n;i++)
#define  F0(i,n) for(i=0;i<=n;i++)
#define _F1(i,n) for(i=n;i>=1;i--)
#define _F0(i,n) for(i=n;i>=0;i--)
using namespace std;
int n,m;
char map[60][60];
int ans;
int max(int x,int y){return x>y?x:y;}
int ue(int x,int y)
{
    int i;
    int cnt = 0;
    for(i=x-1;i>=0;i--)
    {
        if(map[i][y] == 'G')cnt++;
        if(map[i][y] == '#')break;
    }
    return cnt;
}
int shita(int x,int y)
{
    int i;
    int cnt = 0;
    for(i=x+1;i<=n;i++)
    {
        if(map[i][y] == 'G')cnt++;
        if(map[i][y] == '#')break;
    }
    return cnt;
}
int hidari(int x,int y)
{
    int i;
    int cnt = 0;
    for(i=y-1;i>=0;i--)
    {
        if(map[x][i] == 'G')cnt++;
        if(map[x][i] == '#')break;
    }
    return cnt;
}
int migi(int x,int y)
{
    int i;
    int cnt = 0;
    for(i=y+1;i<=m;i++)
    {
        if(map[x][i] == 'G')cnt++;
        if(map[x][i] == '#')break;
    }
    return cnt;
}
void print()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            printf("%c",map[i][j]);
        printf("\n");
    }
    
}
int main()
{
    register int i,j;
    freopen("in","r",stdin);
    while(cin>>n>>m)
    {
        ans = 0;
        memset(map,0,sizeof(map));
        F0(i,n-1)cin>>map[i];
        //print();
        F0(i,n-1)
        {
            F0(j,m-1)
            {
                if(map[i][j] == '.')
                {
                    int cnt = 0;
                    cnt += ue(i,j);
                    cnt += shita(i,j);
                    cnt += migi(i,j);
                    cnt += hidari(i,j);
                    ans = max(ans,cnt);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

