#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int triangle[40][40];
int n;
int maxx = 2;//方案二使用
/*
我准备写两种：
    一种是先算完30层的。
    另一种时求到哪里算到哪里的
    这两中的区别就在于add，
    方法一直接从3到30，而
    方案二是从第二大更新到最大层数.
*/
void print()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++){printf("%d",triangle[i][j]);if(j != i)printf(" ");}
        printf("\n");
    }
    printf("\n");
}
void add(int num)
{
    int i,j;
    for(i=maxx;i<=num;i++)
        for(j=1;j<=i;j++)
            triangle[i][j]=triangle[i-1][j-1]+triangle[i-1][j];
    maxx = num;
}
int main()
{
    int i,j;
    freopen("2.in","r",stdin);
    //初始化
    triangle[1][1]=1;
    triangle[2][1]=1;
    triangle[2][2]=1;
    while(scanf("%d",&n)!=EOF)
    {
        if(n > maxx)add(n);
        print();
    }
    return 0;
}