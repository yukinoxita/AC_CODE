#include <cstdio>
int num[100010];
int n,k;
int ans;
int main()
{
    int i,j;
    freopen("1.in","r",stdin);
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        num[i] += tmp;
        num[i+1] += num[i];
    }
    for(i=1;i<=n;i++)
    {
        for(j=0;j<i;j++)
        {
            int ch = num[i] - num[j];
            if(ch % k == 0)ans++;
        }
    }
    printf("%d",ans);
    return 0;
}