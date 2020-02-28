#include<cstdio>
long long int a,c;
int main()
{
    scanf("%lld",&c);
    while(c--)
    {
        scanf("%d",&a);
        printf("%lld\n",2*a*a-a+1);
    }
    return 0;
}