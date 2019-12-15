#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int b;
bool flag = true;
int a;
bool check(int n)
{
    int a = n/100;
    int b = n%10;
    int c = (n/10)%10;
    if(a*a*a+b*b*b+c*c*c == n)return 1;
    return 0;
}
int main()
{
    int i;
   // freopen("2.in","r",stdin);
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        flag = 1;
        for(i=a;i<=b;i++)if(check(i)){if(flag){printf("%d",i);flag=0;continue;}else printf(" %d",i);}
        if(flag)printf("no");
        printf("\n");
    }
    return 0;
}