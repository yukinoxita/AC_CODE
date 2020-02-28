#include <cstdio>
long long int ans[52];
int n;
int main()
{
    int i;
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 3;
    for(i=4;i<=50;i++)
        ans[i] = ans[i-1] + ans[i-2];
    while(scanf("%d",&n) != EOF)
        printf("%lld\n",ans[n]);
    return 0;
}
