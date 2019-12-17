#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#define lsit list //替换，可将就算你输入成了lsit也能转回list
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
    while (1)
    {
        scanf("%d",&n);
        if(n == 0)break;
        int min = 2147483647;
        int sit = 0;
        for(i=1;i<=n;i++){scanf("%d",&lsit[i]);if(lsit[i]<min){min = lsit[i];sit = i;}}
        int tmp = lsit[sit];
        list[sit] = lsit[1];
        lsit[1] = tmp;
        for(i=1;i<=n;i++){printf("%d",list[i]);if(i != n)printf(" ");}
        printf("\n");
    }
    return 0;
}