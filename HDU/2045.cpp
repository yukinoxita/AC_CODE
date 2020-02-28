#include <cstdio>
long long int ans[52];
int n;
/*
1 : 3       
2 : 6       
3 : 6
4 : 18
5 : 30
6 : 66
7 : 126
*/
int main()
{
    int i;
    ans[1] = 3;
    ans[2] = 6;
    ans[3] = 6;
    ans[4] = 18;//18
    for(i=5;i<=50;i++)
        ans[i] = ans[i-1] + 2 * ans[i-2];
    while(scanf("%d",&n) != EOF)
        printf("%lld\n",ans[n]);
    //for(i=1;i<=50;i++)printf("%d : %lld\n",i,ans[i]);
    return 0;
}