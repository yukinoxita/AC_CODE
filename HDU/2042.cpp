#include <cstdio>
#include <cmath>
int n;
int a[32];
int main()
{
    int i;
    freopen("1.in","r",stdin);
    scanf("%d",&n);
    while (n--)
    {
        int tmp;
        scanf("%d",&tmp);
        int cnt = 3;
        if(a[tmp] != 0)printf("%d\n",a[tmp]);
        else
        {
            for(i=1;i<=tmp;i++)
                cnt = (cnt - 1) * 2;
            printf("%d\n",cnt);
            a[tmp] = cnt;
        }
        
    }
    return 0;
}
