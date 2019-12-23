#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int n;
int a,b;
int greatest_common_divis(int a,int b)
{
    int tmp;
    while(b%a > 0)
    {
        tmp = b;
        b = a;    
        a = tmp % a;
    }    
    return a;
}
int main()
{
    int i,j;
    //freopen("2.in","r",stdin);
    scanf("%d%d",&a,&b);
    int tmp;
    if(a>b){tmp = a;a = b;b = tmp;}
    int ans = greatest_common_divis(a,b);
    int lowest_common_multiple = (b/ans) * a;
    printf("%d\n",lowest_common_multiple);
    printf("%d\n",ans);
    return 0;
}