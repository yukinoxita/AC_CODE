#include <cstdio>
long long int ans[52];
int n;
int main()
{
    int i;
    ans[1] = 3;
    ans[2] = 8;
    ans[3] = 22;
    for(i=4;i<=40;i++)
        ans[i] = 2 * ans[i-1] + 2 * ans[i-2];
    while(scanf("%d",&n) != EOF)
        printf("%lld\n",ans[n]);
 //   for(i=1;i<40;i++)printf("%lld\n",ans[i]);
    return 0;
}
