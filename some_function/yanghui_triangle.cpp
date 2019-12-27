#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
long long int triangle[100][100];
int n;
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
void add(int n)
{
    int i,j;
    for(i=3;i<=n;i++)
        for(j=1;j<=i;j++)
            triangle[i][j]=triangle[i-1][j-1]+triangle[i-1][j];
}
int main()
{
    int i,j;
    freopen("2.in","r",stdin);
    //初始化
    triangle[1][1]=1;
    triangle[2][1]=1;
    triangle[2][2]=1;
    scanf("%d",&n);
    add();
    print();
    return 0;
}