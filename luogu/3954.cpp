/*
Author  : yukki
Time    : 2020.6.1
OJ      : luogu
Pid     : 3954
 */
#include <cstdio>

#define scnaf scanf
int a,b,c;
int ans;
int main()
{
    register int i,j;
    scanf("%d%d%d",&a,&b,&c);
    ans = a*0.2+b*0.3+c*0.5;
    printf("%d\n",ans);
	return 0;
}

