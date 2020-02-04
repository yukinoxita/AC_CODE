#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
int map[5][5];
bool vis[10];
int ans;
int find_r(int x,int y)
{
    if(y != 4)return x;
    return x+1;
}
int find_c(int x,int y)
{
    if(y == 4)return 1;
    return y+1;
}
bool check(int x,int y)
{
    int check_num = map[x][y];
    if(abs(check_num - map[x-1][y]) <=1 || abs(check_num - map[x][y-1]) <= 1 || abs(check_num - map[x-1][y-1]) <=1 || abs(check_num - map[x-1][y+1]) <=1)return false;
    return true;
}
void print()
{
    int i,j;
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=4;j++)printf("%d ",map[i][j]);
        printf("\n");
    }
    printf("------------------------\n");
}
void dfs(int row,int col,int num)
{
    int i,j;
    if(!check(row,col))return;
    if(row == 3 && col == 3){ans++;/*print()*/;return;}
    int next_r = find_r(row,col);
    int next_c = find_c(row,col);
    for(i=0;i<=9;i++)
        if(!vis[i])
        {
            map[next_r][next_c] = i;
            vis[i] = 1;
            dfs(next_r,next_c,i);
            vis[i] = 0;
        }

}
int main()
{
    map[1][1] = 100;
    map[3][4] = 100;
    int i,j;
    for(i=0;i<5;i++)map[i][0] = 100,map[0][i] = 100;
    /*
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        printf("%d ",map[i][j]);
        printf("\n");
    }*/
    for(i=0;i<=9;i++){map[1][2] = i;vis[i] = 1;dfs(1,2,i);vis[i] = 0;}
    printf("%d",ans);
    return 0;
}