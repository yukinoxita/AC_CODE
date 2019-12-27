#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int a[3],b[3];
int n;
/*
注意小时有多少就是多少
*/
int main()
{
    int i,j;
    freopen("2.in","r",stdin);
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d%d%d%d%d",&a[0],&a[1],&a[2],&b[0],&b[1],&b[2]);
        for(i=0;i<3;i++)a[i] += b[i];
        for(i=2;i>=1;i--)
        {
            if(a[i]>=60){a[i-1]++;a[i] -= 60;}
        }
        printf("%d %d %d\n",a[0],a[1],a[2]);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
    }
    return 0;
}