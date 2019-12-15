#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int main()
{
    int i;
    //freopen("2.in","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        int ans = 1;
        while(n--)
        {
            int a;
            scanf("%d",&a);
            if(a%2==1)ans*=a;
        }
        printf("%d\n",ans);
    }
    return 0;
}