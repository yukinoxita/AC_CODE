#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
struct num
{
    int pre_sort;//排序使用
    int origin_num;//输出使用
}a[110];
bool cmp(const num & a, const num & b){return a.pre_sort > b.pre_sort;}
int main()
{
    int i,j;
    freopen("2.in","r",stdin);
    while(1)
    {
        scanf("%d",&n);
        if(n == 0)break;
        for(i=1;i<=n;i++){scanf("%d",&a[i].origin_num);a[i].pre_sort = abs(a[i].origin_num);}
        sort(a+1,a+1+n,cmp);
        for(i=1;i<=n;i++){printf("%d",a[i].origin_num);if(i != n)printf(" ");}
        printf("\n");
    }
    return 0;
}