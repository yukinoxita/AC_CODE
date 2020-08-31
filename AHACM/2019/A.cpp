#include <cstdio>
#include <cmath>
int n,m;
double keisan(){return sqrt((n-100)*(n-100)+(m-10)*(m-10));}
int main()
{
    scanf("%d%d",&n,&m);
    double len = keisan();
    if(len <= 10)printf("0.000");
    else
        printf("%.3f",len-10.0);
    return 0;
}
