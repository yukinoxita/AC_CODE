#include <cstdio>
#include <cmath>
int w,n,m;
int keisan(int num,int cnm)
{
    if(num % 2 == 0)return cnm % w;
    return w - cnm % w - 1;
}
int main()
{
    int i,j;
    scanf("%d%d%d",&w,&n,&m);
    n -= 1;
    m -= 1;
    int nx = n / w;
    int ny = keisan(nx,n);
    int mx = m / w;
    int my = keisan(mx,m);
    //printf("nx = %d ny = %d mx = %d my = %d\n",nx,ny,mx,my);
    printf("%d",abs(nx+ny-mx-my));
    return 0;
}