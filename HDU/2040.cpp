#include <cstdio>
#include <cmath>
int n,a,b;
bool check()
{
    int i;
    int cnt = 1;
    for(i=2;i<=sqrt(a);i++)
        if(a % i == 0){cnt += i;cnt += (a/i);}
    if(cnt != b)return false;
    cnt = 1;
    for(i=2;i<=sqrt(b);i++)
        if(b % i == 0){cnt += i;cnt += (b/i);}
    if(cnt != a)return false;
    return true; 
}
int main()
{
    freopen("1.in","r",stdin);
    scanf("%d",&n);
    while (n--)
    {
        scanf("%d%d",&a,&b);
        if(check())printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
