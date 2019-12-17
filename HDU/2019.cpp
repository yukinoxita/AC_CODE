#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int main()
{
    int i,j;
    freopen("2.in","r",stdin);
    while(1)
    {
        scanf("%d%d",&n,&m);
        bool flag = 0;
        if(n == 0 && m == 0)break;
        for(i=1;i<=n;i++)
        {
            int tmp;
            scanf("%d",&tmp);
            if(m<tmp && !flag){printf("%d %d",m,tmp);flag = 1;}
            else printf("%d",tmp);
            if(i != n)printf(" ");
        }
        if(!flag){printf(" %d",m);}
        printf("\n");
    }
    return 0;
}