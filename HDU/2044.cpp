#include <cstdio>
long long int n;
int a,b;
long long int ans[50];
int sit = 4;
/*
算法:递归
思路：任何形式都能转化成 1 -> n
*/
int main()
{
    int i;
    freopen("1.in", "r", stdin);
    scanf("%lld", &n);
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 3;
    for(i=4;i<=50;i++)ans[i] = ans[i-1] + ans[i-2];
    while (n--)
    {
        scanf("%d%d",&a,&b);
        printf("%lld\n",ans[b-a]);
    }
    return 0;
}
