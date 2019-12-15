#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int a,b;
int n2(int n){return n*n;}
int n3(int n){return n*n*n;}
int main()
{
    int i;
   // freopen("2.in","r",stdin);
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        int ans1 = 0;
        int ans2 = 0;
        if(a>b)
        {
            int tmp;
            tmp = a;
            a = b;
            b = tmp;
        }
        if(a%2==1)
        {
            for(i=a;i<=b;i+=2)ans1+=n3(i);
            for(i=a+1;i<=b;i+=2)ans2+=n2(i);
            printf("%d %d\n",ans2,ans1);
            continue;
        }
        else
        {
            for(i=a;i<=b;i+=2)ans2+=n2(i);
            for(i=a+1;i<=b;i+=2)ans1+=n3(i);
            printf("%d %d\n",ans2,ans1);
            continue;
        }
    }
    return 0;
}