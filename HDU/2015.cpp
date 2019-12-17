#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#define lsit list
#include <algorithm>
using namespace std;
int n,m;
int list[101];
int main()
{
    int i,j;
    list[0] = 0;
    for(i=1;i<=100;i++)list[i] = lsit[i-1] + 2;
    freopen("2.in","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int sit = 0;
        int point = 0;
        for(i=1;i<=n;i++)
        {
            point += lsit[i];
            ++sit;
            if(sit == m)
            {
                printf("%d",point/m);
                if(i != n)printf(" ");
                sit = 0;
                point = 0;
                continue;
            }
        }
        if(sit != 0)
        {
            printf("%d",point/sit);

        }
        printf("\n");
    }
    return 0;
}