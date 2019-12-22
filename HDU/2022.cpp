#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
/*
算法：排序
思路:
按分数的绝对值进行排序
分数相同按题目条件进行
排序得出结果即可。我这
里使用结构体进行了数据
存储
*/
struct MM
{
    int line,row;
    int point;
    int pre_point;
}a[5000000];
bool cmp(const MM & a, const MM & b)
{
    if(a.pre_point > b.pre_point)return true;
    else if(a.pre_point == b.pre_point)
    {
        if(a.line < b.line)return true;
        else if(a.line == b.line)
        {
            if(a.row < b.row)return true;
            else return false;
        }
        else return false;
    }
    else return false;
}
int main()
{
    int i,j;
    freopen("2.in","r",stdin);
    int ans = 0;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                int tmp = (i-1)*m+j;
                scanf("%d",&a[tmp].point);
                a[tmp].line = i;
                a[tmp].row = j;
                a[tmp].pre_point = abs(a[tmp].point);
            }
        }
        sort(a+1,a+1+m*n,cmp);
        printf("%d %d %d\n",a[1].line,a[1].row,a[1].point);
        //for(i=1;i<=n*m;i++)printf("line = %d roe = %d point = %d\n",a[i].line,a[i].row,a[i].point);
    }
    return 0;
}