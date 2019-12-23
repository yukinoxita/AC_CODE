#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int n;
int a,b;
int cnt,ans;
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
    freopen("2.in","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        a = 1;
        for(j=1;j<=n;j++)
        {
            int tmp;
            scanf("%d",&b);
            if(a>b){tmp = a;a = b;b = tmp;}
            cnt = greatest_common_divis(a,b);
            ans = (b/cnt) * a;
            a = ans;
        }
        printf("%d\n",ans);

    }
    return 0;
}