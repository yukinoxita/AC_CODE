#include <cstdio>
#include <cmath>
//   正数没说是整数
double a, b, c;            
int n;
int main()
{
    scanf("%d", &n);
    while (n--)
    {
        scanf("%lf%lf%lf",&a,&b,&c);
        if ((a + b) > c && fabs(a - b) < c)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
